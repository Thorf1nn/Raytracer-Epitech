#include "Camera.hpp"
#include "Utils.hpp"

namespace Scene {
    Camera::Camera(Math::Point<3> lookFrom, Math::Point<3> lookAt, Math::Vector<3> vup, double vfov, double aspectRatio, double aperture, double focusDist, double time0, double time1) {
        auto theta = RayTracer::Utils::degreesToRadians(vfov);
        auto h = tan(theta / 2);
        auto viewportHeight = 2.0 * h;
        auto viewportWidth = aspectRatio * viewportHeight;

        w = (lookFrom - lookAt).unitVector();
        u = vup.cross(w).unitVector();
        v = w.cross(u);

        _origin = lookFrom;
        _horizontal = u*viewportWidth*focusDist;
        _vertical = v*viewportHeight*focusDist;
        _lowerLeftCorner = _origin - _horizontal/2 - _vertical/2 - w*focusDist;
        _lensRadius = aperture / 2;
        _time0 = time0;
        _time1 = time1;
    }

    Math::Ray Camera::getRay(double s, double t) {
        Math::Vector<3> rd = RayTracer::Utils::randomInUnitDisk() * _lensRadius;
        Math::Vector<3> offset = u * rd._points[0] + v * rd._points[1];
        return Math::Ray(_origin + offset, _lowerLeftCorner + (_horizontal * s) + (_vertical * t) - _origin - offset, RayTracer::Utils::randomDouble(_time0, _time1));
    }

    Math::Ray Camera::Ray(double u, double v) {
        Math::Point<3> point = _screen.pointAt(u, v);
        Math::Vector<3> direction = point - _origin;
        return Math::Ray(_origin, direction, 0.0);
    }
}
