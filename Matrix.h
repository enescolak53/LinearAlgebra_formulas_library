#pragma once
#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    double** data;

    //  Sadece sýnýf içinden çaðrýlacak yardýmcý minör fonksiyonu
    Matrix getMinor(int excludeRow, int excludeCol) const;

public:
    // Kurucu Fonksiyon
    Matrix(int r, int c);

    // Yýkýcý Fonksiyon (Bellek temizliði)
    ~Matrix();

    // Kopya Kurucu (Deep Copy için kritik nokta)
    Matrix(const Matrix& other);

    // Fonksiyonlar
    void display() const;
    double& operator()(int row, int col);
    Matrix operator+(const Matrix& other) const;


        // Matrisin transpozunu (devriðini) almak için fonksiyon
        Matrix transpose() const;

        // Ýki matrisi çarpmak için * operatörünü aþýrý yüklüyoruz
        Matrix operator*(const Matrix& other) const;


        // YENÝ EKLENEN: Determinant hesaplama fonksiyonu
        double determinant() const;

        // Skaler carpim (Matrisi bir sayi ile carpmak)
        Matrix operator*(double scalar) const;

        // Birim Matris uretici (Statik fonksiyon: Nesne olusturmadan cagrilabilir)
        static Matrix identity(int size);

        // Kofaktor Matrisi (Ters matris icin yardimci)
        Matrix cofactor() const;

        // Ters Matris (Inverse)
        Matrix inverse() const;
};