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

// Minör Matris Bulma: Belirtilen satýr ve sütunu silerek yeni bir alt matris oluþturur
Matrix Matrix::getMinor(int excludeRow, int excludeCol) const {
    Matrix minorMat(rows - 1, cols - 1); // Yeni matris 1 boyut küçük olacak
    int minorRow = 0, minorCol;

    for (int i = 0; i < rows; ++i) {
        if (i == excludeRow) continue; // Ýstenen satýrý atla

        minorCol = 0;
        for (int j = 0; j < cols; ++j) {
            if (j == excludeCol) continue; // Ýstenen sütunu atla

            minorMat.data[minorRow][minorCol] = this->data[i][j];
            minorCol++;
        }
        minorRow++;
    }
    return minorMat;
}

// Determinant Hesaplama (Laplace Açýlýmý ile Özyineli/Recursive Algoritma)
double Matrix::determinant() const {
    // Kural 1: Sadece kare matrislerin determinantý hesaplanabilir
    if (rows != cols) {
        std::cerr << "Hata: Determinant sadece kare matrisler icin hesaplanabilir!" << std::endl;
        return 0.0;
    }

    // Temel Durum 1: 1x1 Matris
    if (rows == 1) {
        return data[0][0];
    }

    // Temel Durum 2: 2x2 Matris formülü (ad - bc)
    if (rows == 2) {
        return (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]);
    }

    // Genel Durum: 3x3 ve daha büyük matrisler için (Özyineli - Recursive adým)
    double det = 0.0;
    int sign = 1; // Ýþaret deðiþtirici (+, -, +, - ...)

    // Ýlk satýra (0. satýr) göre açýlým yapýyoruz
    for (int j = 0; j < cols; ++j) {
        // Ýlgili elemanýn minör matrisini al
        Matrix minorMat = getMinor(0, j);

        // Ýþaret * Eleman * Minörün Determinantý
        // DÝKKAT: Burada fonksiyon kendi kendini (determinant) çaðýrýyor!
        det += sign * data[0][j] * minorMat.determinant();

        sign = -sign; // Her adýmda iþareti tersine çevir (+ ise - yap, - ise + yap)
    }

    return det;
}


// Skaler Carpim
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = this->data[i][j] * scalar;
    return result;
}

// Birim Matris (Identity)
Matrix Matrix::identity(int size) {
    Matrix I(size, size);
    for (int i = 0; i < size; ++i) I.data[i][i] = 1.0;
    return I;
}

// Kofaktor Matrisi Hesaplama
Matrix Matrix::cofactor() const {
    Matrix res(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Matrix minor = getMinor(i, j);
            // Satir+Sutun toplami tek ise isareti - yap
            double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
            res.data[i][j] = sign * minor.determinant();
        }
    }
    return res;
}

// Ters Matris (Inverse)
Matrix Matrix::inverse() const {
    double det = determinant();
    if (std::abs(det) < 1e-9) { // Sifira cok yakinsa (Tekil matris)
        std::cerr << "Hata: Determinant 0 oldugu icin matrisin tersi yoktur!" << std::endl;
        return Matrix(0, 0);
    }

    // Formul: A^-1 = (1/det) * Transpose(Cofactor(A))
    return cofactor().transpose() * (1.0 / det);
}