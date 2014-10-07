#include "Matte.hpp"

namespace Raytracer {
  Matte::Matte () :
	  Material(),
	ambient_brdf(new Lambertian()),
	diffuse_brdf(new Lambertian())
	{}


  Matte::Matte (const RGBColor& color) :
    Material(),
	ambient_brdf(new Lambertian()),
	diffuse_brdf(new Lambertian())
	{
    set_cd(color);
  }


  Matte::Matte(const Matte& m) :
    Material(m) {
    if(m.ambient_brdf) {
      ambient_brdf = m.ambient_brdf->clone();
    }
    else {
      ambient_brdf = NULL;
    }

    if(m.diffuse_brdf) {
      diffuse_brdf = m.diffuse_brdf->clone();
    }
    else {
      diffuse_brdf = NULL;
	}
  }


  Material* Matte::clone() const {
    return new Matte(*this);
  }


  Matte::~Matte() {
    if (ambient_brdf) {
      delete ambient_brdf;
      ambient_brdf = NULL;
    }
    if (diffuse_brdf) {
      delete diffuse_brdf;
      diffuse_brdf = NULL;
    }
  }


  bool Matte::operator==(const Matte& o) const {
    return
      Material::operator==(o) &&
      *ambient_brdf == *(o.ambient_brdf) &&
      *diffuse_brdf == *(o.diffuse_brdf);
  }


  RGBColor Matte::shade(ShadeRec& sr) {
    /* Vector from the shaded point to the eye. */
    Vector3d wo = -sr.ray.direction;

    /* Luz ambiente. Criada para simular, de maneira global, a
     * iluminação difusa indireta. Constante para todos os objetos da
     * cena. Modelo de campo isotrópico 3D.  rho = kd * cd, significa:
     * o quanto o material reflete (entre 0 e 1) vezes a cor do
     * material.  Adicionalmente: cl * ls, isto é, a cor da luz vezes
     * a intensidade da luz.
     */
    RGBColor L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    const unsigned num_lights = sr.w.lights.size();

    for (unsigned j = 0; j < num_lights; ++j) {
      /* Direção da onde a luz vem (tendência: apontar para *fora* do objeto!). Isso explica a convenção da luz direcional de especificar o contrário. */
      Vector3d wi = sr.w.lights[j]->get_direction(sr);
      double ndotwi = sr.normal.dot(wi);

      if (ndotwi > 0.0) {
        bool in_shadow = false;
        if (sr.w.lights[j]->get_shadows()) {
          Ray shadow_ray(sr.hit_point, wi);
          in_shadow = sr.w.lights[j]->in_shadow(shadow_ray, sr);
        }
        /** f = (kd * cd) / pi: constante de reflexão do material * a
         * cor do material sobre pi (componente lambertiana difusa,
         * refletindo igualmente para todos os lados) L = cl * ls
         * (intensidade da luz vezes a cor da luz) ndotwi = produto
         * interno entre a normal e a direção de onde a luz vem,
         * representando cos(theta) quanto menor for esse ângulo, maior
         * é a intensidade absorvida da luz
         */
        if (!in_shadow) {
          L += diffuse_brdf->f(sr, wo, wi) * sr.w.lights[j]->L(sr) * ndotwi;
  }
      }
    }
    return L;
  }

  RGBColor Matte::area_light_shade(ShadeRec &sr) {
    Vector3d wo = -sr.ray.direction;
    RGBColor L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    const int num_lights = sr.w.lights.size();

    for (unsigned j = 0; j < num_lights; ++j) {
      Vector3d  wi = sr.w.lights[j]->get_direction(sr);
      double ndotwi = sr.normal.dot(wi);

      if (ndotwi > 0.0) {
        bool in_shadow = false;
        if (sr.w.lights[j]->get_shadows()) {
          Ray shadow_ray(sr.hit_point, wi);
          in_shadow = sr.w.lights[j]->in_shadow(shadow_ray, sr);
        }
        if (!in_shadow) {
          L += diffuse_brdf->f(sr, wo, wi) * sr.w.lights[j]->L(sr) * ndotwi * sr.w.lights[j]->G(sr) / sr.w.lights[j]->pdf(sr);
  }
      }
    }
    return L;
  }


  RGBColor Matte::get_color() const {
    return diffuse_brdf->get_cd();
  }
}
BOOST_CLASS_EXPORT_IMPLEMENT(Raytracer::Matte)
