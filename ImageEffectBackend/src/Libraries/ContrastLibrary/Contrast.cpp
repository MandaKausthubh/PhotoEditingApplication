#include "Contrast.h"
#include <algorithm>
#include <vector>
using namespace std;

void adjust_contrast( vector<vector<Pixel>>& image, float amount) {
   // vector<vector<Pixel>> adjusted_image = image;

   int min_intensity = 255;
   int max_intensity = 0;

   // Find minimum and maximum intensity values across all channels
   for ( vector<Pixel>& row : image) {
       for ( Pixel& pixel : row) {
           min_intensity = min({min_intensity, pixel.r, pixel.g, pixel.b});
           max_intensity = max({max_intensity, pixel.r, pixel.g, pixel.b});
       }
   }

   // Apply histogram stretching to each pixel in each channel
   for (auto &row : image) {
       for (auto &pixel : row) {
           pixel.r = int((pixel.r - min_intensity) * amount + min_intensity);
           pixel.g = int((pixel.g - min_intensity) * amount + min_intensity);
           pixel.b = int((pixel.b - min_intensity) * amount + min_intensity);

           // Clip values to valid range (0-255)
           pixel.r = min(max(pixel.r, 0), 255);
           pixel.g = min(max(pixel.g, 0), 255);
           pixel.b = min(max(pixel.b, 0), 255);
       }
   }

   // return adjusted_image;
}