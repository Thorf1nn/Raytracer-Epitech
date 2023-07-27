#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_AMBIENTLIGHT_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_AMBIENTLIGHT_HPP

#include "../../abstract/ALight.hpp"
#include "Math.hpp"
#include "IMaterial.hpp"
#include "ITexture.hpp"
#include "IPrimitive.hpp"
#include "texture/SolidColor.hpp"

namespace Scene {
    class AmbientLight : public RayTracer::IMaterial {
    public:
        explicit AmbientLight(Math::Color<3> c) : emit(std::make_shared<RayTracer::SolidColor>(c)) {};
        ~AmbientLight() override = default;

        Math::Color<3> emitted(double u, double v, const Math::Point<3>& p) override;
        bool scatter(const Math::Ray& rin, RayTracer::hitRecord& rec, Math::Color<3>& attenuation, Math::Ray& scattered) override;

        std::shared_ptr<RayTracer::ITexture> emit;
    };
} // Scene

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_AMBIENTLIGHT_HPP
