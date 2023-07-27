/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Metal
*/

#include "Metal.hpp"

namespace RayTracer {
    Metal::Metal(const Math::Color<3>& a, double f) {
        albedo = a;
        fuzz = f < 1 ? f : 1;
    }

    bool Metal::scatter (const Math::Ray& Rin, RayTracer::hitRecord& rec, Math::Color<3>& attenuation, Math::Ray& scattered) {
        Math::Vector<3> reflected = Rin.direction.unitVector().reflect(rec.normal);
        scattered = Math::Ray(rec.p, reflected + (Utils::randomInUnitSphere() * fuzz));
        attenuation = albedo;
        return (scattered.direction.dot(rec.normal) > 0);
    }
}
