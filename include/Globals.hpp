#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
using boost::serialization::make_nvp;
#include <Eigen/Dense>

namespace boost {
namespace serialization {
// https://stackoverflow.com/questions/12851126/serializing-eigens-matrix-using-boost-serialization
// https://stackoverflow.com/questions/18382457/eigen-and-boostserialize/23407209#23407209
// https://stackoverflow.com/questions/12580579/how-to-use-boostserialization-to-save-eigenmatrix
template <class Archive, typename _Scalar, int _Rows, int _Cols, int _Options,
          int _MaxRows, int _MaxCols>
inline void serialize(
    Archive& ar,
    Eigen::Matrix<_Scalar, _Rows, _Cols, _Options, _MaxRows, _MaxCols>& t,
    const unsigned int file_version) {
  ar& boost::serialization::make_array(t.data(), t.size());
}
}
}

/** Serialize a class into the XML format. */
template <class T>
void save_xml(const T& t, const char* filename) {
  std::ofstream ofs(filename);
  boost::archive::xml_oarchive oa(ofs);
  oa << BOOST_SERIALIZATION_NVP(t);
}

/** Load a serialized class from the XML format. */
template <class T>
void load_xml(T& t, const char* filename) {
  std::ifstream ifs(filename);
  boost::archive::xml_iarchive ia(ifs);
  ia >> BOOST_SERIALIZATION_NVP(t);
}

/** Serialize a class into a binary format. */
template <class T>
void save_binary(const T& t, const char* filename) {
  std::ofstream ofs(filename);
  boost::archive::binary_oarchive oa(ofs);
  oa << BOOST_SERIALIZATION_NVP(t);
}

/** Load a serialized class from a binary format. */
template <class T>
void load_binary(T& t, const char* filename) {
  std::ifstream ifs(filename);
  boost::archive::binary_iarchive ia(ifs);
  ia >> BOOST_SERIALIZATION_NVP(t);
}

/** Small constant for shadows. */
const double kEpsilonShadows = 1.0e-3;

/** Small constant. */
const double kEpsilon = 1.0e-6;

/** Huge constant. */
const double kHugeValue = 1.0e10;

/** Ambient Constant. Should be from 0.0 to 1.0. */
const double kKa = 0.15;

/** Diffuse Constant. Should be from 0.0 to 1.0. */
const double kKd = 0.70;

/** Specular Constant. Should be from 0.0 to 1.0. */
const double kKs = 0.15;

/** Specular Exponent from cosine. A reasonable number is from 1.0 to 20.0. */
const double kExp = 12.0;

/** Reflective Constant. */
const double kKr = 0.75;

/** Return a random integer, from begin to end, or from 0 to RAND_MAX. */
int get_random_int(int begin = 0, int end = RAND_MAX);

/** Return a random double, from begin to end, or from 0.0 to 1.0. */
double get_random_double(double begin = 0.0, double end = 1.0);

/** Return true if the argument is sufficiently near zero. */
bool is_zero(const double);

/** Generate a new seed for randomness. */
void generate_random_seed();

/**
 *  Utility function to find quadric roots. Coefficients are passed
 *  like this:
 *
 *  c[0] + c[1]*x + c[2]*x^2 = 0
 *
 *  The function return the number of non-complex roots and
 *  put the values into the s array.
 *
 *  Author: Jochen Schwarze <schwarze@isa.de>
 */
int solve_quadric(double c[3], double s[2]);

/**
 *  Utility function to find cubic roots. Coefficients are passed
 *  like this:
 *
 *  c[0] + c[1]*x + c[2]*x^2 + c[3]*x^3 = 0
 *
 *  The function return the number of non-complex roots and
 *  put the values into the s array.
 *
 *  Author: Jochen Schwarze <schwarze@isa.de>
 */
int solve_cubic(double c[4], double s[3]);

/**
 *  Utility function to find quartic roots. Coefficients are passed
 *  like this:
 *
 *  c[0] + c[1]*x + c[2]*x^2 + c[3]*x^3 + c[4]*x^4 = 0
 *
 *  The function return the number of non-complex roots and
 *  put the values into the s array.
 *
 *  Author: Jochen Schwarze <schwarze@isa.de>
 */
int solve_quartic(double c[5], double s[4]);

#endif  // _GLOBALS_H_
