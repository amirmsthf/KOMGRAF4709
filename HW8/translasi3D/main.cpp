#include <iostream>

// fungsi untuk melakukan translasi 3D
void translate_3d(int x, int y, int z, int tx, int ty, int tz, int& result_x, int& result_y, int& result_z) {
    // matriks awal
    int initial_matrix[4][1] = {{x}, {y}, {z}, {1}};

    // matriks translasi 3D
    int translation_matrix[4][4] = {{1, 0, 0, tx},
                                    {0, 1, 0, ty},
                                    {0, 0, 1, tz},
                                    {0, 0, 0, 1}};

    // mencetak P
    std::cout << "\n Matriks P(x, y, z)" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << initial_matrix[i][0] << std::endl;
    }

    // mencetak matriks transformasi translasi
    std::cout << "\nMatriks Transformasi Translasi:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << translation_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // mencetak matriks hasil transformasi translasi
    int result_matrix[4][1] = {0};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < 4; ++k) {
                result_matrix[i][j] += translation_matrix[i][k] * initial_matrix[k][j];
            }
        }
    }

    std::cout << "\nMatriks Hasil Transformasi Translasi:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << result_matrix[i][0] << std::endl;
    }

    // mengembalikan hasil translasi (koordinat x, y, z)
    result_x = result_matrix[0][0];
    result_y = result_matrix[1][0];
    result_z = result_matrix[2][0];
}

int main() {
    // input user
    int x, y, z, tx, ty, tz;
    std::cout << "Masukkan nilai x: ";
    std::cin >> x;
    std::cout << "Masukkan nilai y: ";
    std::cin >> y;
    std::cout << "Masukkan nilai z: ";
    std::cin >> z;
    std::cout << "Masukkan nilai tx: ";
    std::cin >> tx;
    std::cout << "Masukkan nilai ty: ";
    std::cin >> ty;
    std::cout << "Masukkan nilai tz: ";
    std::cin >> tz;

    // variabel untuk menyimpan hasil translasi
    int result_x, result_y, result_z;

    // memanggil fungsi translasi
    translate_3d(x, y, z, tx, ty, tz, result_x, result_y, result_z);

    // menampilkan hasil translasi
    std::cout << "\ntranslasi: (" << result_x << ", " << result_y << ", " << result_z << ")" << std::endl;

    return 0;
}
