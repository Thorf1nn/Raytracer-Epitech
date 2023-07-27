#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_CYLINDER_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_CYLINDER_HPP

#include "IMaterial.hpp"
#include "IPrimitive.hpp"
#include "Math.hpp"
#include "Ray.hpp"
#include "AABB.hpp"

namespace Primitive {
    class Cylinder : public RayTracer::IPrimitive {
    public:
        Cylinder() = default;
        Cylinder(Math::Point<3> center, double radius, double width);
        Cylinder(Math::Point<3> center, double radius, double width, std::shared_ptr<RayTracer::IMaterial> mat);
        ~Cylinder() = default;

        static void getCylinderUv(const Math::Point<3>& p, double& u, double& v);
        virtual bool hits(const Math::Ray& r, double tMin, double tMax, RayTracer::hitRecord& rec) override;
        virtual bool boundingBox(double time0, double time1, AABB& outputBox) const;

        void translate(Math::Vector<3> direction) override {
            _center += direction;
        }
        void rotation() override {}


    private:
        Math::Point<3> _center;
        double _radius;
        double _width;
        std::shared_ptr<RayTracer::IMaterial> _matPtr;
    };
} // Primitive

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_CYLINDER_HPP
