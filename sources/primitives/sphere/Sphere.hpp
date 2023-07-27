/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Sphere
*/

#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_SPHERE_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_SPHERE_HPP

#include "IMaterial.hpp"
#include "IPrimitive.hpp"
#include "Math.hpp"
#include "Ray.hpp"
#include "AABB.hpp"

namespace Primitive {
    class Sphere : public RayTracer::IPrimitive {
    public:
        Sphere(Math::Point<3> center, double radius);
        Sphere(Math::Point<3> center, double radius, std::shared_ptr<RayTracer::IMaterial> mat);
        ~Sphere() override = default;

        bool hits(const Math::Ray& r, double Tmin, double Tmax, RayTracer::hitRecord& rec) override;
        bool boundingBox(double time0, double time1, AABB& outputBox) const override;

        void translate(Math::Vector<3> direction) override;
        void rotation() override {}


        static void getSphereUv(const Math::Point<3>& p, double& u, double& v);

        Math::Point<3> center;
        double radius;
        std::shared_ptr<RayTracer::IMaterial> matPtr;
    };
}

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_SPHERE_HPP