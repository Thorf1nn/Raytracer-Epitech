/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** IMaterial
*/

#ifndef IMATERIAL_HPP_
#define IMATERIAL_HPP_

#include "IPrimitive.hpp"
#include "Math.hpp"

struct hitRecord;
namespace RayTracer {
    class IMaterial {
    public:
        virtual ~IMaterial() = default;
        virtual bool scatter(const Math::Ray &rin, hitRecord &rec,Math::Color<3>& attenuation, Math::Ray& scattered) = 0;
        virtual Math::Color<3> emitted(double u, double v, const Math::Point<3>& p) = 0;
    };
}

#endif /* !IMATERIAL_HPP_ */
