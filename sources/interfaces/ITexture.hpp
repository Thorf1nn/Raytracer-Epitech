#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_ITEXTURE_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_ITEXTURE_HPP

#include "../math/Math.hpp"
#include "../math/Vector.hpp"

namespace RayTracer {
    class ITexture {
    public:
        virtual ~ITexture() = default;
        virtual Math::Vector<3> value(double u, double v, const Math::Vector<3> &p) const = 0;
    };
} // RayTracer

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_ITEXTURE_HPP
