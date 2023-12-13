#include <iostream>

// fungsi translasi 2D
void translate_2d(int x, int y, int tx, int ty, int &result_x, int &result_y) {
    // matriks awal
    int initial_matrix[3][1] = {{x}, {y}, {1}};

    // matriks translasi 2D
    int translation_matrix[3][3] = {{1, 0, tx}, {0, 1, ty}, {0, 0, 1}};

    // mencetak P
    std::cout << "\n Matriks P(x,y)\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << initial_matrix[i][0] << '\n';
    }

    // mencetak matriks transformasi translasi
    std::cout << "\nMatriks Transformasi Translasi:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << translation_matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    // mencetak matriks hasil transformasi translasi (tanpa matriks awal)
    int result_matrix[3][1] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                result_matrix[i][j] += translation_matrix[i][k] * initial_matrix[k][j];
            }
        }
    }

    std::cout << "\nMatriks Hasil Transformasi Translasi:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << result_matrix[i][0] << '\n';
    }

    // mengembalikan hasil translasi (koordinat x, y)
    result_x = result_matrix[0][0];
    result_y = result_matrix[1][0];
}

int main() {
    // input nilai
    int x, y, tx, ty;
    std::cout << "Masukkan nilai x: ";
    std::cin >> x;
    std::cout << "Masukkan nilai y: ";
    std::cin >> y;
    std::cout << "Masukkan nilai tx: ";
    std::cin >> tx;
    std::cout << "Masukkan nilai ty: ";
    std::cin >> ty;

    int result_x, result_y;
    translate_2d(x, y, tx, ty, result_x, result_y);

    std::cout << "\ntranslasi: (" << result_x << ", " << result_y << ")\n";

    return 0;
}
