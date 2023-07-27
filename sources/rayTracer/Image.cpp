#include "Image.hpp"

namespace RayTracer {
    int Image::getWidth() const {
        return _width;
    }
    int Image::getHeight() const {
        return _height;
    }
    int Image::getSamplesPerPixel() const {
        return _samplesPerPixel;
    }
    int Image::getMaxDepth() const {
        return _maxDepth;
    }
    Math::Color<3> Image::getBackground() const {
        return _background;
    }
}
