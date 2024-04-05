#include "include/triangle.h"

Triangle::Triangle(Vec3 t1, Vec3 t2, Vec3 t3) : t1(t1), t2(t2), t3(t3) {
    // Calculate the (general) plane formula associated with the triangle.

    // To find out the normal vector of the plane, first find out the two vectors on the triangle.
    Vec3 a = t1 - t2;
    Vec3 b = t1 - t3;

    // Then take the cross product and normalize it to get a unit normal.
    n = a.cross(b).normalized();
    n = -1 * n;  // Define such a direction as the correct direction, based on t1,t2,t3.

    float p = n.x();
    float q = n.y();
    float r = n.z();

    // Clearly, t1 is a point on the plane, so we can now find out d.
    float d = p * t1.x() + q * t1.y() + r * t1.z();
    // We now have sufficient information to completely define the equation of the plane.
    plane[0] = p;
    plane[1] = q;
    plane[2] = r;
    plane[3] = d;
}

bool Triangle::isInsideTriangle(Vec3 p) {
    // Assumes p is already on the plane of the triangle.
    // Then, we perform the "inside-outside test.
    // e stands for edge.

    // ((t2 - t1).cross(p - t1)).dot(n)

    

    // return 


}