#include <iostream>

#include "color.h"
#include "ray.h"
#include "vec3.h"

Vec3 trace(const Ray& r) {
    Vec3 direction_vector = r.d.normalized();
    auto a{0.5 * (direction_vector.y() + 1.0)};
    return (1.0 - a) * Color3(1.0, 1.0, 1.0) + a * Color3(0.5, 0.7, 1.0);
}

int main() {
    // We only set IMAGE_WIDTH, while IMAGE_HEIGHT is implied by ASPECT_RATIO.
    int IMAGE_WIDTH{400};
    float ASPECT_RATIO{16.0 / 9.0};

    int IMAGE_HEIGHT{static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO)};  // We don't want 0 height images, make it at least 1.
    IMAGE_HEIGHT = IMAGE_HEIGHT >= 1 ? IMAGE_HEIGHT : IMAGE_WIDTH;

    // The following code is essentially given by "Ray Tracing in a Weekend" series.
    // Define camera and viewport (virtual image plane of our 3D scene, should have same aspect ratio as defined before).
    float focal_length{1.0};
    float viewport_height{2.0};  // Choice of 2.0 was arbitrary.
    float viewport_width{viewport_height * static_cast<float>(IMAGE_WIDTH) / IMAGE_HEIGHT};
    Point3 camera_center = Point3{0, 0, 0};

    Vec3 viewport_u{Vec3{viewport_width, 0, 0}};
    Vec3 viewport_v{Vec3{0, -viewport_height, 0}};

    Vec3 px_delta_u{viewport_u / IMAGE_WIDTH};
    Vec3 px_delta_v{viewport_v / IMAGE_HEIGHT};

    // Find (virtual) center of a pixel.
    Vec3 viewport_upper_left{Vec3(0, 0, focal_length) + (-viewport_u / 2) + (-viewport_v / 2)};
    Vec3 pixel_00_location{viewport_upper_left + 0.5 * (px_delta_u + px_delta_v)};

    // Preamble of a .PPM image.
    std::cout
        << "P3\n"
        << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << '\n'
        << "255" << std::endl;

    // Ray tracing algorithm, while building the PPM image at the same time.
    for (int j = 0; j < IMAGE_HEIGHT; ++j) {
        std::clog << "\rScanlines remaining: " << (IMAGE_HEIGHT - j) << ' ' << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; ++i) {
            // Create new ray
            // Call rayIntersect
            // Let ir, ig, ib = 1/d, where d = distance travelled by ray to intersection point
            // 0 if no intersection

            Vec3 rayDirection{pixel_00_location + (i * px_delta_u) + (j * px_delta_v)};
            Ray ray{camera_center, rayDirection};

            Color3 color = trace(ray);
            writeColor(std::cout, color);

            // std::cout << static_cast<int>(color.x() * 255.999) << ' ' << static_cast<int>(color.y() * 255.999) << ' ' << static_cast<int>(color.z() * 255.999) << '\n';
        }
    }

    std::clog << "\rDone.                 \n";
    return 0;
}