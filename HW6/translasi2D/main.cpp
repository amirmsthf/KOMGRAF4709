#include <iostream>
#include <array>

class Transformasi2D {
public:
    static std::pair<int, int> translasi2D(int x, int y, int tx, int ty) {
        // Matriks awal
        std::array<std::array<int, 1>, 3> matriks_awal = {{
            {x},
            {y},
            {1}
        }};

        // Matriks translasi 2D
        std::array<std::array<int, 3>, 3> matriks_translasi = {{
            {1, 0, tx},
            {0, 1, ty},
            {0, 0, 1}
        }};

        // Mencetak P
        std::cout << "\n Matriks P(x, y)" << std::endl;
        cetakMatriks(matriks_awal);

        // Mencetak matriks transformasi translasi
        std::cout << "\nMatriks Transformasi Translasi:" << std::endl;
        cetakMatriks(matriks_translasi);

        // Mencetak matriks hasil transformasi translasi (tanpa matriks awal)
        auto hasil_translasi = perkalianMatriks(matriks_translasi, matriks_awal);
        std::cout << "\nMatriks Hasil Transformasi Translasi:" << std::endl;
        cetakMatriks(hasil_translasi);

        // Mengembalikan hasil translasi (koordinat x, y)
        return std::make_pair(hasil_translasi[0][0], hasil_translasi[1][0]);
    }

private:
    static std::array<std::array<int, 1>, 3> perkalianMatriks(const std::array<std::array<int, 3>, 3>& mat1,
                                                              const std::array<std::array<int, 1>, 3>& mat2) {
        std::array<std::array<int, 1>, 3> hasil;
        for (int i = 0; i < 3; ++i) {
            hasil[i][0] = 0;
            for (int j = 0; j < 3; ++j) {
                hasil[i][0] += mat1[i][j] * mat2[j][0];
            }
        }
        return hasil;
    }

    static void cetakMatriks(const std::array<std::array<int, 1>, 3>& mat) {
        for (const auto& row : mat) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }

    static void cetakMatriks(const std::array<std::array<int, 3>, 3>& mat) {
        for (const auto& row : mat) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Input dari pengguna
    int x, y, tx, ty;
    std::cout << "Masukkan nilai x: ";
    std::cin >> x;
    std::cout << "Masukkan nilai y: ";
    std::cin >> y;
    std::cout << "Masukkan nilai tx: ";
    std::cin >> tx;
    std::cout << "Masukkan nilai ty: ";
    std::cin >> ty;

    // Melakukan translasi 2D
    auto hasil = Transformasi2D::translasi2D(x, y, tx, ty);

    // Menampilkan hasil translasi
    std::cout << "\ntranslasi: (" << hasil.first << ", " << hasil.second << ")\n";

    return 0;
}
