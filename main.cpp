#include <iostream>
#include "Matrix.h"

int main() {
   
    /*
  std::cout << "=====================================" << std::endl;
    std::cout << "  LINEAR ALGEBRA LIBRARY  " << std::endl;
    std::cout << "=====================================\n" << std::endl;

    // 3 satýr, 3 sütunluk bir A matrisi oluþtur (Kurucu fonksiyon tetiklenir)
    Matrix A(3, 3);

    std::cout << "Olusturulan A Matrisi (Baslangic degerleri):" << std::endl;

    // Matrisi ekrana yazdýr
    A.display();
    */










    /*
    std::cout << "--- Lineer Cebir Modulu Testi ---" << std::endl;

    // 2x2 boyutunda iki matris oluþtur
    Matrix A(2, 2);
    Matrix B(2, 2);

    // A matrisine deðerler atayalým
    A(0, 0) = 1.5;  A(0, 1) = 2.0;
    A(1, 0) = 3.2;  A(1, 1) = 4.1;

    // B matrisine deðerler atayalým
    B(0, 0) = 0.5;  B(0, 1) = 1.0;
    B(1, 0) = 2.8;  B(1, 1) = 0.9;

    std::cout << "\nA Matrisi:" << std::endl;
    A.display();

    std::cout << "\nB Matrisi:" << std::endl;
    B.display();

    // Ýþte C++ OOP'nin gücü: Ýki nesneyi doðrudan + operatörü ile topluyoruz!
    Matrix C = A + B;

    std::cout << "\nC Matrisi (A + B Sonucu):" << std::endl;
    C.display();
    
    */










    /*
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
    */












   /* std::cout << "--- Matris Carpimi Testi ---" << std::endl;

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
    */












/*
   std::cout << "--- Determinant Hesaplama Testi ---" << std::endl;

    // 3x3 boyutunda bir kare matris oluþturalým
    Matrix A(3, 3);

    A(0, 0) = 6.0; A(0, 1) = 1.0; A(0, 2) = 1.0;
    A(1, 0) = 4.0; A(1, 1) = -2.0; A(1, 2) = 5.0;
    A(2, 0) = 2.0; A(2, 1) = 8.0; A(2, 2) = 7.0;

    std::cout << "\nA Matrisi (3x3):" << std::endl;
    A.display();

    // Determinantý hesapla
    double det = A.determinant();

    std::cout << "\nA Matrisinin Determinanti: " << det << std::endl;
    // Beklenen kesin sonuç: -306 olmalýdýr. */





/*
std::cout << "--- Lineer Cebir Final Testi: Ters Matris ---" << std::endl;

Matrix A(2, 2);
A(0, 0) = 4.0; A(0, 1) = 7.0;
A(1, 0) = 2.0; A(1, 1) = 6.0;

std::cout << "\nA Matrisi:" << std::endl;
A.display();

Matrix A_inv = A.inverse();

std::cout << "\nA'nin Tersi (A^-1):" << std::endl;
A_inv.display();

std::cout << "\nSaglama (A * A^-1): (Sonuc Birim Matris cikmali)" << std::endl;
Matrix I = A * A_inv;
I.display();
*/




    return 0;
}