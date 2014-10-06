#include "RGBColor.hpp"
#include <math.h>

namespace Raytracer {
RGBColor::RGBColor() : r(0.0), g(0.0), b(0.0) {}

RGBColor::RGBColor(float r, float g, float b) : r(r), g(g), b(b) {}

RGBColor::RGBColor(const RGBColor& c) : r(c.r), g(c.g), b(c.b) {}

RGBColor::~RGBColor() {}

RGBColor& RGBColor::operator=(const RGBColor& rhs) {
  if (this != &rhs) {
    r = rhs.r;
    g = rhs.g;
    b = rhs.b;
  }
  return *this;
}}
