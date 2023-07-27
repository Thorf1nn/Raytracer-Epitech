#include "Utils.hpp"

namespace RayTracer {
    void Utils::writeColor(std::ostream& out, Math::Vector<3>& color, int samplesPerPixel) {
        auto r = color._points[0];
        auto g = color._points[1];
        auto b = color._points[2];
        // Divide the color by the number of samples.
        auto scale = 1.0 / samplesPerPixel;
        r = std::sqrt(scale * r);
        g = std::sqrt(scale * g);
        b = std::sqrt(scale * b);

        // Write the translated [0,255] value of each color component.
        out  << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
               << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
               << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
    }

    Math::Vector<3> Utils::rayColor(const Math::Ray& r, const Math::Color<3> &background, RayTracer::IPrimitive &world, int depth) {
        RayTracer::hitRecord rec;

        if (depth <= 0)
            return Math::Color<3>{0.0, 0.0, 0.0};

        if (!world.hits(r, 0.001, Math::infinity, rec))
            return background;

        Math::Ray scattered;
        Math::Color<3> attenuation;
        Math::Color<3> emitted = rec.matPtr->emitted(rec.u, rec.v, rec.p);

        if (!rec.matPtr->scatter(r, rec, attenuation, scattered))
            return emitted;

        return emitted + attenuation * rayColor(scattered, background, world, depth - 1);
        // if (world.hits(r, 0.001, Math::infinity, rec)) {
        //     Math::Ray scattered;
        //     Math::Color<3> attenuation;
        //     if (rec.matPtr->scatter(r, rec, attenuation, scattered))
        //         return attenuation * rayColor(scattered, world, depth - 1);
        //     return Math::Color<3>{0,0,0};
        // }

        // Math::Vector<3> unit_direction = r.direction.unitVector();
        // auto t = 0.5*(unit_direction._points[1] + 1.0);
        // return Math::Color<3>{1.0, 1.0, 1.0}*(1.0-t) + Math::Color<3>{0.5, 0.7, 1.0}*t;
    }

    double Utils::randomDouble() {
        static std::uniform_real_distribution<double> distribution(0.0, 1.0);
        static std::mt19937 generator;
        return distribution(generator);
    }

    double Utils::randomDouble(double min, double max) {
        return min + (max - min) * randomDouble();
    }

    Math::Vector<3> Utils::random() {
        Math::Vector<3> vector;
        for (std::size_t i = 0; i < 3; i++)
            vector._points[i] = randomDouble();
        return vector;
    }

    Math::Vector<3> Utils::random(double min, double max) {
        Math::Vector<3> vector;
        for (std::size_t i = 0; i < 3; i++)
            vector._points[i] = randomDouble(min, max);
        return vector;
    }

     Math::Vector<3> Utils::randomInUnitSphere() {
        while (true) {
            Math::Vector<3> vector = random(-1, 1);
            if (vector.lengthSquared() >= 1)
                continue;
            return vector;
        }
    }

    Math::Vector<3> Utils::randomUnitVector() {
        return randomInUnitSphere().unitVector();
    }

    Math::Vector<3> Utils::randomInHemisphere(const Math::Vector<3>& normal) {
        Math::Vector<3> inUnitSphere = randomInUnitSphere();
        if (inUnitSphere.dot(normal) > 0.0)
            return inUnitSphere;
        else
            return -inUnitSphere;
    }

    Math::Vector<3> Utils::randomInUnitDisk() {
        while (true) {
            Math::Vector<3> vector{randomDouble(-1, 1), randomDouble(-1, 1), 0};
            if (vector.lengthSquared() >= 1)
                continue;
            return vector;
        }
    }

    double Utils::clamp(double x, double min, double max) {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    double Utils::degreesToRadians(double degrees) {
        return degrees * Math::pi / 180.0;
    }

}