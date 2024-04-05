#include "triangle.h"

Triangle::Triangle(Vec3 t1, Vec3 t2, Vec3 t3) : t1(t1), t2(t2), t3(t3) {
    // Calculate the (general) plane formula associated with the triangle.

    // To find out the normal vector of the plane, first find out the two vectors on the triangle.
    Vec3 a = t1 - t2;
    Vec3 b = t1 - t3;

    // Then take the cross product and normalize it to get a unit normal.
    n = a.cross(b).normalized();
    n = -1.0 * n;  // Define such a direction as the correct direction, based on t1,t2,t3.

    float p = n.x();
    float q = n.y();
    float r = n.z();

    // std::cout << n.x() << ' ' << n.y() << ' ' << n.z() << '\n';
    // Clearly, t1 is a point on the plane, so we can now find out d.
    float d = p * t1.x() + q * t1.y() + r * t1.z();
    // We now have sufficient information to completely define the equation of the plane.
    plane[0] = p;
    plane[1] = q;
    plane[2] = r;
    plane[3] = d;
}

bool Triangle::isInsideTriangle(Point3 p) {
    // Assumes p is already on the plane of the triangle.
    // Then, we perform the "inside-outside test.
    // e stands for edge.

    // std::cout << p.x() << '\n';
    // std::cout << (((t2 - t1).cross(p - t1)).dot(n) >= -1 * 10e-4) << '\n';
    // std::cout << (((t3 - t2).cross(p - t2)).dot(n) >= -1 * 10e-4) << '\n';
    // std::cout << (((t1 - t3).cross(p - t3)).dot(n) >= -1 * 10e-4) << '\n';

    // return false;
    // std::cout << n.x() << ' ' << n.y() << ' ' << n.z() << '\n';


    
    // std::cout << "cP1 " << (t2 - t1).cross(p - t1).printVec() << '\n';
    // std::cout << "cP2 " << ((t3 - t2).cross(p - t2)).dot(n) << '\n';
    // std::cout << "cP3 " << ((t1 - t3).cross(p - t3)).dot(n) << '\n';

    return (-((t2 - t1).cross(p - t1)).dot(n) >= -10e-2) &&
           (-((t3 - t2).cross(p - t2)).dot(n) >= -10e-2) &&
           (-((t1 - t3).cross(p - t3)).dot(n) >= -10e-2);
}