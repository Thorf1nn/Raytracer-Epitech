/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** APrimitive
*/

#include "APrimitive.hpp"

namespace RayTracer {
    void APrimitive::add(const std::shared_ptr<IPrimitive> &object) {
        _objects.push_back(object);
    }

    void APrimitive::clear() {
        _objects.clear();
    }

    bool APrimitive::hits(const Math::Ray& r, double tmin, double tmax, hitRecord& rec) {
        hitRecord tempRec;
        bool hitAnything = false;
        auto closestSoFar = tmax;

        for (const auto& object : _objects) {
            if (object->hits(r, tmin, closestSoFar, tempRec)) {
                hitAnything = true;
                closestSoFar = tempRec.t;
                rec = tempRec;
            }
        }
        return hitAnything;
    }
}