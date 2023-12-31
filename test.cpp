#include <iostream>
#include <vector>

struct Test {
    int a, b, c;
};

int main(void) {
    std::vector<std::vector<int>> A = {{2, 3, 1}, {9}};
    std::vector<std::vector<int>> B = {{34}, {23, 45, 65}, {5, 7}};
    
    Test X;
    X.a = 1; X.b = 2, X.c = 3;
    Test Y;
    Y.a = 4; Y.b = 2, Y.c = 3;

    X = Y;
    A = B;
    
    for(std::vector<int> x: A) {
        for(int y: x) std::cout << y << " ";
        std::cout << "\n";
    }

    std::cout << X.a << '\n';

    return 0;
}
