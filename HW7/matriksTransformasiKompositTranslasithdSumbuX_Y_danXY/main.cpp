#include <iostream>
#include <vector>

// definisi matriks transformasi translasi
std::vector<std::vector<int>> translationMatrix(int tx, int ty) {
    return {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}
    };
}

// definisi matriks transformasi refleksi terhadap sumbu x
std::vector<std::vector<int>> reflectionMatrixX() {
    return {
        {1, 0, 0},
        {0, -1, 0},
        {0, 0, 1}
    };
}

// definisi matriks transformasi refleksi terhadap sumbu y
std::vector<std::vector<int>> reflectionMatrixY() {
    return {
        {-1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
}

// definisi matriks transformasi refleksi terhadap sumbu xy
std::vector<std::vector<int>> reflectionMatrixXY() {
    return {
        {-1, 0, 0},
        {0, -1, 0},
        {0, 0, 1}
    };
}

// fungsi untuk menerapkan transformasi pada vektor
std::vector<int> applyTransformation(const std::vector<std::vector<int>>& matrix, const std::vector<int>& vector) {
    std::vector<int> resultVector(2, 0);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultVector[i] += matrix[i][j] * vector[j];
        }
    }

    return resultVector;
}

int main() {
    // tx, ty
    int tx1 = 2, ty1 = 3;
    int tx2 = 1, ty2 = 2;

    // matriks transformasi translasi
    std::vector<std::vector<int>> translationMatrix1 = translationMatrix(tx1, ty1);
    std::vector<std::vector<int>> translationMatrix2 = translationMatrix(tx2, ty2);
    std::vector<std::vector<int>> translationMatrix3 = translationMatrix(tx1, ty1);

    // penggabungan dua matriks transformasi translasi terhadap sumbu x, y, dan xy
    std::vector<std::vector<int>> combinedTranslationMatrixX = reflectionMatrixX();
    std::vector<std::vector<int>> combinedTranslationMatrixY = reflectionMatrixY();
    std::vector<std::vector<int>> combinedTranslationMatrixXY = reflectionMatrixXY();

    // transformasi pada vektor
    std::vector<int> vector = {2, 3};
    std::vector<int> resultVectorX = applyTransformation(combinedTranslationMatrixX, vector);
    std::vector<int> resultVectorY = applyTransformation(combinedTranslationMatrixY, vector);
    std::vector<int> resultVectorXY = applyTransformation(combinedTranslationMatrixXY, vector);

    // output hasil transformasi
    std::cout << "Vektor awal: [" << vector[0] << ", " << vector[1] << "]" << std::endl;
    std::cout << "Hasil transformasi translasi dan refleksi terhadap sumbu x: ["
              << resultVectorX[0] << ", " << resultVectorX[1] << "]" << std::endl;
    std::cout << "Hasil transformasi translasi dan refleksi terhadap sumbu y: ["
              << resultVectorY[0] << ", " << resultVectorY[1] << "]" << std::endl;
    std::cout << "Hasil transformasi translasi dan refleksi terhadap sumbu xy: ["
              << resultVectorXY[0] << ", " << resultVectorXY[1] << "]" << std::endl;

    return 0;
}
