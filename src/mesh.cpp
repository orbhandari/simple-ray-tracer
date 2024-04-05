#include "mesh.h"

#include <limits>

#include "vec3.h"

bool Mesh::rayIntersect(Ray& ray) {
    bool foundIntersection{false};
    for (int i = 0; i < triangles.size(); ++i) {
        const std::vector<float>& plane = triangles[i].getPlane();

        Vec3 n{plane[0], plane[1], plane[2]};
        float d{plane[3]};

        // Check if ray is parallel to the plane.
        if (std::abs(n.dot(ray.d)) < 10e-4) {
            return false;
        }

        // Otherwise, it must intersect the plane somewhere.
        float t = (d - n.dot(ray.o)) / n.dot(ray.d);

        // If it intersects behind the camera, it is pointless, we will never see it.
        if (t < 0) {
            return false;
        }

        Vec3 p = ray.o + t * ray.d;
        // std::cout << "p: " << p.x() << ' ' << p.y()  << ' ' << p.z() << '\n';
        if (triangles[i].isInsideTriangle(p)) {
            // std::cout << "Is inside triangle\n";
            // std::cout << "t: " << t << '\n';
            // std::cout << "ray t: " << ray.t << '\n';
            foundIntersection = true;
            if (t < ray.t) {
                ray.t = t;
                // std::cout << "ray t: " << t << '\n';
            }
        }
    }
    return foundIntersection;
}