#include "Rectangle3D.hpp"

namespace Primitive {
    Math::Point<3> Rectangle3D::pointAt(double u, double v) {
        Math::Vector<3> vec = origin + bottomSide * u + leftSide * v;
        Math::Point<3> point{vec._points[0], vec._points[1], vec._points[2]};
        return point;
    }
}