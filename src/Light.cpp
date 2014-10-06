#include "Light.hpp"

namespace Raytracer {
Light::Light() : shadows(true) {}

Light::Light(const Light& ls) : shadows(ls.shadows) {}

Light::~Light() {}

bool Light::operator==(const Light& o) const { return shadows == o.shadows; }

RGBColor Light::L(ShadeRec& s) { return black; }

void Light::set_shadows(const bool shadow) { shadows = shadow; }

bool Light::get_shadows() const { return shadows; }

double Light::G(const ShadeRec& sr) const { return 1.0; }

double Light::pdf(const ShadeRec& sr) const { return 1.0; }
}
