#include <iostream>
#include "Matrix.h"

int main() {
    std::cout << "--- Matris Carpimi Testi ---" << std::endl;

    // A matrisi: 2 satýr, 3 sütun (2x3)
    Matrix A(2, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;

    // B matrisi: 3 satýr, 2 sütun (3x2)
    Matrix B(3, 2);
    B(0, 0) = 7.0;  B(0, 1) = 8.0;
    B(1, 0) = 9.0;  B(1, 1) = 10.0;
    B(2, 0) = 11.0; B(2, 1) = 12.0;

    std::cout << "\nA Matrisi (2x3):" << std::endl;
    A.display();

    std::cout << "\nB Matrisi (3x2):" << std::endl;
    B.display();

    // Çarpma iþlemini baþlat (Beklenen sonuç: 2x2 matris)
    Matrix C = A * B;

    std::cout << "\nC Matrisi (A * B Sonucu - 2x2):" << std::endl;
    C.display();

    return 0;
}