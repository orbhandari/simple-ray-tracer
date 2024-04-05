#pragma once
#include <iostream>

#include "vec3.h"

using Color3 = Vec3;
void writeColor(std::ostream &out, Color3 pixel_color) {
    // Assumes each component of pixel_color is in the correct range of [0,1].
    out << static_cast<int>(pixel_color.x() * 255.999) << ' '
        << static_cast<int>(pixel_color.y() * 255.999) << ' '
        << static_cast<int>(pixel_color.z() * 255.999) << '\n';
}