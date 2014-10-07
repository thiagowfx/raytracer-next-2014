#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "Globals.hpp"
#include "RGBColor.hpp"
#include "ShadeRec.hpp"
#include <Eigen/Dense>
using Eigen::Vector3d;

namespace Raytracer {
  /**
   * @brief A material for a geometric object. Its shade function is
   * responsible for shading the correct color for a given ShadeRec object.
   */
  class Material {
  public:
    Material();
    virtual ~Material();
    Material(const Material&);
    virtual Material* clone() const = 0;
    virtual bool operator==(const Material&) const;

    /** Return the main color of this material, necessary for the
        MultipleObjects tracer. Lights shouldn't be present in this
        calculation. */
    virtual RGBColor get_color() const = 0;

    /** How should the color of a point in a geometric object be computed? */
    virtual RGBColor shade(ShadeRec&) = 0;

    /* Required for area lights. */
    virtual RGBColor area_light_shade(ShadeRec&) = 0;
    
    /** Effective color (radiance * hue) emitted by this material. */
    virtual RGBColor get_Le(ShadeRec&) const;

    friend class boost::serialization::access;
    template<class Archive>
      void serialize(Archive& ar, const unsigned int version) {}
  };
}

#endif // _MATERIAL_H_
