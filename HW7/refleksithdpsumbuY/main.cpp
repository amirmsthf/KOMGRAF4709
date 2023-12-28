#include <iostream>
#include <vector>

// definisi matriks transformasi refleksi terhadap sumbu y
std::vector<std::vector<int>> reflectionMatrixY() {
    return {
        {-1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
}

// fungsi untuk menerapkan transformasi pada vektor
std::vector<int> applyTransformation(const std::vector<std::vector<int>>& matrix, const std::vector<int>& vector) {
    std::vector<int> resultVector(3, 0);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultVector[i] += matrix[i][j] * vector[j];
        }
    }

    return resultVector;
}

int main() {
    // misalnya kita punya vektor [x, y, z]
    std::vector<int> vector = {2, 3, 1};

    // dapatkan matriks transformasi refleksi terhadap sumbu y
    std::vector<std::vector<int>> reflectionMatrix = reflectionMatrixY();

    // terapkan transformasi pada vektor
    std::vector<int> resultVector = applyTransformation(reflectionMatrix, vector);

    // output hasil transformasi
    std::cout << "Vektor awal: [";
    for (int i = 0; i < 3; ++i) {
        std::cout << vector[i];
        if (i < 2) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Hasil transformasi: [";
    for (int i = 0; i < 3; ++i) {
        std::cout << resultVector[i];
        if (i < 2) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
