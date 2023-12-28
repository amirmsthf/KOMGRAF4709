#include <iostream>
#include <cmath>

// fungsi untuk melakukan rotasi 3D
void rotate_3d(int x, int y, int z, float rx, float ry, float rz, int& result_x, int& result_y, int& result_z) {
    // matriks awal
    float initial_matrix[4][1] = {{x}, {y}, {z}, {1}};

    // matriks transformasi rotasi Rx
    float rotation_matrix_rx[4][4] = {{1, 0, 0, 0},
                                      {0, cos(rx), -sin(rx), 0},
                                      {0, sin(rx), cos(rx), 0},
                                      {0, 0, 0, 1}};

    // matriks transformasi rotasi Ry
    float rotation_matrix_ry[4][4] = {{cos(ry), 0, sin(ry), 0},
                                      {0, 1, 0, 0},
                                      {-sin(ry), 0, cos(ry), 0},
                                      {0, 0, 0, 1}};

    // matriks transformasi rotasi Rz
    float rotation_matrix_rz[4][4] = {{cos(rz), -sin(rz), 0, 0},
                                      {sin(rz), cos(rz), 0, 0},
                                      {0, 0, 1, 0},
                                      {0, 0, 0, 1}};

    // mencetak P
    std::cout << "\n Matriks P(x, y, z)" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << initial_matrix[i][0] << std::endl;
    }

    // mencetak matriks transformasi rotasi Rx
    std::cout << "\nMatriks Transformasi Rotasi Rx:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << rotation_matrix_rx[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // mencetak matriks transformasi rotasi Ry
    std::cout << "\nMatriks Transformasi Rotasi Ry:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << rotation_matrix_ry[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // mencetak matriks transformasi rotasi Rz
    std::cout << "\nMatriks Transformasi Rotasi Rz:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << rotation_matrix_rz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // menghitung matriks hasil transformasi rotasi
    float result_matrix_rx[4][1] = {0};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < 4; ++k) {
                result_matrix_rx[i][j] += rotation_matrix_rx[i][k] * initial_matrix[k][j];
            }
        }
    }

    float result_matrix_ry[4][1] = {0};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < 4; ++k) {
                result_matrix_ry[i][j] += rotation_matrix_ry[i][k] * result_matrix_rx[k][j];
            }
        }
    }

    float result_matrix_rz[4][1] = {0};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < 4; ++k) {
                result_matrix_rz[i][j] += rotation_matrix_rz[i][k] * result_matrix_ry[k][j];
            }
        }
    }

    std::cout << "\nMatriks Hasil Transformasi Rotasi:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << result_matrix_rz[i][0] << std::endl;
    }

    // mengembalikan hasil rotasi (koordinat x, y, z)
    result_x = result_matrix_rz[0][0];
    result_y = result_matrix_rz[1][0];
    result_z = result_matrix_rz[2][0];
}

int main() {
    // input user
    int x, y, z;
    float rx, ry, rz;
    std::cout << "Masukkan nilai x: ";
    std::cin >> x;
    std::cout << "Masukkan nilai y: ";
    std::cin >> y;
    std::cout << "Masukkan nilai z: ";
    std::cin >> z;
    std::cout << "Masukkan nilai rotasi Rx (derajat): ";
    std::cin >> rx;
    std::cout << "Masukkan nilai rotasi Ry (derajat): ";
    std::cin >> ry;
    std::cout << "Masukkan nilai rotasi Rz (derajat): ";
    std::cin >> rz;

    // variabel untuk menyimpan hasil rotasi
    int result_x, result_y, result_z;

    // memanggil fungsi rotasi
    rotate_3d(x, y, z, rx, ry, rz, result_x, result_y, result_z);

    // menampilkan hasil rotasi
    std::cout << "\nrotasi: (" << result_x << ", " << result_y << ", " << result_z << ")" << std::endl;

    return 0;
}
