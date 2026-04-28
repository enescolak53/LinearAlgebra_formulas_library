#include <iostream>
#include "Matrix.h"

int main() {
    std::cout << "--- Transpoz Modulu Testi ---" << std::endl;

    // 2 satýr, 3 sütunluk (2x3) asimetrik bir matris oluþturalým
    Matrix A(2, 3);

    // Deðerleri atayalým
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;

    std::cout << "\nOrijinal A Matrisi (2x3):" << std::endl;
    A.display();

    // Transpozunu alalým
    Matrix A_T = A.transpose();

    std::cout << "\nA Matrisinin Transpozu (3x2):" << std::endl;
    A_T.display();

    return 0;
}