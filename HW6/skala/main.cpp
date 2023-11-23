#include <iostream>
#include <vector>

// menampilkan matriks
void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

// melakukan transformasi skala pada matriks
std::vector<std::vector<double>> scaleMatrix(const std::vector<std::vector<double>>& matrix, double scaleX, double scaleY) {
    std::vector<std::vector<double>> result;

    for (size_t i = 0; i < matrix.size(); ++i) {
        std::vector<double> row;
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            // lakukan transformasi skala pada setiap elemen matriks
            double scaledValue = matrix[i][j];
            if (j == 0) {
                scaledValue *= scaleX; // skala pada sumbu x
            } else if (j == 1) {
                scaledValue *= scaleY; // skala pada sumbu y
            }
            row.push_back(scaledValue);
        }
        result.push_back(row);
    }

    return result;
}

int main() {
    size_t rows, cols;
    std::cout << "Masukkan jumlah baris matriks: ";
    std::cin >> rows;
    std::cout << "Masukkan jumlah kolom matriks: ";
    std::cin >> cols;

    std::vector<std::vector<double>> matrix;
    std::cout << "Masukkan elemen-elemen matriks:" << std::endl;
    for (size_t i = 0; i < rows; ++i) {
        std::vector<double> row;
        for (size_t j = 0; j < cols; ++j) {
            double element;
            std::cout << "Baris " << i + 1 << ", Kolom " << j + 1 << ": ";
            std::cin >> element;
            row.push_back(element);
        }
        matrix.push_back(row);
    }

    // faktor skala untuk sumbu x dan y
    double scaleX, scaleY;
    std::cout << "Masukkan faktor skala untuk sumbu x: ";
    std::cin >> scaleX;
    std::cout << "Masukkan faktor skala untuk sumbu y: ";
    std::cin >> scaleY;

    std::cout << "\nMatriks Awal:" << std::endl;
    printMatrix(matrix);

    // lakukan transformasi skala
    std::vector<std::vector<double>> scaledMatrix = scaleMatrix(matrix, scaleX, scaleY);

    std::cout << "\nMatriks Setelah Transformasi Skala:" << std::endl;
    printMatrix(scaledMatrix);

    return 0;
}
