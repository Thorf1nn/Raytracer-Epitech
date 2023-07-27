/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Metal
*/

#ifndef METAL_HPP_
#define METAL_HPP_

#include "AMaterial.hpp"
#include "Math.hpp"
#include "IPrimitive.hpp"
#include "../utils/Utils.hpp"

namespace RayTracer {
    class Metal : public AMaterial {
    public:
        Metal(const Math::Color<3>& a, double f);
        ~Metal() override = default;

        bool scatter(const Math::Ray& rin, RayTracer::hitRecord& rec, Math::Color<3>& attenuation, Math::Ray& scattered) override;

        Math::Color<3> albedo;
        double fuzz;
    };
}

#endif /* !METAL_HPP_ */
