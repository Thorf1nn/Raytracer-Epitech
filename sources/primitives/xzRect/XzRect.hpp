/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** XzRect
*/

#ifndef XZRECT_HPP_
#define XZRECT_HPP_

#include "AABB.hpp"
#include "IMaterial.hpp"
#include "APrimitive.hpp"
#include "Math.hpp"
#include "IPrimitive.hpp"
#include "Utils.hpp"

namespace RayTracer {
    class XzRect : public APrimitive {
        public:
            XzRect() {};
            XzRect(double _x0, double _x1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> mat);
            ~XzRect();

            virtual bool hits(const Math::Ray& r, double tmin, double tmax, hitRecord& rec) override;
            virtual bool boundingBox(double time0, double time1, AABB& outputBox) const;

            void translate(Math::Vector<3> direction) override {}
            void rotation() override {}


            std::shared_ptr<IMaterial> mp;
            double x0;
            double x1;
            double z0;
            double z1;
            double k;
    };
}

#endif /* !XZRECT_HPP_ */
