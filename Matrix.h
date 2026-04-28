#pragma once
#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    double** data;

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
};