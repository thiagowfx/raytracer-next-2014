#include "BRDF.hpp"

namespace Raytracer {
BRDF::BRDF() { set_sampler(new MultiJittered(kSamples), kSampleSets); }

BRDF::BRDF(const BRDF& brdf) {
  if (brdf.sampler_ptr) {
    sampler_ptr = brdf.sampler_ptr->clone();
  } else {
    sampler_ptr = NULL;
  }
}

BRDF::~BRDF() {
  if (sampler_ptr) {
    delete sampler_ptr;
    sampler_ptr = NULL;
  }
}

bool BRDF::operator==(const BRDF& o) const {
  return *sampler_ptr == *(o.sampler_ptr);
}

RGBColor BRDF::sample_f(const ShadeRec& sr, const Vector3d& wo,
                        Vector3d& wi) const {
  return black;
}

RGBColor BRDF::sample_f(const ShadeRec& sr, const Vector3d& wo, Vector3d& wi,
                        double& pdf) const {
  return black;
}

RGBColor BRDF::f(const ShadeRec& sr, const Eigen::Vector3d& wo,
                 const Eigen::Vector3d& wi) const {
  return black;
}

RGBColor BRDF::rho(const ShadeRec& sr, const Eigen::Vector3d& wo) const {
  return black;
}

void BRDF::set_sampler(Sampler* sampler, const double exp) {
  this->sampler_ptr = sampler;
  this->sampler_ptr->map_samples_to_hemisphere(exp);
}
}
