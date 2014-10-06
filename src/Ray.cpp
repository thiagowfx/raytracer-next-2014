#include "Ray.hpp"

namespace Raytracer {
Ray::Ray() : origin(Vector3d::Zero()), direction(Vector3d(0.0, 0.0, 0.1)) {}

Ray::~Ray() {}

Ray::Ray(const Vector3d& origin, const Vector3d& direction)
    : origin(origin), direction(direction) {}

Ray::Ray(const Ray& ray) : origin(ray.origin), direction(ray.direction) {}

Ray& Ray::operator=(const Ray& rhs) {
	if (this != &rhs) {
		origin = rhs.origin;
		direction = rhs.direction;
	}
	return *this;
}

bool Ray::operator==(const Ray& o) const {
  return origin == o.origin && direction == o.direction;
}
}
