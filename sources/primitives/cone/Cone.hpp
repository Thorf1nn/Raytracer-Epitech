/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Cone
*/

#ifndef CONE_HPP_
#define CONE_HPP_

#include "IMaterial.hpp"
#include "IPrimitive.hpp"
#include "Math.hpp"
#include "Ray.hpp"
#include "AABB.hpp"

namespace Primitive
{   
    class Cone : public RayTracer::IPrimitive {
        public:
            Cone() = default;
            Cone(Math::Point<3> center, double radius, double width);
            Cone(Math::Point<3> center, double radius, double width, std::shared_ptr<RayTracer::IMaterial> mat);

            static void getConeUv(const Math::Point<3>& p, double& u, double& v);
            virtual bool hits(const Math::Ray& r, double tMin, double tMax, RayTracer::hitRecord& rec) override;
            virtual bool boundingBox(double time0, double time1, AABB& outputBox) const;

            void translate(Math::Vector<3> direction) override;
            void rotation() override {}
            ~Cone() = default;

        private:
            Math::Point<3> _center;
            double _radius;
            double _width;
            std::shared_ptr<RayTracer::IMaterial> _matPtr;
        };
} // namespace Primitive


#endif /* !CONE_HPP_ */
