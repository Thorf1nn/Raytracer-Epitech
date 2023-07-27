/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** XyRect
*/

#ifndef XYRECT_HPP_
#define XYRECT_HPP_

#include "AABB.hpp"
#include "IMaterial.hpp"
#include "APrimitive.hpp"
#include "Math.hpp"
#include "IPrimitive.hpp"
#include "Utils.hpp"

namespace RayTracer {
    class XyRect : public APrimitive {
        public:
            XyRect() {};
            XyRect(double _x0, double _x1, double _y0, double _y1, double _k,
                std::shared_ptr<IMaterial> mat)
                : x0(_x0), x1(_x1), y0(_y0), y1(_y1), k(_k), mp(mat) {};
            ~XyRect();

            bool hits(const Math::Ray& r, double tmin, double tmax, hitRecord& rec) override;
            void translate(Math::Vector<3> direction) override {}
            void rotation() override {}


            virtual bool boundingBox(double time0, double time1, AABB& outputBox) const override {
                outputBox = AABB(Math::Vector<3> {x0,y0, k-0.0001}, Math::Point<3> {x1, y1, k + 0.0001});
                return true;
            }

            std::shared_ptr<IMaterial> mp;
            double x0;
            double x1;
            double y0;
            double y1;
            double k;
    };
}

#endif /* !XYRECT_HPP_ */
