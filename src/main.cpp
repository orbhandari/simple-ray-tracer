#include <iostream>
int main() {
    const int IMAGE_WIDTH{256};
    const int IMAGE_HEIGHT{256};

    // Ray tracing algorithm, while building the PPM image at the same time
    for (int j = 0; j < IMAGE_HEIGHT; ++j) {
        std::clog << "\rScanlines remaining: " << (IMAGE_HEIGHT - j) << ' ' << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; ++i) {
            // auto r = double(i) / (IMAGE_WIDTH - 1);
            // auto g = double(j) / (IMAGE_HEIGHT - 1);
            // auto b = 0;

            // int ir = static_cast<int>(255.999 * r);
            // int ig = static_cast<int>(255.999 * g);
            // int ib = static_cast<int>(255.999 * b);

            int ir = 0;
            int ig = 0;
            int ib = 0;

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::clog << "\rDone.                 \n";
    return 0;
}