#include "GaussianBlur.h"
#include <algorithm>
#include <cstdlib>
#include <vector>

// Function to generate single dimensional Gaussian Distribution
std::vector<float> GenerateGausianMatrix(int size){
    std::vector<float> Gaussian(size);
    Gaussian[0] = 0.39894;
    for(int i = 1; i < size; i++) {
        Gaussian[i] = Gaussian[i-1];
        for(int j = 0; j < 2*i - 1; i++) {
            Gaussian[i] *= 0.3678;
        }
    }
    return Gaussian;
}

void GaussianBlur(std::vector<std::vector<Pixel>> &image, float radius) {
    // We Implement Gaussian BLur Using Convolutions with the Gaussian Distribution !!

    std::vector<std::vector<Pixel>> Temp (image.size(), std::vector<Pixel>(image[0].size()));

    int rows = image.size(), cols = image[0].size();

    std::vector<float> Gaussian = GenerateGausianMatrix((int)(radius * 100) + 1);

    int NeighbourhoodSize = (int)(radius * 10);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            // Here we calculate temp[i][j];
            
            float r_value = 0, g_value = 0, b_value = 0;

            for(int x = -NeighbourhoodSize / 2; x < (NeighbourhoodSize/2) + 1; x++) {
                for(int y = -NeighbourhoodSize/2; y < (NeighbourhoodSize/2) + 1; y++) {
                    int pix_r = 0, pix_g = 0, pix_b = 0;
                    if(x + i >= 0 && y + j >= 0 && x + i < rows && y + j < cols) {
                        pix_r = image[x + i][y + j].r;
                        pix_g = image[x + i][y + j].g;
                        pix_b = image[x + i][y + j].b;
                    }

                    r_value += pix_r * Gaussian[abs(x)] * Gaussian[abs(y)];
                    g_value += pix_g * Gaussian[abs(x)] * Gaussian[abs(y)];
                    b_value += pix_b * Gaussian[abs(x)] * Gaussian[abs(y)];
                }
            }
            r_value = std::min(255, (int)r_value);
            g_value = std::min(255, (int)g_value);
            b_value = std::min(255, (int)b_value);
            Temp[i][j] = Pixel{(int)r_value, (int)g_value, (int)b_value};
        }
    }

    image = Temp;
}
