// Main camera that looks into our scene
// Position: in a Point3f
// Direction: yaw-angle (horizontal), pitch-angle (vertical)
#pragma once
#include "vec3.h"

class Camera {
   public:
    Camera(Point3 position, float yaw, float pitch);

   private:
    Point3 position{0};
    float yaw{0};
    float pitch{0};
};