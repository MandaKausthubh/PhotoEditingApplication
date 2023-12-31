#include "GaussianBlur.h"
#include <cstdlib>
#include <vector>

// Function to generate single dimensional Gaussian Distribution
std::vector<float> GenerateGausianMatrix(int size){
    std::vector<float> Gauss(size);
    Gauss[0] = 0.3989;
    for(int i = 1; i < size; i++) {
        Gauss[i] = Gauss[i-1];
        for(int j = 0; j <= i * (i - 1); j++)
            Gauss[i] = 0.3678 * Gauss[i-1];
    }
    return Gauss;
}

void GaussianBlur(std::vector<std::vector<Pixel>> &image, float radius) {
    std::vector<std::vector<Pixel>> temp(image.size(), std::vector<Pixel> (image[0].size()));
    
    int row = image.size(), col = image[0].size();
    int neighbour = (int)(radius * 100);
    
    std::vector<float> Gaussian = GenerateGausianMatrix((int)(radius * 100 + 1));
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            // Convolving with Gaussian
            temp[i][j] = Pixel{0, 0, 0};
            Pixel Dummy = Pixel{0, 0, 0};
            float sum_r = 0, sum_g = 0, sum_b = 0;
            for(int k1 = -neighbour/2; k1 < neighbour/2; k1 ++) {
                for(int k2 = -neighbour/2; k2 < neighbour/2; k2++) {
                    sum_r += image[i + k1][j + k2].r * Gaussian[abs(k1)] * Gaussian[abs(k2)];
                    sum_g += image[i + k1][j + k2].g * Gaussian[abs(k1)] * Gaussian[abs(k2)];
                    sum_b += image[i + k1][j + k2].b * Gaussian[abs(k1)] * Gaussian[abs(k2)];
                }
            }
            temp[i][j] = Pixel{(int)sum_r, (int)sum_g, (int)sum_g};
        }
    }

    image = temp;
}
