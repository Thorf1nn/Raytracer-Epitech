#include "Ray.hpp"

namespace Math {
    Ray::Ray(Point<3> origin, Vector<3> direction, double time) : origin(origin), direction(direction), time(time) {}

    Ray::Ray(Point<3> origin, Vector<3> direction) : origin(origin), direction(direction) {}

    Vector<3> Ray::at(double t) const{
        return origin + (direction * t);
    }
}