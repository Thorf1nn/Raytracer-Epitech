#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_COPY_CONFIGURATION_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_COPY_CONFIGURATION_HPP

#include <iostream>
#include <string>
#include <libconfig.h++>
#include <memory>
#include <unordered_map>
#include <functional>

#include "../rayTracer/Image.hpp"
#include "../primitives/xyRect/XyRect.hpp"
#include "../primitives/sphere/Sphere.hpp"
#include "../primitives/cylinder/Cylinder.hpp"
#include "../scene/camera/Camera.hpp"
#include "../material/Lambertian.hpp"
#include "../material/Metal.hpp"
#include "../material/Dielectric.hpp"
#include "../scene/light/AmbientLight.hpp"
#include "texture/CheckerTexture.hpp"
#include "../../exceptions/RayTracerException.hpp"
#include "xzRect/XzRect.hpp"
#include "yzRect/YzRect.hpp"

namespace RayTracer {
    class Configuration {
    public:
        explicit Configuration(std::string& filename);
        ~Configuration() = default;

        void load();
        std::unique_ptr<Image> loadImage();
        std::unique_ptr<Scene::Camera> loadCamera();

        // Primitives
        std::vector<std::shared_ptr<IPrimitive>> loadPrimitives();
        std::vector<std::shared_ptr<IPrimitive>> createSpheres();
        std::vector<std::shared_ptr<IPrimitive>> createPlanes();
        std::vector<std::shared_ptr<IPrimitive>> createCylinders();
        std::vector<std::shared_ptr<IPrimitive>> createCones();
        std::vector<std::shared_ptr<IPrimitive>> createBoxes();

        // Materials
        std::shared_ptr<IMaterial> loadMaterial(const std::string& type);
        std::shared_ptr<IMaterial> createLambertian();
        std::shared_ptr<IMaterial> createMetal();
        std::shared_ptr<IMaterial> createDielectric();
        std::shared_ptr<IMaterial> createAmbient();

        // Textures
        std::shared_ptr<ITexture> loadTexture(const std::string& type);
        std::shared_ptr<ITexture> createSolidColor();
        std::shared_ptr<ITexture> createCheckerTexture();

        // Boxes
        std::shared_ptr<IPrimitive> loadBox(const std::string& type);
        std::shared_ptr<IPrimitive> createXyRect();
        std::shared_ptr<IPrimitive> createXzRect();
        std::shared_ptr<IPrimitive> createYzRect();

    private:
        std::string _filename;
        libconfig::Config _config;
        std::unordered_map<std::string, std::function<std::vector<std::shared_ptr<IPrimitive>>()>> _factory;
        std::unordered_map<std::string, std::function<std::shared_ptr<IMaterial>()>> _factoryMaterials;
        std::unordered_map<std::string, std::function<std::shared_ptr<ITexture>()>> _factoryTextures;
        std::unordered_map<std::string, std::function<std::shared_ptr<IPrimitive>()>> _factoryBoxes;
    };
} // RayTracer

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_COPY_CONFIGURATION_HPP
