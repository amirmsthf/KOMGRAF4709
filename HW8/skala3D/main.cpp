#include <iostream>

// fungsi untuk melakukan skala 3D
void scale_3d(int x, int y, int z, float sx, float sy, float sz, int& result_x, int& result_y, int& result_z) {
    // matriks awal
    float initial_matrix[4][1] = {{x}, {y}, {z}, {1}};

    // matriks transformasi skala 3D
    float scale_matrix[4][4] = {{sx, 0, 0, 0},
                                {0, sy, 0, 0},
                                {0, 0, sz, 0},
                                {0, 0, 0, 1}};

    // mencetak P
    std::cout << "\n Matriks P(x, y, z)" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << initial_matrix[i][0] << std::endl;
    }

    // mencetak matriks transformasi skala
    std::cout << "\nMatriks Transformasi Skala:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << scale_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // mencetak matriks hasil transformasi skala
    float result_matrix[4][1] = {0};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < 4; ++k) {
                result_matrix[i][j] += scale_matrix[i][k] * initial_matrix[k][j];
            }
        }
    }

    std::cout << "\nMatriks Hasil Transformasi Skala:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << result_matrix[i][0] << std::endl;
    }

    // mengembalikan hasil skala (koordinat x, y, z)
    result_x = result_matrix[0][0];
    result_y = result_matrix[1][0];
    result_z = result_matrix[2][0];
}

int main() {
    // input user
    int x, y, z;
    float sx, sy, sz;
    std::cout << "Masukkan nilai x: ";
    std::cin >> x;
    std::cout << "Masukkan nilai y: ";
    std::cin >> y;
    std::cout << "Masukkan nilai z: ";
    std::cin >> z;
    std::cout << "Masukkan nilai skala sx: ";
    std::cin >> sx;
    std::cout << "Masukkan nilai skala sy: ";
    std::cin >> sy;
    std::cout << "Masukkan nilai skala sz: ";
    std::cin >> sz;

    // variabel untuk menyimpan hasil skala
    int result_x, result_y, result_z;

    // memanggil fungsi skala
    scale_3d(x, y, z, sx, sy, sz, result_x, result_y, result_z);

    // menampilkan hasil skala
    std::cout << "\nskala: (" << result_x << ", " << result_y << ", " << result_z << ")" << std::endl;

    return 0;
}
