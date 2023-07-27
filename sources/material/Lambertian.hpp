/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Lambertian
*/

#ifndef LAMBERTIAN_HPP
#define LAMBERTIAN_HPP_

#include "../interfaces/ITexture.hpp"
#include "texture/SolidColor.hpp"
#include "AMaterial.hpp"
#include "Math.hpp"
#include "../utils/Utils.hpp"

namespace RayTracer {
    class Lambertian : public AMaterial {
    public:
        Lambertian(const Math::Color<3>& a);
        Lambertian(std::shared_ptr<ITexture> a);

        bool scatter (const Math::Ray& rin, RayTracer::hitRecord& rec, Math::Color<3>& attenuation, Math::Ray& scattered) override;
        std::shared_ptr<ITexture> albedo;
    };
}

#endif /* !LAMBERTIAN_HPP_ */
