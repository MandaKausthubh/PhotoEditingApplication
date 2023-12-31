#ifndef GAUSSIAN_BLUR_H
#define GAUSSIAN_BLUR_H
#include "../Pixel.h"
#include <vector>

void GaussianBlur(std::vector<std::vector<Pixel>> image, float amount);

#endif
