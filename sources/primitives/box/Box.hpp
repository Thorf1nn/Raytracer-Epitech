/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "IMaterial.hpp"
#include "IPrimitive.hpp"
#include "Math.hpp"
#include "Ray.hpp"
#include "AABB.hpp"
#include "IMaterial.hpp"
#include "xyRect/XyRect.hpp"
#include "yzRect/YzRect.hpp"
#include "xzRect/XzRect.hpp"

namespace Primitive {
    class Box : public RayTracer::APrimitive {
        public:
            Box() {}
            virtual bool boundingBox(double time0, double time1, AABB& outputBox) const;
            Box(const Math::Point<3> & p0, const Math::Point<3>& p1, std::shared_ptr<RayTracer::IMaterial> ptr);
            bool hits(const Math::Ray& r, double tmin, double tmax, RayTracer::hitRecord& rec);
            void translate(Math::Vector<3> direction) override {}
            void rotation() override {}

        public:
            Math::Point<3> boxMin;
            Math::Point<3> boxMax;
            std::shared_ptr<RayTracer::APrimitive> sides;
    };
}


#endif /* !BOX_HPP_ */
