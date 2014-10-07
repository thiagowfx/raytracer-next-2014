#ifndef _SAMPLER_H_
#define _SAMPLER_H_

#include "Globals.hpp"
#include <algorithm>
#include <cmath>
#include <vector>
#include <Eigen/Dense>
using Eigen::Vector2d;
using Eigen::Vector3d;

namespace Raytracer {
/**
 * @brief A sampler is responsible for generating sample points
 * according to a pattern, which might be random or well distributed.
 */
class Sampler {
 public:
  /** Create a sampler with the given number of samples and sets. */
  Sampler(const int number_of_samples = kSamples,
          const int number_of_sets = kSampleSets);
  Sampler(const Sampler&);
  virtual Sampler* clone() const = 0;
  virtual ~Sampler();
  virtual bool operator==(const Sampler&) const;

  /** A string with the class name. */
  virtual const char* to_string() = 0;

  /** Return the number of samples. */
  int get_number_of_samples() const;

  /** Shuffle the x coordinates of the points within each set. */
  void shuffle_x_coordinates();

  /** Shuffle the y coordinates of the points within set. */
  void shuffle_y_coordinates();

  /** Sets up randomly shuffled indices for the samples array. */
  void setup_shuffled_indices();

  /** Generate sample patterns in a unit square. */
  virtual void generate_samples() = 0;

  /** Get next sample on unit square. */
  Vector2d sample_unit_square();

  /** Maps the 2D sample points in the square [-1,1] X [-1,1] to a
      unit disk, using Peter Shirley's concentric map function. */
  void map_samples_to_unit_disk();

  /** Get next sample on unit disk. */
  Vector2d sample_unit_disk();

  /** Maps the 2D sample points to 3D points on a unit hemisphere with
      a cosine power density distribution in the polar angle. */
  void map_samples_to_hemisphere(const double);

  /** Get next sample on unit hemisphere. */
  Vector3d sample_hemisphere();

  /** Maps the 2D sample points to 3D points on a unit sphere with a
      uniform density distribution over the surface -- this is used
      for modelling a spherical light. */
  void map_samples_to_sphere();

  /** Get next sample on unit sphere. */
  Vector3d sample_sphere();

 protected:
  /** Number of sample points in a set */
  unsigned number_of_samples;

  /** Number of sample sets */
  unsigned number_of_sets;

  /** Current number of sample points used */
  unsigned long count;

  /** Random index jump. */
  int jump;

  /** Sample points on a unit square */
  std::vector<Vector2d> samples;

  /** Shuffled samples array indices */
  std::vector<int> shuffled_indices;

  /** Sample points on a unit disk */
  std::vector<Vector2d> disk_samples;

  /** Sample points on a unit hemisphere */
  std::vector<Vector3d> hemisphere_samples;

  /** Sample points on a unit sphere */
  std::vector<Vector3d> sphere_samples;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_NVP(number_of_samples);
    ar& BOOST_SERIALIZATION_NVP(number_of_sets);
    ar& BOOST_SERIALIZATION_NVP(count);
    ar& BOOST_SERIALIZATION_NVP(jump);
    ar& BOOST_SERIALIZATION_NVP(samples);
    ar& BOOST_SERIALIZATION_NVP(shuffled_indices);
    ar& BOOST_SERIALIZATION_NVP(disk_samples);
    ar& BOOST_SERIALIZATION_NVP(hemisphere_samples);
    ar& BOOST_SERIALIZATION_NVP(sphere_samples);
  }
};
}

#endif  // _SAMPLER_H_
