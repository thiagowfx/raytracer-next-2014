#ifndef _JITTERED_H_
#define _JITTERED_H_

#include "Sampler.hpp"

namespace Raytracer {
class Jittered : public Sampler {
 public:
  Jittered(const int number_of_samples = 10);
  Jittered(const Jittered&);
  virtual const char* to_string();
  virtual Jittered* clone() const;
  virtual ~Jittered();
  virtual bool operator==(const Jittered&) const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Sampler);
  }

 private:
  virtual void generate_samples();
};
}

#endif  // _JITTERED_H_
