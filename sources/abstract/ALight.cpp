/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** ALight
*/

#include "ALight.hpp"

namespace Scene
{
    ALight::ALight()
    {
        _position = Math::Vector<3>{0.0, 0.0, 0.0};
    }

    ALight::ALight(Math::Vector<3> vec)
    {
        _position = vec;
    }

    ALight::~ALight()
    {
    }
}