/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** Box
*/

#include "Box.hpp"

namespace Primitive {
    bool Box::boundingBox(double time0, double time1, AABB& outputBox) const {
        outputBox = AABB(boxMin, boxMax);
        return true;
    }

    Box::Box(const Math::Point<3> & p0, const Math::Point<3> & p1, std::shared_ptr<RayTracer::IMaterial> ptr) {
        boxMin = p0;
        boxMax = p1;

        sides->add(std::make_shared<RayTracer::XyRect>(p0._points[0], p1._points[0], p0._points[1], p1._points[1], p1._points[2], ptr));
        sides->add(std::make_shared<RayTracer::XyRect>(p0._points[0], p1._points[0], p0._points[1], p1._points[1], p0._points[2], ptr));

        sides->add(std::make_shared<RayTracer::XzRect>(p0._points[0], p1._points[0], p0._points[2], p1._points[2], p1._points[1], ptr));
        sides->add(std::make_shared<RayTracer::XzRect>(p0._points[0], p1._points[0], p0._points[2], p1._points[2], p0._points[1], ptr));

        sides->add(std::make_shared<RayTracer::YzRect>(p0._points[1], p1._points[1], p0._points[2], p1._points[2], p1._points[0], ptr));
        sides->add(std::make_shared<RayTracer::YzRect>(p0._points[1], p1._points[1], p0._points[2], p1._points[2], p0._points[0], ptr));
    }

    bool Box::hits(const Math::Ray& r, double tmin, double tmax, RayTracer::hitRecord& rec) {
        return sides->hits(r, tmin, tmax, rec);
    }


}