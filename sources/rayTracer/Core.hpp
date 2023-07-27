#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_CORE_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_CORE_HPP

#include <memory>
#include <iostream>
#include <libconfig.h++>
#include "../configuration/Configuration.hpp"
#include "../abstract/APrimitive.hpp"
#include "../utils/Utils.hpp"
#include "../primitives/sphere/Sphere.hpp"
#include "../primitives/cylinder/Cylinder.hpp"
#include "../math/Ray.hpp"
#include "../scene/camera/Camera.hpp"

namespace RayTracer {
    class Core {
    public:
        explicit Core(const std::string& filename);
        ~Core() = default;

        void launch();

    private:
        std::string _filename;
    };
}

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_CORE_HPP
