#include <iostream>
#include <iomanip>
#include <vector>

// mentranslasikan titik (x, y)
void translasi(double& x, double& y, const std::vector<std::vector<double>>& matrix) {
    double hasil_x = x * matrix[0][0] + y * matrix[0][1] + matrix[0][2];
    double hasil_y = x * matrix[1][0] + y * matrix[1][1] + matrix[1][2];
    x = hasil_x;
    y = hasil_y;
}

// menampilkan matriks transformasi
void tampilkanMatriks(const std::vector<std::vector<double>>& matrix) {
    for (const auto& baris : matrix) {
        for (const auto& elemen : baris) {
            std::cout << std::setw(8) << elemen;
        }
        std::cout << '\n';
    }
}

int main() {
    // titik awal
    double x_awal, y_awal;

    std::cout << "Masukkan koordinat titik awal (x y): ";
    std::cin >> x_awal >> y_awal;

    std::cout << "Titik awal: (" << x_awal << ", " << y_awal << ")\n";

    // input nilai tx dan ty
    double tx, ty;
    std::cout << "Masukkan nilai tx: ";
    std::cin >> tx;
    std::cout << "Masukkan nilai ty: ";
    std::cin >> ty;

    // matriks transformasi translasi
    std::vector<std::vector<double>> matriks_translasi = {
        {1.0, 0.0, tx},  // Matrix baris 1: [1 0 tx]
        {0.0, 1.0, ty},  // Matrix baris 2: [0 1 ty]
        {0.0, 0.0, 1.0}   // Matrix baris 3: [0 0 1 ]
    };

    // menampilkan matriks transformasi translasi
    std::cout << "Matriks Transformasi Translasi:\n";
    tampilkanMatriks(matriks_translasi);

    // melakukan translasi
    translasi(x_awal, y_awal, matriks_translasi);

    std::cout << "Setelah translasi: (" << x_awal << ", " << y_awal << ")\n";

    return 0;
}
