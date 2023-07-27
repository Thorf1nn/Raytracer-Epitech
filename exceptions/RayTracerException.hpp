#ifndef B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_RAYTRACEREXCEPTION_HPP
#define B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_RAYTRACEREXCEPTION_HPP

#include <iostream>
#include <exception>

namespace RayTracer {
    class RayTracerException : public std::exception {
    public:
        RayTracerException(std::string message) : _message(message) {}
        ~RayTracerException() = default;

        const char *what() const noexcept override {
            return _message.c_str();
        }

    private:
        std::string _message;
    };
} // RayTracer

#endif //B_OOP_400_MPL_4_1_RAYTRACER_THIBAULT_BERNUZ_RAYTRACEREXCEPTION_HPP
