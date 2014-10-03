#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
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

template <class T>
void save_xml(const T& t, const char* filename) {
  std::ofstream ofs(filename);
  boost::archive::xml_oarchive oa(ofs);
  oa << BOOST_SERIALIZATION_NVP(t);
}

template <class T>
void load_xml(T& t, const char* filename) {
  std::ifstream ifs(filename);
  boost::archive::xml_iarchive ia(ifs);
  ia >> BOOST_SERIALIZATION_NVP(t);
}

template <class T>
void save_binary(const T& t, const char* filename) {
  std::ofstream ofs(filename);
  boost::archive::binary_oarchive oa(ofs);
  oa << BOOST_SERIALIZATION_NVP(t);
}

template <class T>
void load_binary(T& t, const char* filename) {
  std::ifstream ifs(filename);
  boost::archive::binary_iarchive ia(ifs);
  ia >> BOOST_SERIALIZATION_NVP(t);
}

#endif  // _GLOBALS_H_
