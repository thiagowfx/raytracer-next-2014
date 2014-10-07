#ifndef _REGULAR_H_
#define _REGULAR_H_

#include "Sampler.hpp"

namespace Raytracer {
/** @brief A Regular sampler distributes its samples uniformly in a unit square.
 */
class Regular : public Sampler {
 public:
  Regular(const int number_of_samples = 10);
  Regular(const Regular&);
  virtual const char* to_string();
  virtual Regular* clone() const;
  virtual ~Regular();
  virtual bool operator==(const Regular&) const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Sampler);
  }

 private:
  virtual void generate_samples();
};
}

#endif  // _REGULAR_H_
