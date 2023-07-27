#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_CAMERA_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_CAMERA_HPP

#include "Vector.hpp"
#include "Rectangle3D.hpp"
#include "Ray.hpp"
#include "Utils.hpp"

namespace Scene {
    class Camera {
    public:
        Camera(Math::Point<3> lookFrom, Math::Point<3> lookAt, Math::Vector<3> vup, double vfov, double aspectRatio, double aperture, double focusDist, double time0, double time1);
        ~Camera() = default;

        Math::Ray Ray(double x, double y);
        Math::Ray getRay(double u, double v);

    private:
        double _lensRadius;

        Math::Point<3> _origin;
        Primitive::Rectangle3D _screen;

        Math::Point<3> _lowerLeftCorner;
        Math::Vector<3> _horizontal;
        Math::Vector<3> _vertical;
        Math::Vector<3> u;
        Math::Vector<3> v;
        Math::Vector<3> w;
        double _time0;
        double _time1;
    };
}

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_CAMERA_HPP
