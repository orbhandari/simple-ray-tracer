// A triangle primitive (shape) to define all our objects
// Each triangle is characterised by {t1,t2,t3}, where each ti is a vec3 coordinate
// Plane of triangle?
#include <vec3.h>

#include <vector>

class Triangle {
   public:
    Triangle(Vec3 t1, Vec3 t2, Vec3 t3);

    ~Triangle(){};

    bool isInsideTriangle(Vec3 p);

   private:
    Vec3 t1{0};
    Vec3 t2{0};
    Vec3 t3{0};
    std::vector<float> plane{0, 0, 0, 0};
    Vec3 n{0};  // Unit normal vector
};
