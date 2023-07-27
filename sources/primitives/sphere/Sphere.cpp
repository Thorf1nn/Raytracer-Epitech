/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Sphere
*/

#include "Sphere.hpp"

namespace Primitive {
    Sphere::Sphere(Math::Point<3> center, double radius)
        : center(center), radius(radius) {}

    Sphere::Sphere(Math::Point<3> c, double r, std::shared_ptr<RayTracer::IMaterial> mat) :
        center(c), radius(r), matPtr(mat) {};

    void Sphere::translate(Math::Vector<3> direction) {
        center += direction;
    }

    void Sphere::getSphereUv(const Math::Point<3>& p, double& u, double& v) {

        auto theta = acos(-p._points[1]);
        auto phi = atan2(-p._points[2], p._points[0]) + Math::pi;

        u = phi / (2 * Math::pi);
        v = theta / Math::pi;
    }

    bool Sphere::hits(const Math::Ray &r, double Tmin, double Tmax, RayTracer::hitRecord &rec) {
        Math::Vector<3> oc = r.origin - center;
        auto a = r.direction.lengthSquared();
        auto b = oc.dot(r.direction);
        auto c = oc.lengthSquared() - radius * radius;

        auto discriminant = b * b - a * c;
        if (discriminant < 0) return false;
        auto sqrtd = std::sqrt(discriminant);

        auto root = (-b - sqrtd) / a;
        if (root < Tmin || Tmax < root) {
            root = (-b + sqrtd) / a;
            if (root < Tmin || Tmax < root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        Math::Vector<3> outwardNormal = (rec.p - center) / radius;
        rec.setFaceNormal(r, outwardNormal);
        getSphereUv(outwardNormal, rec.u, rec.v);
        rec.matPtr = matPtr;

        return true;
    }

    bool Sphere::boundingBox(double time0, double time1, AABB& outputBox) const {
        outputBox = AABB{
            center - Math::Vector<3> {radius, radius, radius},
            center + Math::Vector<3> {radius, radius, radius}};
    return true;
    }
}