#ifndef _NROOKS_H_
#define _NROOKS_H_

#include "Sampler.hpp"

namespace Raytracer {
/**
 * @brief A NRooks sampler generates only one sampler per line and column, in a
 * scheme compared to placing rooks in a chess board.
 */
class NRooks : public Sampler {
 public:
  NRooks(const int number_of_samples = kSamples);
  NRooks(const NRooks&);
  virtual const char* to_string();
  virtual NRooks* clone() const;
  virtual ~NRooks();
  virtual bool operator==(const NRooks&) const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Sampler);
  }

 private:
  virtual void generate_samples();
};
}

#endif  // _NROOKS_H_
