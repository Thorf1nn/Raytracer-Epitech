#include "AMaterial.hpp"

namespace RayTracer {
    Math::Color<3> AMaterial::emitted(double u, double v, const Math::Point<3>& p) {
        return Math::Color<3>{0, 0, 0};
    }
} // RayTracer