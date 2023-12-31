#include "Sepia.h"
#include<vector>
using namespace std;

void applySepiaEffect(vector<vector<Pixel>>& image) {
    
    for (auto& row : image) {
        for (auto& pixel : row) {
            // 0.393, 0.769, 0.189, 0.349, 0.686, 0.168, 0.272, 0.534, 0.131 are typical constants used in sepia conversion algos
            int newr = static_cast<int>((0.393 * pixel.r) + (0.769 * pixel.g) + (0.189 * pixel.b));
            int newg = static_cast<int>((0.349 * pixel.r) + (0.686 * pixel.g) + (0.168 * pixel.b));
            int newb = static_cast<int>((0.272 * pixel.r) + (0.534 * pixel.g) + (0.131 * pixel.b));

            // Ensuring color values are within the valid range (0-255)
            pixel.r = min(newr, 255);
            pixel.g = min(newg, 255);
            pixel.b = min(newb, 255);
        }
    }
}

