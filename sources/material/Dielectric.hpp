/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Dieletric
*/

#ifndef DIELETRIC_HPP_
#define DIELETRIC_HPP_

#include "AMaterial.hpp"
#include "Math.hpp"
#include "IPrimitive.hpp"
#include "Vector.hpp"
#include "../utils/Utils.hpp"
#include "../interfaces/ITexture.hpp"

namespace RayTracer {
    class Dielectric : public AMaterial {
    public:
        explicit Dielectric(double index_of_refraction);
        explicit Dielectric(std::shared_ptr<ITexture>& a, double index_of_refraction);

        bool scatter(const Math::Ray& rin, RayTracer::hitRecord& rec, Math::Color<3>& attenuation, Math::Ray& scattered) override;
        static double reflectance(double cosine, double ref_idx);

    private:
        std::shared_ptr<ITexture> albedo;
        double ir; // Index of Refraction
    };
}

#endif /* !DIELETRIC_HPP_ */
