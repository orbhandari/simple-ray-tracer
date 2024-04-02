// Simulate a ray, which is a direction vector from the camera to the scene
#include <vec3.h>

class Ray {
    // r = o + td
   public:
   private:
    Vec3 o;   // origin
    float t;  // scalar multiple
    Vec3 d;   // direction
};