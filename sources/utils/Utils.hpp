#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_COPY_UTILS_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_COPY_UTILS_HPP

#include <iostream>
#include <string>

#include "Math.hpp"
#include "../primitives/sphere/Sphere.hpp"

namespace RayTracer {
    class Utils {
    public:
        static void writeColor(std::ostream& out, Math::Vector<3>& color, int samplesPerPixel);
        static Math::Vector<3> rayColor(const Math::Ray&, const Math::Color<3> &, RayTracer::IPrimitive&, int);
        static double randomDouble();
        static double randomDouble(double min, double max);
        static Math::Vector<3> random();
        static Math::Vector<3> random(double min, double max);
        static Math::Vector<3> randomInUnitSphere();
        static Math::Vector<3> randomUnitVector();
        static Math::Vector<3> randomInHemisphere(const Math::Vector<3>& normal);
        static Math::Vector<3> randomInUnitDisk();
        static double clamp(double x, double min, double max);
        static double degreesToRadians(double degrees);
    };
}

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_COPY_UTILS_HPP
