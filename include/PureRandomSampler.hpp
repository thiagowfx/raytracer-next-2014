#ifndef _PURERANDOM_H_
#define _PURERANDOM_H_

#include "Sampler.hpp"

namespace Raytracer {
/**
 * @brief A PureRandom sampler generates all samples randomly.
 */
class PureRandom : public Sampler {
 public:
  PureRandom(const int number_of_samples = 10);
  PureRandom(const PureRandom&);
  virtual const char* to_string();
  virtual PureRandom* clone() const;
  virtual ~PureRandom();
  virtual bool operator==(const PureRandom&) const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Sampler);
  }

 private:
  virtual void generate_samples();
};
}

#endif  // _PURERANDOM_H_
