/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** CheckerTexture
*/

#ifndef CHECKERTEXTURE_HPP_
#define CHECKERTEXTURE_HPP_

#include "../../interfaces/ITexture.hpp"
#include "../../math/Math.hpp"
#include "SolidColor.hpp"
#include <memory>


namespace RayTracer {
    class CheckerTexture : public ITexture {
        public:
            virtual ~CheckerTexture() = default;

            CheckerTexture(std::shared_ptr<ITexture> _even, std::shared_ptr<ITexture> _odd)
                : even(_even), odd(_odd) {}

            CheckerTexture(Math::Color<3> c1, Math::Color<3> c2)
                : even(std::make_shared<SolidColor>(c1)), odd(std::make_shared<SolidColor>(c2)) {}

            virtual Math::Color<3> value(double u, double v, const Math::Point<3>& p) const override {
                auto sines = sin(10 * p._points[0]) * sin(10 * p._points[1]) * sin(10 * p._points[2]);
                if (sines < 0)
                    return odd->value(u, v, p);
                else
                    return even->value(u, v, p);
            }

            std::shared_ptr<ITexture> odd;
            std::shared_ptr<ITexture> even;
    };
}

#endif /* !CHECKERTEXTURE_HPP_ */
