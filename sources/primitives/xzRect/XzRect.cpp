/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** XzRect
*/

#include "XzRect.hpp"


namespace RayTracer {

    XzRect::XzRect(double _x0, double _x1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> mat) {
        x0 =_x0; 
        x1 =_x1; 
        z0 =_z0; 
        z1 =_z1; 
        k = _k;
        mp = mat;
    }

    bool XzRect::boundingBox(double time0, double time1, AABB& outputBox) const {
        outputBox = AABB(Math::Vector<3> {x0, k - 0.0001, z0}, Math::Point<3> {x1, k + 0.0001, z1});
        return true;
    }

    bool XzRect::hits(const Math::Ray& r, double tmin, double tmax, hitRecord& rec) {
        auto t = (k - r.origin._points[1]) / r.direction._points[1];
        if (t < tmin || t > tmax)
            return false;
        auto x = r.origin._points[0] + t * r.direction._points[0];
        auto z = r.origin._points[2] + t * r.direction._points[2];
        if (x < x0 || x > x1 || z < z0 || z > z1)
            return false;
        rec.u = (x - x0) / (x1 - x0);
        rec.v = (z - z0) / (z1 - z0);
        rec.t = t;
        auto outwardNormal = Math::Vector<3> {0.0, 1.0, 0.0};
        rec.setFaceNormal(r, outwardNormal);
        rec.matPtr = mp;
        rec.p = r.at(t);
        return true;
    }

    XzRect::~XzRect() {
    }
}
