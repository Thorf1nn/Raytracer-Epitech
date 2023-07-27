/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** YzRect
*/

#ifndef YZRECT_HPP_
#define YZRECT_HPP_

#include "AABB.hpp"
#include "IMaterial.hpp"
#include "APrimitive.hpp"
#include "Math.hpp"
#include "IPrimitive.hpp"
#include "Utils.hpp"

namespace RayTracer {
    class YzRect : public APrimitive {
        public:
            YzRect() {};
            YzRect(double y0, double _y1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> mat);
            ~YzRect();

            virtual bool hits(const Math::Ray& r, double tmin, double tmax, hitRecord& rec) override;
            virtual bool boundingBox(double time0, double time1, AABB& outputBox) const;

            void translate(Math::Vector<3> direction) override {}
            void rotation() override {}

            std::shared_ptr<IMaterial> mp;
            double y0;
            double y1;
            double z0;
            double z1;
            double k;
    };
}

#endif /* !YZRECT_HPP_ */

