/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** AABB
*/

#ifndef AABB_HPP_
#define AABB_HPP_

#include "Math.hpp"

class AABB {
    public:
    public:
        AABB() {}
        AABB(const Math::Vector<3>& a, const Math::Vector<3>& b) {minimum = a; maximum = b;}
        ~AABB() {};

        Math::Vector<3> min() const {return minimum; }
        Math::Vector<3> max() const {return maximum; }

        bool hit(const Math::Ray& r, double tmin, double tmax) const {
            for (int a = 0; a < 3; a++) {
                auto t0 = fmin((minimum._points[a] - r.origin._points[a]) / r.direction._points[a],
                               (maximum._points[a] - r.origin._points[a]) / r.direction._points[a]);
                auto t1 = fmax((minimum._points[a] - r.origin._points[a]) / r.direction._points[a],
                               (maximum._points[a] - r.origin._points[a]) / r.direction._points[a]);
                tmin = fmax(t0, tmin);
                tmax = fmin(t1, tmax);
                if (tmax <= tmin)
                    return false;
            }
            return true;
        }

        //METHOD 2 :
    //     inline bool aabb::hit(const ray& r, double t_min, double t_max) const {
    //          for (int a = 0; a < 3; a++) {
    //     auto invD = 1.0f / r.direction()[a];
    //     auto t0 = (min()[a] - r.origin()[a]) * invD;
    //     auto t1 = (max()[a] - r.origin()[a]) * invD;
    //     if (invD < 0.0f)
    //         std::swap(t0, t1);
    //     t_min = t0 > t_min ? t0 : t_min;
    //     t_max = t1 < t_max ? t1 : t_max;
    //     if (t_max <= t_min)
    //         return false;
    // }
    // return true;}

        Math::Vector<3> minimum;
        Math::Vector<3> maximum;
};


#endif /* !AABB_HPP_ */
