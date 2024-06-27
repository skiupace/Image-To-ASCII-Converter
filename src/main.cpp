#include <iostream>
#include <cstring>

#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb_image.hpp"

int main(int argc, char** argv) {

    const char density[] = "Ñ@#W$9876543210?!abc;:+=-,._              ";
    const unsigned short density_len = strlen(density);

    int width, height, pixel_size;
    unsigned char* image_data = stbi_load(argv[1], &width, &height, &pixel_size, 0);

    if (image_data) {
        unsigned char* pixels = image_data;
        for (int row_index = 0; row_index < height; ++row_index) {
            for (int column_index = 0; column_index < width; ++column_index) {
                const unsigned char r = *pixels++;
                const unsigned char g = *pixels++;
                const unsigned char b = *pixels++;

                if (pixel_size >= 4)
                    const unsigned char a = *pixels++;

                const float average = (r + g + b) / 3.0f;
                const int density_index = static_cast<int>(density_len * (average / 255.0f));
                putchar(density[density_index]);
            } putchar('\n');
        }
    } else
        std::cout << "Failed to Load Image: " << argv[1] << '\n';

    return EXIT_SUCCESS;
}