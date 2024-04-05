// Simulate a ray, which is a direction vector from the camera to the scene
#pragma once
#include "vec3.h"

class Ray {
    // r = o + td
   public:
    Ray() = default;
    Ray(Point3 origin, Vec3 direction) : o{origin}, t{0}, d{direction} {};

    //    private:
    Point3 o{0};  // origin
    float t{0};   // scalar multiple
    Vec3 d{0};    // direction
};