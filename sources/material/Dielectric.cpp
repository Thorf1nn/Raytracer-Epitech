/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Dielectric
*/

#include "Dielectric.hpp"

namespace RayTracer {
    Dielectric::Dielectric(double indexOfRefraction) : ir(indexOfRefraction) {}

    Dielectric::Dielectric(std::shared_ptr<ITexture>& a, double indexOfRefraction) : albedo(a), ir(indexOfRefraction) {}

    bool Dielectric::scatter(const Math::Ray& rin, RayTracer::hitRecord& rec, Math::Color<3>& attenuation, Math::Ray& scattered) {
        attenuation = Math::Color<3>{1.0, 1.0, 1.0};
        double refractionRatio = rec.frontFace ? (1.0 / ir) : ir;

        Math::Vector<3> unitDirection = rin.direction.unitVector();
        double cosTheta = fmin(-unitDirection.dot(rec.normal), 1.0);
        double sinTheta = std::sqrt(1.0 - cosTheta * cosTheta);

        bool cannotRefract = refractionRatio * sinTheta > 1.0;
        Math::Vector<3> direction;

        if (cannotRefract || reflectance(cosTheta, refractionRatio) > Utils::randomDouble()) {
            direction = unitDirection.reflect(rec.normal);
        } else {
            direction = unitDirection.refract(rec.normal, refractionRatio);
        }

        scattered = Math::Ray(rec.p, direction);
        return true;
    }

     double Dielectric::reflectance(double cosine, double refIdx) {
        auto r0 = (1 - refIdx) / (1 + refIdx);
        r0 = r0*r0;
        return r0 + (1-r0)*pow((1 - cosine),5);
    }
}