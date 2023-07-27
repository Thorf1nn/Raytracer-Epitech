#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_RAY_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_RAY_HPP

#include "Vector.hpp"

namespace Math {
    class Ray {
    public:
        Ray() = default;
        Ray(Point<3> origin, Vector<3> direction);
        Ray(Point<3> origin, Vector<3> direction, double time);
        Ray(Ray& other) = default;
        Ray(Ray&& other) = default;
        Ray& operator=(Ray& other) = default;
        Ray& operator=(Ray&& other) = default;

        Vector<3> at(double t) const;

        Point<3> origin;
        Vector<3> direction;
        double time;
    };
} // math

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_RAY_HPP