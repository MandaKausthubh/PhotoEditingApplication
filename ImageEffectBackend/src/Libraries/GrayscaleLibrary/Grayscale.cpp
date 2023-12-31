#include "Grayscale.h"
#include<vector>
using namespace std;

void applyGrayScale(vector<vector<Pixel>>  &image) {
    for(auto &Row: image) {
        for(Pixel &Pix: Row) {
            // In grayscale we set r, g and b for every pixel equal to their respective mean
            int sum = (Pix.r + Pix.g + Pix.b)/3;
            Pix.r = Pix.g = Pix.b = sum;
        }
    }
}