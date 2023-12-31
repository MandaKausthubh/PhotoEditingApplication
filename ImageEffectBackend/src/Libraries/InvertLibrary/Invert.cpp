#include "Invert.h"
#include<vector>
using namespace std;
void applyInversion(vector<vector<Pixel>>& image) {
    // Apply invert effect to each pixel in the image
    for (auto& row : image) {
        for (auto& pixel : row) {
            // Invert each color channel individually
            pixel.r = 255 - pixel.r;
            pixel.g = 255 - pixel.g;
            pixel.b = 255 - pixel.b;
        }
    }
}