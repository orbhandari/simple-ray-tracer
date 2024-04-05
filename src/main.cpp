#include <iostream>
int main() {
    const int IMAGE_WIDTH{256};
    const int IMAGE_HEIGHT{256};
    std::cout << "P3\n"
              << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << '\n'
              << "255" << std::endl;

    // Ray tracing algorithm, while building the PPM image at the same time
    for (int j = 0; j < IMAGE_HEIGHT; ++j) {
        std::clog << "\rScanlines remaining: " << (IMAGE_HEIGHT - j) << ' ' << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; ++i) {
            // Create new ray
            // Call rayIntersect
            // Let ir, ig, ib = 1/d, where d = distance travelled by ray to intersection point
            // 0 if no intersection

            int ir = 152;
            int ig = 125;
            int ib = 109;

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::clog << "\rDone.                 \n";
    return 0;
}