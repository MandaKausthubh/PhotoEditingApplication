#include "GaussianBlur.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <math.h>

// Function to generate single dimensional Gaussian Distribution
std::vector<float> GenerateGausianMatrix(int size, float sigma){
    std::vector<float> Gaussian(size);
    float sum = 0;
    // Gaussian[0] = 0.39894;
    for(int i = 0; i < size; ++i) {
        // Gaussian[i] = Gaussian[i-1];
        // for(int j = 0; j < 2*i - 1; i++) {
        //     Gaussian[i] *= 0.3678;
        // }

        int x = i - size/2;
        Gaussian[i] = exp(-( x * x ) / (2* sigma * sigma));
        sum += Gaussian[i];
    }
    for (int i = 0; i < size; ++i) { Gaussian[i] /= sum; }
    
    return Gaussian;
}

void GaussianBlur(std::vector<std::vector<Pixel>> &image, float radius) {
    // We Implement Gaussian BLur Using Convolutions with the Gaussian Distribution !!

    std::vector<std::vector<Pixel>> Temp (image.size(), std::vector<Pixel>(image[0].size()));
    int rows = image.size(), cols = image[0].size();
    std::vector<float> Gaussian = GenerateGausianMatrix(1 + 2 * ceil(2 * radius), sigma);

    int NeighbourhoodSize = 1 + 2 * ceil(2 * radius)
    std::vector<std::vector<Pixel>> ImageWithPadding(image.size() + 2 * (NeighbourhoodSize/2), std::vector<Pixel>(image[0].size() + 2 * (NeighbourhoodSize / 2)));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            // Here we calculate temp[i][j];
            Pixel tempPix;
            tempPix.r = 0;
            tempPix.g = 0;
            tempPix.b = 0;

            for(int m = 0; m < NeigbourhoodSize; ++m) {
                for(int n = 0; n < NeighbourhoodSize; ++n) {
                    int x = i + m - NeighbourhoodSize/2;
                    int m = j + n - NeighbourhoodSize/2;
                    tempPixel.r += Gaussian[m] * Gaussian[n] * ImageWithPadding[x][y].r;
                    tempPixel.g += Gaussian[m] * Gaussian[n] * ImageWithPadding[x][y].g;
                    tempPixel.b += Gaussian[m] * Gaussian[n] * ImageWithPadding[x][y].b;
                }
            }
            Temp[i][j] = tempPix;
        }
    }

    image = Temp;
}
