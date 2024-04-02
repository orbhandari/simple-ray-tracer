// Main camera that looks into our scene
// Position: in a Point3f
// Direction: yaw-angle (horizontal), pitch-angle (vertical)
#include <vec3.h>

class Camera {
   public:
    Camera(Vec3 position, float yaw, float pitch);

   private:
    Vec3 position{0};
    float yaw{0};
    float pitch{0};
};