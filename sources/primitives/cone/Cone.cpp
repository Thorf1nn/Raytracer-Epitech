/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Cone
*/

#include "Cone.hpp"

namespace Primitive {
    Cone::Cone(Math::Point<3> center, double radius, double width) :
        _center(center), _radius(radius), _width(width)
    {
    }

    Cone::Cone(Math::Point<3> center, double radius, double width, std::shared_ptr<RayTracer::IMaterial> mat) :
        _center(center), _radius(radius), _width(width), _matPtr(mat)
    {
    }
    
    void Cone::translate(Math::Vector<3> direction) {
        _center += direction;
    }

    void Cone::getConeUv(const Math::Point<3>& p, double& u, double& v)
    {
        auto theta = acos(-p._points[1]);
        auto phi = atan2(-p._points[2], p._points[0]) + Math::pi;

        u = phi / (2 * Math::pi);
        v = theta / Math::pi;
    }

    bool Cone::hits(const Math::Ray& r, double tMin, double tMax, RayTracer::hitRecord& rec)
    {
        Math::Vector<3> oc = r.origin - _center;
        double A = oc._points[0] - _center._points[0];
        double B = oc._points[2] - _center._points[2];
        double D = _width - oc._points[1] + _center._points[1];

        double tan = (_radius / _width) * (_radius / _width);

        double a = (r.direction._points[0] * r.direction._points[0]) + (r.direction._points[2] * r.direction._points[2]) - (tan*(r.direction._points[1] * r.direction._points[1]));
        double b = (2*A*r.direction._points[0]) + (2*B*r.direction._points[2]) + (2*tan*D*r.direction._points[1]);
        double c = (A*A) + (B*B) - (tan*(D*D));

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
        getConeUv(outwardNormal, rec.u, rec.v);
        rec.matPtr = _matPtr;

        return true;
    }

    bool Cone::boundingBox(double time0, double time1, AABB& outputBox) const {
        outputBox = AABB(_center - Math::Vector<3>{_radius, _width, _radius}, _center + Math::Vector<3>{_radius, _width, _radius});
        return true;
    }
}
