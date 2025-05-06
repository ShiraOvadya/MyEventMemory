#include <dlib/matrix.h>
#include <iostream>

int main() {
    dlib::matrix<double> mat(2, 2);
    mat = 1, 2,
          3, 4;

    std::cout << "Matrix:\n" << mat << std::endl;

    return 0;
}
