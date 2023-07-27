#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_DIRECTIONALLIGHT_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_DIRECTIONALLIGHT_HPP

#include "ILight.hpp"

namespace Scene {
    class DirectionalLight : public Scene::ILight {
    public:
        DirectionalLight() = default;
        ~DirectionalLight() = default;
    };
}

extern "C" Scene::ILight *entryPoint();

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_DIRECTIONALLIGHT_HPP
