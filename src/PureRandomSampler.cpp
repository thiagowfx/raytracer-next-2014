#include "PureRandomSampler.hpp"

namespace Raytracer {
PureRandom::PureRandom(const int number_of_samples)
    : Sampler(number_of_samples) {
  generate_samples();
}

PureRandom::PureRandom(const PureRandom& r) : Sampler(r) { generate_samples(); }

const char* PureRandom::to_string() { return "PureRandom"; }

PureRandom* PureRandom::clone() const { return new PureRandom(*this); }

bool PureRandom::operator==(const PureRandom& o) const {
  return Sampler::operator==(o);
}

PureRandom::~PureRandom() {}

void PureRandom::generate_samples() {
  for (unsigned p = 0; p < number_of_sets; p++) {
    for (unsigned q = 0; q < number_of_samples; q++) {
      samples.push_back(Vector2d(get_random_double(), get_random_double()));
    }
  }
}
}
