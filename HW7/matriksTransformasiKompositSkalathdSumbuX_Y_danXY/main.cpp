#include <iostream>
#include <vector>

// definisi matriks transformasi skala
std::vector<std::vector<double>> scaleMatrix(double sx, double sy) {
    return {
        {sx, 0, 0},
        {0, sy, 0},
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

// definisi matriks transformasi refleksi terhadap sumbu y
std::vector<std::vector<double>> reflectionMatrixY() {
    return {
        {-1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
}

// definisi matriks transformasi refleksi terhadap sumbu xy
std::vector<std::vector<double>> reflectionMatrixXY() {
    return {
        {-1, 0, 0},
        {0, -1, 0},
        {0, 0, 1}
    };
}

// fungsi untuk menerapkan transformasi pada vektor
std::vector<double> applyTransformation(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector) {
    std::vector<double> resultVector(2, 0);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultVector[i] += matrix[i][j] * vector[j];
        }
    }

    return resultVector;
}

int main() {
    // skala
    double sx1 = 2, sy1 = 3;
    double sx2 = 1.5, sy2 = 0.5;

    // matriks transformasi skala
    std::vector<std::vector<double>> scaleMatrix1 = scaleMatrix(sx1, sy1);
    std::vector<std::vector<double>> scaleMatrix2 = scaleMatrix(sx2, sy2);

    // penggabungan dua matriks transformasi skala terhadap sumbu x, y, dan xy
    std::vector<std::vector<double>> combinedScaleMatrixX = reflectionMatrixX();
    std::vector<std::vector<double>> combinedScaleMatrixY = reflectionMatrixY();
    std::vector<std::vector<double>> combinedScaleMatrixXY = reflectionMatrixXY();

    // vektor (x, y)
    std::vector<double> vector = {2, 3};

    // transformasi pada vektor
    std::vector<double> resultVectorX = applyTransformation(combinedScaleMatrixX, vector);
    std::vector<double> resultVectorY = applyTransformation(combinedScaleMatrixY, vector);
    std::vector<double> resultVectorXY = applyTransformation(combinedScaleMatrixXY, vector);

    // output hasil transformasi
    std::cout << "Vektor awal: [" << vector[0] << ", " << vector[1] << "]" << std::endl;
    std::cout << "Hasil transformasi skala dan refleksi terhadap sumbu x: ["
              << resultVectorX[0] << ", " << resultVectorX[1] << "]" << std::endl;
    std::cout << "Hasil transformasi skala dan refleksi terhadap sumbu y: ["
              << resultVectorY[0] << ", " << resultVectorY[1] << "]" << std::endl;
    std::cout << "Hasil transformasi skala dan refleksi terhadap sumbu xy: ["
              << resultVectorXY[0] << ", " << resultVectorXY[1] << "]" << std::endl;

    return 0;
}
