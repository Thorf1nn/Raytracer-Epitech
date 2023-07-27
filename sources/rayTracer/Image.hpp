#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_IMAGE_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_IMAGE_HPP

#include <iostream>
#include "Vector.hpp"

namespace RayTracer {
    class Image {
    public:
        Image(int width, int height, int samplesPerPixel, int maxDepth, Math::Color<3> background) : _width(width), _height(height), _samplesPerPixel(samplesPerPixel), _maxDepth(maxDepth), _background(background) {}
        ~Image() = default;

        int getWidth() const;
        int getHeight() const;
        int getSamplesPerPixel() const;
        int getMaxDepth() const;
        Math::Color<3> getBackground() const;

    private:
        int _width;
        int _height;
        int _samplesPerPixel;
        int _maxDepth;
        Math::Color<3> _background;
    };
}

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_IMAGE_HPP
