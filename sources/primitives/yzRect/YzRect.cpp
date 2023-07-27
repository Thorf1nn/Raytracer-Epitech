/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** YzRect
*/

#include "YzRect.hpp"

namespace RayTracer {
    YzRect::YzRect(double _y0, double _y1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> mat) {
        y0 =_y0; 
        y1 =_y1; 
        z0 =_z0; 
        z1 =_z1; 
        k = _k;
        mp = mat;
    }

    bool YzRect::boundingBox(double time0, double time1, AABB& outputBox) const {
        outputBox = AABB(Math::Vector<3> {k - 0.0001, y0, z0}, Math::Point<3> {k + 0.0001, y1, z1});
        return true;
    }

    bool YzRect::hits(const Math::Ray& r, double tmin, double tmax, hitRecord& rec) {
        auto t = (k - r.origin._points[0]) / r.direction._points[0];
        if (t < tmin || t > tmax)
            return false;
        auto y = r.origin._points[1] + t * r.direction._points[1];
        auto z = r.origin._points[2] + t * r.direction._points[2];
        if (y < y0 || y > y1 || z < z0 || z > z1)
            return false;
        rec.u = (y - y0) / (y1 - y0);
        rec.v = (z - z0) / (z1 - z0);
        rec.t = t;
        auto outwardNormal = Math::Vector<3> {1.0, 0.0, 0.0};
        rec.setFaceNormal(r, outwardNormal);
        rec.matPtr = mp;
        rec.p = r.at(t);
        return true;
    }
    
    YzRect::~YzRect() {
    }
}
