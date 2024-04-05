// Simulate a ray, which is a direction vector from the camera to the scene
#pragma once
#include <limits>

#include "vec3.h"

class Ray {
    // r = o + td
   public:
    Ray() = default;
    Ray(Point3 origin, Vec3 direction) : o{origin}, d{direction} {};
    float getDistance() {
        Vec3 p = o + t * d;
        return p.norm();
    }

    //    private:
    Point3 o{0};                                      // origin
    float t{std::numeric_limits<float>::infinity()};  // scalar multiple
    Vec3 d{0};                                        // direction
};