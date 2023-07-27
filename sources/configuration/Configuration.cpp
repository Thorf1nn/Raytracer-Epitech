#include "Configuration.hpp"

namespace RayTracer {
    Configuration::Configuration(std::string& filename) : _filename(filename), _config() {
        _factory = {
                {"spheres", [this]() -> std::vector<std::shared_ptr<IPrimitive>> { return createSpheres(); }},
                {"planes", [this]() -> std::vector<std::shared_ptr<IPrimitive>> { return createPlanes(); }},
                {"cylinders", [this]() -> std::vector<std::shared_ptr<IPrimitive>> { return createCylinders(); }},
                {"cones", [this]() -> std::vector<std::shared_ptr<IPrimitive>> { return createCones(); }},
                {"boxes", [this]() -> std::vector<std::shared_ptr<IPrimitive>> { return createBoxes(); }}
        };

        _factoryMaterials = {
                {"lambertian", [this]() -> std::shared_ptr<IMaterial> { return createLambertian(); }},
                {"metal", [this]() -> std::shared_ptr<IMaterial> { return createMetal(); }},
                {"dielectric", [this]() -> std::shared_ptr<IMaterial> { return createDielectric(); }},
                {"ambient", [this]() -> std::shared_ptr<IMaterial> { return createAmbient(); }}
        };

        _factoryTextures = {
                {"solidColor", [this]() -> std::shared_ptr<ITexture> { return createSolidColor(); }},
                {"checkerTexture", [this]() -> std::shared_ptr<ITexture> { return createCheckerTexture(); }}
        };

        _factoryBoxes = {
                {"XyRect", [this]() -> std::shared_ptr<IPrimitive> { return createXyRect(); }},
                {"XzRect", [this]() -> std::shared_ptr<IPrimitive> { return createXzRect(); }},
                {"YzRect", [this]() -> std::shared_ptr<IPrimitive> { return createYzRect(); }}
        };
    }

    void Configuration::load() {
        _config.readFile(_filename.c_str());
    }

    std::unique_ptr<Image> Configuration::loadImage() {
        libconfig::Setting& imageSetting = _config.lookup("image");
        return std::make_unique<Image>(
                imageSetting.lookup("resolution.width").operator int(),
                imageSetting.lookup("resolution.height").operator int(),
                imageSetting.lookup("samplesPerPixel").operator int(),
                imageSetting.lookup("maxDepth").operator int(),
                Math::Color<3>{
                    imageSetting.lookup("background.r").operator double(),
                    imageSetting.lookup("background.g").operator double(),
                    imageSetting.lookup("background.b").operator double()
        });
    }

    std::unique_ptr<Scene::Camera> Configuration::loadCamera() {
        libconfig::Setting& cameraSetting = _config.lookup("camera");

        return std::make_unique<Scene::Camera>(
                Math::Point<3>{cameraSetting.lookup("lookFrom.x").operator double(), cameraSetting.lookup("lookFrom.y").operator double(), cameraSetting.lookup("lookFrom.z").operator double()},
                Math::Point<3>{cameraSetting.lookup("lookAt.x").operator double(), cameraSetting.lookup("lookAt.y").operator double(), cameraSetting.lookup("lookAt.z").operator double()},
                Math::Vector<3>{cameraSetting.lookup("vup.x").operator double(), cameraSetting.lookup("vup.y").operator double(), cameraSetting.lookup("vup.z").operator double()},
                cameraSetting.lookup("fov").operator double(),
                cameraSetting.lookup("aspectRatio").operator double(),
                cameraSetting.lookup("aperture").operator double(),
                cameraSetting.lookup("focusDistance").operator double(),
                cameraSetting.lookup("time0").operator double(),
                cameraSetting.lookup("time1").operator double()
        );
    }

    std::vector<std::shared_ptr<IPrimitive>> Configuration::loadPrimitives() {
        libconfig::Setting& primitivesSetting = _config.lookup("primitives");
        std::vector<std::shared_ptr<IPrimitive>> primitives;
        std::vector<std::shared_ptr<IPrimitive>> tmp;

        for (int i = 0; i < primitivesSetting.getLength(); i++) {
            std::string type = primitivesSetting[i].getName();
            if (_factory.find(type) == _factory.end()) {
                throw RayTracerException("Component " + type + " not found");
            }
            tmp = _factory.find(type)->second();
            primitives.insert(primitives.end(), tmp.begin(), tmp.end());
        }
        return primitives;
    }

    std::shared_ptr<IMaterial> Configuration::loadMaterial(const std::string& type) {
        if (_factoryMaterials.find(type) == _factoryMaterials.end()) {
            throw RayTracerException("Component " + type + " not found");
        }
        return _factoryMaterials.find(type)->second();
    }

    std::shared_ptr<ITexture> Configuration::loadTexture(const std::string &type) {
        if (_factoryTextures.find(type) == _factoryTextures.end()) {
            throw RayTracerException("Component " + type + " not found");
        }
        return _factoryTextures.find(type)->second();
    }

    std::shared_ptr<IPrimitive> Configuration::loadBox(const std::string &type) {
        if (_factoryBoxes.find(type) == _factoryBoxes.end()) {
            throw RayTracerException("Component " + type + " not found");
        }
        return _factoryBoxes.find(type)->second();
    }

    std::vector<std::shared_ptr<IPrimitive>> Configuration::createSpheres() {
        libconfig::Setting& spheresSetting { _config.lookup("primitives.spheres") };
        std::vector<std::shared_ptr<IPrimitive>> spheres;

        for (int i = 0; i < spheresSetting.getLength(); i++) {
            double x = spheresSetting[i].lookup("center.x");
            double y = spheresSetting[i].lookup("center.y");
            double z = spheresSetting[i].lookup("center.z");
            double radius = spheresSetting[i].lookup("radius");
            std::string materialType = spheresSetting[i].lookup("material").operator std::string();
            std::shared_ptr<IMaterial> material = loadMaterial(materialType);
            std::shared_ptr<IPrimitive> sphere = std::make_shared<Primitive::Sphere>(Math::Point<3>{x, y, z}, radius, material);
            if (spheresSetting[i].exists("translate")) {
                sphere->translate(Math::Vector<3>{
                        spheresSetting[i].lookup("translate.x").operator double(),
                        spheresSetting[i].lookup("translate.y").operator double(),
                        spheresSetting[i].lookup("translate.z").operator double()
                });
            }
            spheres.push_back(sphere);
        }
        return spheres;
    }

    std::vector<std::shared_ptr<IPrimitive>> Configuration::createBoxes() {
        libconfig::Setting& boxesSetting { _config.lookup("primitives.boxes") };
        std::vector<std::shared_ptr<IPrimitive>> boxes;

        for (int i = 0; i < boxesSetting.getLength(); i++) {
            std::string type = boxesSetting[i].getName();
            if (_factoryBoxes.find(type) == _factoryBoxes.end()) {
                throw RayTracerException("Component " + type + " not found");
            }
            boxes.push_back(_factoryBoxes.find(type)->second());
        }
        return boxes;
    }

    std::shared_ptr<IPrimitive> Configuration::createXyRect() {
        libconfig::Setting& xyRectSetting { _config.lookup("primitives.boxes.XyRect") };
        double x0 = xyRectSetting.lookup("x0").operator double();
        double x1 = xyRectSetting.lookup("x1").operator double();
        double y0 = xyRectSetting.lookup("y0").operator double();
        double y1 = xyRectSetting.lookup("y1").operator double();
        double k = xyRectSetting.lookup("k").operator double();
        std::string materialType = xyRectSetting.lookup("material").operator std::string();
        std::shared_ptr<IMaterial> material = loadMaterial(materialType);
        return std::make_shared<RayTracer::XyRect>(x0, x1, y0, y1, k, material);
    }

    std::shared_ptr<IPrimitive> Configuration::createXzRect() {
        libconfig::Setting& xzRectSetting { _config.lookup("primitives.boxes.XzRect") };
        double x0 = xzRectSetting.lookup("x0").operator double();
        double x1 = xzRectSetting.lookup("x1").operator double();
        double z0 = xzRectSetting.lookup("z0").operator double();
        double z1 = xzRectSetting.lookup("z1").operator double();
        double k = xzRectSetting.lookup("k").operator double();
        std::string materialType = xzRectSetting.lookup("material").operator std::string();
        std::shared_ptr<IMaterial> material = loadMaterial(materialType);
        return std::make_shared<RayTracer::XzRect>(x0, x1, z0, z1, k, material);
    }

    std::shared_ptr<IPrimitive> Configuration::createYzRect() {
        libconfig::Setting& yzRectSetting { _config.lookup("primitives.boxes.YzRect") };
        double y0 = yzRectSetting.lookup("y0").operator double();
        double y1 = yzRectSetting.lookup("y1").operator double();
        double z0 = yzRectSetting.lookup("z0").operator double();
        double z1 = yzRectSetting.lookup("z1").operator double();
        double k = yzRectSetting.lookup("k").operator double();
        std::string materialType = yzRectSetting.lookup("material").operator std::string();
        std::shared_ptr<IMaterial> material = loadMaterial(materialType);
        return std::make_shared<RayTracer::YzRect>(y0, y1, z0, z1, k, material);
    }

    std::vector<std::shared_ptr<IPrimitive>> Configuration::createPlanes() {
        std::vector<std::shared_ptr<IPrimitive>> planes;
        return planes;
    }

    std::vector<std::shared_ptr<IPrimitive>> Configuration::createCylinders() {
        std::vector<std::shared_ptr<IPrimitive>> cylinders;
        return cylinders;
    }

    std::vector<std::shared_ptr<IPrimitive>> Configuration::createCones() {
        std::vector<std::shared_ptr<IPrimitive>> cones;
        return cones;
    }

    std::shared_ptr<IMaterial> Configuration::createLambertian() {
        libconfig::Setting& lambertianSetting = _config.lookup("materials.lambertian");

        return std::make_shared<Lambertian>(loadTexture(lambertianSetting.operator std::string()));
    }

    std::shared_ptr<IMaterial> Configuration::createMetal() {
        libconfig::Setting& metalSetting = _config.lookup("materials.metal");
        Math::Color<3> color{metalSetting.lookup("color.r"), metalSetting.lookup("color.g"), metalSetting.lookup("color.b")};
        return std::make_shared<Metal>(color, metalSetting.lookup("fuzz").operator double());
    }

    std::shared_ptr<IMaterial> Configuration::createDielectric() {
        libconfig::Setting& dielectricSetting = _config.lookup("materials.dielectric");
        return std::make_shared<Dielectric>(dielectricSetting.lookup("refractionIndex").operator double());
    }

    std::shared_ptr<IMaterial> Configuration::createAmbient() {
//        std::cout << "ambient" << std::endl;
        libconfig::Setting& ambientSetting = _config.lookup("lights.ambient");

        return std::make_shared<Scene::AmbientLight>(Math::Color<3>{
            ambientSetting.lookup("color.r").operator double(),
            ambientSetting.lookup("color.g").operator double(),
            ambientSetting.lookup("color.b").operator double()
        });
    }

    std::shared_ptr<ITexture> Configuration::createSolidColor() {
        libconfig::Setting& solidColorSetting = _config.lookup("textures.solidColor");
        return std::make_shared<SolidColor>(Math::Color<3>{
            solidColorSetting.lookup("color.r").operator double(),
            solidColorSetting.lookup("color.g").operator double(),
            solidColorSetting.lookup("color.b").operator double()
        });
    }

    std::shared_ptr<ITexture> Configuration::createCheckerTexture() {
        libconfig::Setting& checkerTextureSetting = _config.lookup("textures.checkerTexture");
        return std::make_shared<CheckerTexture>(
                Math::Color<3>{
                        checkerTextureSetting.lookup("colorEven.r").operator double(),
                        checkerTextureSetting.lookup("colorEven.g").operator double(),
                        checkerTextureSetting.lookup("colorEven.b").operator double()
                },
                Math::Color<3>{
                        checkerTextureSetting.lookup("colorOdd.r").operator double(),
                        checkerTextureSetting.lookup("colorOdd.g").operator double(),
                        checkerTextureSetting.lookup("colorOdd.b").operator double()
                }
        );
    }
} // RayTracer