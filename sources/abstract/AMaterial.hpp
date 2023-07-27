#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_AMATERIAL_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_AMATERIAL_HPP

#include "IMaterial.hpp"

namespace RayTracer {
    class AMaterial : public IMaterial {
    public:
        ~AMaterial() override = default;

        Math::Color<3> emitted(double u, double v, const Math::Point<3>& p) override;
    };
} // RayTracer

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_AMATERIAL_HPP
