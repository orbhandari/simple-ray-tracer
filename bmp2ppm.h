/*
    Parses a .BMP file into a .PPM file.
    BMP files are easier to parse compared with modern, compressed formats such as .PNG or .JPEG.
    Wikipedia reference: https://en.wikipedia.org/wiki/BMP_file_format#:~:text=The%20BMP%20file%20format%20or,Internet%20media%20type
*/

#include <iostream>
#include <cstdint>

/*
Note: the uint8_t, uint16_t, ... types are to define FIXED bit sizes, since they may differ across machines and compilers.
See "Bitmap file header" section in https://en.wikipedia.org/wiki/BMP_file_format.
*/
#pragma pack(push, 1)
struct BMPFileHeader {
    uint16_t file_type{0x4D42}; /* Always BM */
    uint32_t file_size{0};      /* Size of BMP file in bytes */
    uint16_t reserved1{0};
    uint16_t reserved2{0};
    uint32_t offset{0}; /* Starting address of the byte for pixel array s*/
};
#pragma pack(pop)

class BMP2PPM {
    /*
    This loader can process BMP images with 4 regions. Wikipedia may show other regions, but they are optional.
    - Bitmap file header
    - DIB header
    - Color table
    - Pixel array
    */
};
