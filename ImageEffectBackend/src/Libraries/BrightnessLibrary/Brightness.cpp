#include "Brightness.h"
using namespace std;
#include<vector>
#include<iostream>

void applyBrighteness(vector<vector< Pixel >> &image, float amount){

    // Loop through each pixel in the image and adjust the color values
   
    for (vector<Pixel>& row : image) {
        for (Pixel& pixel : row) {
            pixel.r = (pixel.r + (255 - pixel.r) * amount);
            pixel.g = (pixel.g + (255 - pixel.g) * amount);
            pixel.b = (pixel.b + (255 - pixel.b) * amount);

            // Ensuring that the values stay within the valid range of 0 to 255
            pixel.r = min(255, max(0, pixel.r));
            pixel.g = min(255, max(0, pixel.g));
            pixel.b = min(255, max(0, pixel.b));
        }
    }
}
