#include "Rotation.h"
#include <vector>
using namespace std;

void rotateImage(vector<vector<Pixel>>& image, int val) {
    if(val == 0) {/*Doing nothing*/ return;}
    else if(val == 1) {
        std::vector<vector<Pixel>> temp(image[0].size(), vector<Pixel>(image.size()));
        int rows = image[0].size(), cols = image.size();
        for(int i = 0; i < cols; i++) {
            for(int j = 0; j < rows; j++) {
                temp[j][i] = image[cols - i - 1][j];
            }
        }
        image = temp;
    }
    else{
        rotateImage(image, 1);
        rotateImage(image, val - 1);
    }
}
