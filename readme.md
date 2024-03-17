# Minimal ray tracer program in C++
# References
Bitmap images: 

# Notes
## Bitmap images
Bitmap images are stored as a grid of pixels. Suppose we have a $24$-bit bitmap file. Each pixel is thus represented by $24/8=3$ bytes, each byte corresponding to a red, green or blue color value. Since each byte has $8$ bits, each color channel will have $2^8=256$ possible colors (more specifically, each channel's range is $[0,255]$). 

We can visualize a bitmap file in hexadecimal in the terminal by running the following command:
```xxd <filename>.bmp```

Note that the data is stored in *little endian*. Moreover, note that since we are in hex, each hex digit represents $4$ bits, i.e. half a byte, hence $2$ hex digits represents $8$ bits, i.e. $1$ full byte. 

Bitmap images, while simple to understand, are large in size. This is why other image formats exist, such as PNG or JPEG. 