#include <iostream>
#include <cmath>
#include <vector>

// definisi matriks transformasi rotasi
std::vector<std::vector<double>> rotationMatrix(double theta) {
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);
    return {
        {cosTheta, -sinTheta, 0},
        {sinTheta, cosTheta, 0},
        {0, 0, 1}
    };
}

// definisi matriks transformasi refleksi terhadap sumbu x
std::vector<std::vector<double>> reflectionMatrixX() {
    return {
        {1, 0, 0},
        {0, -1, 0},
        {0, 0, 1}
    };
}

// fungsi untuk menggabungkan dua matriks transformasi rotasi dan refleksi terhadap sumbu x
std::vector<std::vector<double>> combineRotationAndReflect(const std::vector<std::vector<double>>& rotationMatrix1, const std::vector<std::vector<double>>& rotationMatrix2) {
    std::vector<std::vector<double>> combinedMatrix(3, std::vector<double>(3, 0.0));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            combinedMatrix[i][j] = 0.0;
            for (int k = 0; k < 3; ++k) {
                combinedMatrix[i][j] += rotationMatrix2[i][k] * rotationMatrix1[k][j];
            }
        }
    }

    std::vector<std::vector<double>> reflectionMatrix = reflectionMatrixX();
    std::vector<std::vector<double>> resultMatrix(3, std::vector<double>(3, 0.0));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultMatrix[i][j] = 0.0;
            for (int k = 0; k < 3; ++k) {
                resultMatrix[i][j] += reflectionMatrix[i][k] * combinedMatrix[k][j];
            }
        }
    }

    return resultMatrix;
}

// fungsi untuk menerapkan transformasi pada vektor
std::vector<double> applyTransformation(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector) {
    std::vector<double> resultVector(2, 0.0);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultVector[i] += matrix[i][j] * vector[j];
        }
    }

    return resultVector;
}

int main() {
    // contoh penggunaan:
    // tentukan sudut rotasi yang diinginkan (dalam radian)
    double theta1 = 30.0, theta2 = 45.0;

    // dapatkan matriks transformasi rotasi
    std::vector<std::vector<double>> rotationMatrix1 = rotationMatrix(theta1);
    std::vector<std::vector<double>> rotationMatrix2 = rotationMatrix(theta2);

    // gabungkan dua matriks transformasi rotasi dan refleksi terhadap sumbu x
    std::vector<std::vector<double>> combinedRotationMatrix = combineRotationAndReflect(rotationMatrix1, rotationMatrix2);

    // misalnya kita punya vektor [x, y]
    std::vector<double> vector = {2.0, 3.0};

    // terapkan transformasi pada vektor
    std::vector<double> resultVector = applyTransformation(combinedRotationMatrix, vector);

    // output hasil transformasi
    std::cout << "Vektor awal: [" << vector[0] << ", " << vector[1] << "]" << std::endl;
    std::cout << "Hasil transformasi rotasi dan refleksi terhadap sumbu x: ["
              << resultVector[0] << ", " << resultVector[1] << "]" << std::endl;

    return 0;
}
