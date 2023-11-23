#include <iostream>
#include <cmath>

// menghitung matriks transformasi rotasi
void rotateMatrix(float matrix[3][3], float angle) {
    float radian = angle * M_PI / 180.0;
    float cosValue = cos(radian);
    float sinValue = sin(radian);

    matrix[0][0] = cosValue;
    matrix[0][1] = -sinValue;
    matrix[1][0] = sinValue;
    matrix[1][1] = cosValue;
    matrix[2][2] = 1.0;
}

// mengalikan dua matriks
void multiplyMatrix(float result[3][3], float matrix1[3][3], float matrix2[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = 0.0;
            for (int k = 0; k < 3; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    float angle;
    std::cout << "Masukkan sudut rotasi (derajat): ";
    std::cin >> angle;

    // matriks awal
    float matrix[3][3] = {{1.0, 0.0, 0.0},
                          {0.0, 1.0, 0.0},
                          {0.0, 0.0, 1.0}};

    // matriks transformasi rotasi
    float rotationMatrix[3][3];
    rotateMatrix(rotationMatrix, angle);

    // matriks hasil rotasi
    float resultMatrix[3][3];
    multiplyMatrix(resultMatrix, matrix, rotationMatrix);

    // menampilkan matriks hasil rotasi
    std::cout << "Matriks Hasil Rotasi:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << resultMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
