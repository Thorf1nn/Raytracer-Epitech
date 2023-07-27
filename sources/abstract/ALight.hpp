/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
** File description:
** ALight
*/

#ifndef ALight_HPP_
#define ALight_HPP_

#include "../interfaces/ILight.hpp"

namespace Scene {
    class ALight : ILight {
        public:
            ALight();
            ALight(Math::Vector<3> vec);
            ~ALight();

        protected:
            Math::Vector<3> _position;
    };
}

#endif /* !ALight_HPP_ */
