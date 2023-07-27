#include "Core.hpp"

namespace RayTracer {
    Core::Core(const std::string& filename) : _filename(filename) {}

    void Core::launch() {
        Configuration configuration(_filename);
        configuration.load();

        std::unique_ptr<Image> image = configuration.loadImage();
        std::unique_ptr<Scene::Camera> camera = configuration.loadCamera();

        APrimitive world;
        for (std::shared_ptr<IPrimitive>& primitive : configuration.loadPrimitives()) {
            world.add(primitive);
        }

        std::cout << "P3\n" << " " << image->getWidth() << " " << image->getHeight() << "\n255\n";
        for (int y = image->getHeight() - 1; y >= 0; --y) {
            std::cerr << "\rTemps restant: " << y << " " << std::flush;
            for (int x = 0; x < image->getWidth(); ++x) {
                Math::Vector<3> pixelColor{0.0, 0.0, 0.0};
                for (int s = 0; s < image->getSamplesPerPixel(); s++) {
                    double u = (x + Utils::randomDouble()) / (image->getWidth()-1);
                    double v = (y + Utils::randomDouble()) / (image->getHeight()-1);
                    Math::Ray r = camera->getRay(u, v);
                    pixelColor += Utils::rayColor(r, image->getBackground(), world, image->getMaxDepth());
                }
                Utils::writeColor(std::cout, pixelColor, image->getSamplesPerPixel());
            }
        }
        std::cerr << "\nDone.\n";
        world.clear();
    }
}