#include "Cylinder.hpp"

namespace Primitive {
    Cylinder::Cylinder(Math::Point<3> center, double radius, double width) : _center(center), _radius(radius), _width(width) {}

    Cylinder::Cylinder(Math::Point<3> center, double radius, double width, std::shared_ptr<RayTracer::IMaterial> mat) : _center(center), _radius(radius), _width(width), _matPtr(mat) {}

    void Cylinder::getCylinderUv(const Math::Point<3>& p, double& u, double& v) {

        auto theta = acos(-p._points[1]);
        auto phi = atan2(-p._points[2], p._points[0]) + Math::pi;

        u = phi / (2 * Math::pi);
        v = theta / Math::pi;
    }

    bool Cylinder::hits(const Math::Ray& r, double tMin, double tMax, RayTracer::hitRecord& rec) {
        Math::Vector<3> oc = r.origin - _center;
        double a = r.direction._points[0] * r.direction._points[0] + r.direction._points[2] * r.direction._points[2];
        double b = 2 * (oc._points[0] * r.direction._points[0] + oc._points[2] * r.direction._points[2]);
        double c = oc._points[0] * oc._points[0] + oc._points[2] * oc._points[2] - _radius * _radius;

        auto discriminant = b * b - 4 * a * c;
        if (discriminant < 0) return false;

        double sqrtd = std::sqrt(discriminant);
        double root1 = (-b - sqrtd) / (2 * a);
        double root2 = (-b + sqrtd) / (2 * a);

        double root;
        if (root1 < tMin || root1 > tMax) {
            if (root2 < tMin || root2 > tMax) {
                return false;
            } else {
                root = root2;
            }
        } else {
            root = root1;
        }

        Math::Point<3> intersectionPoint = r.at(root);
        Math::Vector<3> normal{intersectionPoint._points[0] - _center._points[0], 0, intersectionPoint._points[2] - _center._points[2]};
        if (normal.lengthSquared() > 0) {
            normal.unitVector();
        }

        double y = intersectionPoint._points[1];
        if (y < 0 || y > _width) return false;

        rec.t = root;
        rec.p = r.at(rec.t);
        Math::Vector<3> outwardNormal = (rec.p - _center) / _radius;
        rec.setFaceNormal(r, outwardNormal);
        getCylinderUv(outwardNormal, rec.u, rec.v);
        rec.matPtr = _matPtr;

        return true;
    }

    bool Cylinder::boundingBox(double time0, double time1, AABB& outputBox) const {
        outputBox = AABB(_center - Math::Vector<3>{_radius, _width, _radius}, _center + Math::Vector<3>{_radius, _width, _radius});
        return true;
    }
} // Primitive