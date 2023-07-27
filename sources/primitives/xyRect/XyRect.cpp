/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** XyRect
*/

#include "XyRect.hpp"

namespace RayTracer {
    bool XyRect::hits(const Math::Ray& r, double tmin, double tmax, hitRecord& rec) {
        auto t = (k - r.origin._points[2]) / r.direction._points[2];
        if (t < tmin || t > tmax)
            return false;
        auto x = r.origin._points[0] + t * r.direction._points[0];
        auto y = r.origin._points[1] + t * r.direction._points[1];
        if (x < x0 || x > x1 || y < y0 || y > y1)
            return false;
        rec.u = (x-x0)/(x1-x0);
        rec.v = (y-y0)/(y1-y0);
        rec.t = t;
        auto outwardNormal = Math::Vector<3> {0.0, 0.0, 1.0};
        rec.setFaceNormal(r, outwardNormal);
        rec.matPtr = mp;
        rec.p = r.at(t);
        return true;
    }

    XyRect::~XyRect()
    {
    }
}
