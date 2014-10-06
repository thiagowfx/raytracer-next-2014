#ifndef _RGBCOLOR_H_
#define _RGBCOLOR_H_

#include "Globals.hpp"
#include <algorithm>

namespace Raytracer {
/** @brief A color in the RGB format, which components are in the 0.0 to 1.0
 * range. */
class RGBColor {
 public:
  /** Create a RGBColor with the specified red, green and blue components. */
  RGBColor(float, float, float);
  RGBColor(const RGBColor&);
  RGBColor();
  ~RGBColor();
  RGBColor& operator=(const RGBColor&);
  bool operator==(const RGBColor&) const;
  bool operator!=(const RGBColor&) const;
  RGBColor operator+(const RGBColor&) const;
  RGBColor& operator+=(const RGBColor&);
  RGBColor operator*(const float) const;
  RGBColor& operator*=(const float);
  RGBColor operator/(const float) const;
  RGBColor& operator/=(const float);
  RGBColor operator*(const RGBColor&) const;
  float get_r() const;
  float get_g() const;
  float get_b() const;
  void set_r(float);
  void set_g(float);
  void set_b(float);

 private:
  /** Red component. */
  float r;

  /** Green component. */
  float g;

  /** Blue component. */
  float b;

 public:
  friend RGBColor operator*(const float, const RGBColor&);

  /** Raise color components to the specified power. */
  RGBColor powc(float) const;

  /** The average of the components. */
  float average() const;

  /** Normalize all components if any of them is greater than one. */
  RGBColor normalize() const;

  /** Return red if any component is greater than one. */
  RGBColor clamp_to_red() const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_NVP(r);
    ar& BOOST_SERIALIZATION_NVP(g);
    ar& BOOST_SERIALIZATION_NVP(b);
  }
};

/* Color constants. */
const RGBColor black(0.0, 0.0, 0.0);
const RGBColor blue(0.0, 0.0, 1.0);
const RGBColor brown(0.71, 0.40, 0.16);
const RGBColor dark_green(0.0, 0.41, 0.41);
const RGBColor dark_gray(0.25, 0.25, 0.25);
const RGBColor dark_purple(0.5, 0.0, 1);
const RGBColor dark_yellow(0.61, 0.61, 0.0);
const RGBColor green(0.0, 1.0, 0.0);
const RGBColor gray(0.50, 0.50, 0.50);
const RGBColor light_green(0.65, 1.0, 0.30);
const RGBColor light_gray(0.75, 0.75, 0.75);
const RGBColor light_purple(0.65, 0.3, 1.0);
const RGBColor orange(1.0, 0.75, 0.0);
const RGBColor red(1.0, 0.0, 0.0);
const RGBColor white(1.0, 1.0, 1.0);
const RGBColor yellow(1.0, 1.0, 0.0);

inline RGBColor RGBColor::powc(float p) const {
  return RGBColor(pow(r, p), pow(g, p), pow(b, p));
}

inline RGBColor RGBColor::normalize() const {
  float max_value = std::max(r, std::max(g, b));
  return (max_value > 1.0) ? (*this / max_value) : *this;
}

inline RGBColor RGBColor::clamp_to_red() const {
  return (r > 1.0 || g > 1.0 || b > 1.0) ? RGBColor(1.0, 0.0, 0.0) : *this;
}

inline RGBColor RGBColor::operator+(const RGBColor& c) const {
  return RGBColor(r + c.r, g + c.g, b + c.b);
}

inline RGBColor& RGBColor::operator+=(const RGBColor& c) {
  r += c.r;
  g += c.g;
  b += c.b;
  return *this;
}

inline RGBColor RGBColor::operator*(const float a) const {
  return RGBColor(r * a, g * a, b * a);
}

inline RGBColor& RGBColor::operator*=(const float a) {
  r *= a;
  g *= a;
  b *= a;
  return *this;
}

inline RGBColor RGBColor::operator/(const float a) const {
  return RGBColor(r / a, g / a, b / a);
}

inline RGBColor& RGBColor::operator/=(const float a) {
  r /= a;
  g /= a;
  b /= a;
  return *this;
}

inline RGBColor RGBColor::operator*(const RGBColor& c) const {
  return RGBColor(r * c.r, g * c.g, b * c.b);
}

inline bool RGBColor::operator==(const RGBColor& o) const {
  return r == o.r && g == o.g && b == o.b;
}

inline bool RGBColor::operator!=(const RGBColor& c) const {
  return !operator==(c);
}

inline float RGBColor::average() const { return (r + g + b) / 3.0; }

inline RGBColor operator*(const float a, const RGBColor& c) {
  return RGBColor(a * c.r, a * c.g, a * c.b);
}

inline float RGBColor::get_r() const { return r; }

inline float RGBColor::get_g() const { return g; }

inline float RGBColor::get_b() const { return b; }

inline void RGBColor::set_r(float r) { this->r = r; }

inline void RGBColor::set_g(float g) { this->g = g; }

inline void RGBColor::set_b(float b) { this->b = b; }
}

#endif  // _RGBCOLOR_H_
