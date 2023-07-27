#ifndef B_OOP_400_MPL_4_1_BSRAYTRACER_HUGO_ESCHLIMANN_Vector_HPP
#define B_OOP_400_MPL_4_1_BSRAYTRACER_HUGO_ESCHLIMANN_Vector_HPP

#include <iostream>
#include <array>
#include <cstdarg>
#include <cmath>
#include <limits>
#include <memory>
#include <random>

namespace Math {
    template <std::size_t N>
    class Vector {
    public:
        std::array<double, N> _points;

        bool nearZero() const {
            const auto s = 1e-8;
    
            return (fabs(_points[0]) < s) && (fabs(_points[1]) < s) && (fabs(_points[2]) < s);
        }

        Vector() : _points{0} {}

        explicit Vector(std::initializer_list<double> list) {
            std::size_t i = 0;
            for (auto it = list.begin(); it != list.end() && i < N; ++it, ++i) {
                _points[i] = *it;
            }
        }

        Vector operator-() const {
            Vector v;
            for (std::size_t i = 0; i < N; i++)
                v._points[i] = -_points[i];
            return v;
        }

        Vector operator-(const Vector& v) const {
            Vector tmp;
            for (std::size_t i = 0; i < N; i++) {
                tmp._points[i] = _points[i] - v._points[i];
            }
            return tmp;
        }
    
        Vector operator+(const Vector& v) const {
            Vector vector;
            for (std::size_t i = 0; i < N; i++) {
                vector._points[i] = _points[i] + v._points[i];
            }
            return vector;
        }

        Vector& operator+=(const Vector &v) {
            for (std::size_t i = 0; i < N; i++)
                _points[i] += v._points[i];
            return *this;
        }

        Vector operator*(const Vector& v) const {
            Vector vector;
            for (std::size_t i = 0; i < N; i++) {
                vector._points[i] = _points[i] * v._points[i];
            }
            return vector;
        }

        Vector operator*(const double t) const {
            Vector tmp;
            for (std::size_t i = 0; i < N; i++) {
                tmp._points[i] = _points[i] * t;
            }
            return tmp;
        }
        
        Vector& operator*=(const double t) {
            for (std::size_t i = 0; i < N; i++)
                _points[i] *= t;
            return *this;
        }

        Vector operator/(double t) const {
            return Vector{_points[0] / t, _points[1] / t, _points[2] / t};
        }

        Vector& operator/=(const double t) {
            return *this *= 1 / t;
        }

        double length() const {
            return std::sqrt(lengthSquared());
        }

        double lengthSquared() const {
            double length = 0;
            for (std::size_t i = 0; i < N; i++)
                length += _points[i] * _points[i];
            return length;
        }

        double dot(const Vector& other) const {
            double product = 0;
            for (std::size_t i = 0; i < N; i++) {
                product += _points[i] * other._points[i];
            }
            return product;
        }

        Vector unitVector() const {
            return (*this) / length();
        }

        Vector refract(const Vector& n, double etaiOverEtat) {
            auto cosTheta = fmin(-this->dot(n), 1.0);
            Vector<3> rOutPerp = (*this + n * cosTheta) * etaiOverEtat;
            Vector<3> rOutParallel = n * -std::sqrt(fabs(1.0 - rOutPerp.lengthSquared()));
            return rOutPerp + rOutParallel;
        }

        Vector reflect(const Vector& n) {
            return *this - n * (2 * this->dot(n));
        }

        Vector cross(const Vector& v) {
            Vector vector;
            vector._points[0] = _points[1] * v._points[2] - _points[2] * v._points[1];
            vector._points[1] = _points[2] * v._points[0] - _points[0] * v._points[2];
            vector._points[2] = _points[0] * v._points[1] - _points[1] * v._points[0];
            return vector;
        }
    };

    template <std::size_t N>
    using Point = Vector<N>;

    template <std::size_t N>
    using Color = Vector<N>;

    template <std::size_t N>
    std::ostream &operator<<(std::ostream &os, const Vector<N> &vector) {
        os << "Vector" << N << "D(";
        for (std::size_t i = 0; i < N; i++) {
            os << vector._points[i];
            if (i != N - 1)
                os << ", ";
        }
        return os;
    }
}

#endif //B_OOP_400_MPL_4_1_BSRAYTRACER_HUGO_ESCHLIMANN_Vector_HPP