#ifndef B_OOP_400_MPL_4_1_BSRAYTRACER_HUGO_ESCHLIMANN_RECTANGLE3D_HPP
#define B_OOP_400_MPL_4_1_BSRAYTRACER_HUGO_ESCHLIMANN_RECTANGLE3D_HPP

#include "Vector.hpp"
#include "../abstract/APrimitive.hpp"

namespace Primitive {
    class Rectangle3D {
    public:
        Rectangle3D() = default;
        Rectangle3D(Math::Point<3> origin, Math::Vector<3> bottomSide, Math::Vector<3> leftSide): origin(origin), bottomSide(bottomSide), leftSide(leftSide) {}
        Rectangle3D(Rectangle3D& other) = default;
        Rectangle3D(Rectangle3D&& other) = default;
        Math::Point<3> pointAt(double u, double v);

        Rectangle3D& operator=(Rectangle3D& other) = default;
        Rectangle3D& operator=(Rectangle3D&& other) = default;

        Math::Point<3> origin;
        Math::Vector<3> bottomSide;
        Math::Vector<3> leftSide;
    };
}

#endif //B_OOP_400_MPL_4_1_BSRAYTRACER_HUGO_ESCHLIMANN_RECTANGLE3D_HPP