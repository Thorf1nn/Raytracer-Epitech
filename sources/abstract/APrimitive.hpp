/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** APrimitive
*/

#ifndef APrimitive_HPP_
#define APrimitive_HPP_
#include "Math.hpp"
#include "IPrimitive.hpp"
#include "AABB.hpp"
#include <utility>
#include <vector>

namespace RayTracer {
    class APrimitive : public IPrimitive {
    public:
//        explicit APrimitive(std::shared_ptr<IPrimitive> object) {
//            add(object);
//        };

        void clear();
        void add(const std::shared_ptr<IPrimitive>& object);

        bool hits(const Math::Ray& r, double tmin, double tmax, hitRecord& rec) override;
        bool boundingBox(double time0, double time1, AABB& outputBox) const override {}
        void translate(Math::Vector<3> direction) override {}
        void rotation() override {}

    private:
        std::vector<std::shared_ptr<IPrimitive>> _objects;
    };

}


#endif /* !APrimitive_HPP_ */