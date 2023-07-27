#include "AmbientLight.hpp"

namespace Scene {
    bool AmbientLight::scatter(const Math::Ray& rin, RayTracer::hitRecord& rec, Math::Color<3>& attenuation, Math::Ray& scattered) {
        return false;
    }

    Math::Color<3> AmbientLight::emitted(double u, double v, const Math::Point<3>& p) {
        return emit->value(u, v, p);
    }
}
