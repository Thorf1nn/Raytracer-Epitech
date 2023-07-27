/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** SolidColor
*/

#ifndef SOLIDCOLOR_HPP_
#define SOLIDCOLOR_HPP_

#include "../../math/Math.hpp"
#include"../../interfaces/ITexture.hpp"

namespace RayTracer {
    class SolidColor : public ITexture {
        public:
            explicit SolidColor(Math::Color<3> c) : colorValue(c) {};
            ~SolidColor() override = default;

            Math::Color<3> value(double u, double v, const Math::Vector<3>& p) const override {
                return colorValue;
            }

        private:
            Math::Color<3> colorValue;
    };
}

#endif /* !SOLIDCOLOR_HPP_ */
