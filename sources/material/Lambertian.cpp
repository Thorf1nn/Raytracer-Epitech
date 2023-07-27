/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Lambertian
*/

#include "Lambertian.hpp"

namespace RayTracer {
    Lambertian::Lambertian(const Math::Color<3> &a) : albedo(std::make_shared<SolidColor>(a)) {}

    Lambertian::Lambertian(std::shared_ptr<ITexture> a) : albedo(a) {}

    bool Lambertian::scatter(const Math::Ray &rin, RayTracer::hitRecord &rec, Math::Color<3> &attenuation, Math::Ray &scattered) {
        auto scatterDirection = rec.normal + Utils::randomUnitVector();

        if (scatterDirection.nearZero())
            scatterDirection = rec.normal;

        scattered = Math::Ray(rec.p, scatterDirection);
        attenuation = albedo->value(rec.u, rec.v, rec.p);
        return true;
    }
}