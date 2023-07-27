#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_IPrimitive_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_IPrimitive_HPP

#include "Math.hpp"
#include "IMaterial.hpp"
#include "AABB.hpp"

namespace RayTracer {
    class IMaterial;
}

namespace RayTracer {
    struct hitRecord {
        Math::Point<3> p;
        Math::Vector<3> normal;
        double t;
        double u;
        double v;
        bool frontFace;
        std::shared_ptr<RayTracer::IMaterial> matPtr;

        inline void setFaceNormal(const Math::Ray& r, const Math::Vector<3>& outwardNormal) {
            frontFace = r.direction.dot(outwardNormal) < 0;
            normal = frontFace ? outwardNormal : -outwardNormal;
        }
    };

    class IPrimitive {
    public:
        virtual ~IPrimitive() = default;

        virtual bool hits(const Math::Ray& r, double Tmin, double Tmax, RayTracer::hitRecord& rec) = 0;
        virtual bool boundingBox(double time0, double time1, AABB& outputBox) const = 0;
        virtual void translate(Math::Vector<3> direction) = 0;
        virtual void rotation() = 0;
    };
}

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_IPrimitive_HPP