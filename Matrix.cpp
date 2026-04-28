#include "Matrix.h"

// Normal Kurucu: Bellek ayýrýr ve 0 ile doldurur
Matrix::Matrix(int r, int c) {
    rows = r;
    cols = c;
    data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0.0;
        }
    }
}

// Yýkýcý: Belleði serbest býrakýr
Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

// Kopya Kurucu: Bir matris kopyalanýrken (return veya Matrix B = A gibi) yeni bellek açar
Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;

    // Yeni nesne için ayrý bir bellek adresi oluþturuyoruz
    data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j]; // Deðerleri tek tek kopyala
        }
    }
}

void Matrix::display() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

double& Matrix::operator()(int row, int col) {
    return data[row][col];
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        std::cerr << "Hata: Boyutlar uyumsuz!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }

    return result; // Burada Kopya Kurucu devreye girer ve çökme engellenir
}
// Transpoz Fonksiyonu: Satýrlarý sütun, sütunlarý satýr yapar
Matrix Matrix::transpose() const {
    // ÖNEMLÝ: Yeni matrisin satýr sayýsý eskinin sütun sayýsýna, 
    // sütun sayýsý ise eskinin satýr sayýsýna eþit olacak.
    Matrix result(cols, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Eskinin [i][j] elemaný, yeninin [j][i] elemaný olur
            result.data[j][i] = this->data[i][j];
        }
    }

    return result; // Kopya kurucu (copy constructor) sayesinde güvenle döner
}

// * Operatörü: Ýki matrisi çarpar ve yeni bir matris döndürür
Matrix Matrix::operator*(const Matrix& other) const {
    // Çarpým kuralý: 1. matrisin sütun sayýsý, 2. matrisin satýr sayýsýna eþit olmalýdýr
    if (this->cols != other.rows) {
        std::cerr << "Hata: Carpma islemi icin boyutlar uyumsuz!" << std::endl;
        return Matrix(0, 0);
    }

    // Sonuç matrisi: 1. matrisin satýr sayýsý x 2. matrisin sütun sayýsý boyutunda olur
    Matrix result(this->rows, other.cols);

    // Satýr ve sütunlarý çarparak toplama iþlemi (Dot Product)
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            double sum = 0.0;
            // Kesiþim noktasýndaki elemanlarý bulmak için k döngüsü
            for (int k = 0; k < this->cols; ++k) {
                sum += this->data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}