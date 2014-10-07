#include "BRDF.hpp"

namespace Raytracer {
BRDF::BRDF() {}

BRDF::BRDF(const BRDF& brdf) {}

BRDF::~BRDF() {}

bool BRDF::operator==(const BRDF& o) const { return true; }

RGBColor BRDF::sample_f(const ShadeRec& sr, const Vector3d& wo, Vector3d& wi) const {
  return black;
}

RGBColor BRDF::sample_f(const ShadeRec& sr, const Vector3d& wo, Vector3d& wi, double& pdf) const {
  return black;
}

RGBColor BRDF::f(const ShadeRec& sr, const Eigen::Vector3d& wo, const Eigen::Vector3d& wi) const {
  return black;
}

RGBColor BRDF::rho(const ShadeRec& sr, const Eigen::Vector3d& wo) const {
  return black;
}
}
