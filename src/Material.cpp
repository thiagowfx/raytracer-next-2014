#include "Material.hpp"

namespace Raytracer {
  Material::Material() {}

  Material::~Material() {}

  Material::Material(const Material&) {}

  bool Material::operator==(const Material&) const {
    return true;
  }

  RGBColor Material::get_Le(ShadeRec& sr) const {
    return black;
  }
}
