#include "Flip.h"
#include <algorithm>
#include <vector>
using namespace std;

void FlipImage(vector<vector<Pixel>> &image, int HorizontalFlip, int VerticleFlip) {
    if(HorizontalFlip != 0) {
        int rows = image.size();
        int cols = image[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols / 2; j++) {
            // Swap pixels horizontally
                swap(image[i][j], image[i][cols - 1 - j]);
        }
    }
    }

    if(VerticleFlip != 0) {
         int rows = image.size();
        int cols = image[0].size();

        for (int i = 0; i < rows / 2; i++) {
            for (int j = 0; j < cols; j++) {
            // Swap pixels vertically
                swap(image[i][j], image[rows - 1 - i][j]);
        }
    }
    }
}