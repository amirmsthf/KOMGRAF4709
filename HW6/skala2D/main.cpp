#include <iostream>
#include <array>

class Transformasi2D {
public:
    static std::pair<double, double> skala2D(double x, double y, double skala_x, double skala_y) {
        // Matriks transformasi skala 2D
        std::array<std::array<double, 3>, 3> matriks_skala = {{
            {skala_x, 0, 0},
            {0, skala_y, 0},
            {0, 0, 1}
        }};

        // Representasi vektor kolom [x, y, 1]
        std::array<std::array<double, 1>, 3> vektor_kolom = {{
            {x},
            {y},
            {1}
        }};

        // Mencetak matriks awal
        std::cout << "Matriks Awal:" << std::endl;
        cetakMatriks(vektor_kolom);

        // Melakukan perkalian matriks
        auto hasil_transformasi = perkalianMatriks(matriks_skala, vektor_kolom);

        // Mencetak matriks transformasi skala
        std::cout << "\nMatriks Transformasi Skala:" << std::endl;
        cetakMatriks(matriks_skala);

        // Mengembalikan hasil transformasi
        return std::make_pair(hasil_transformasi[0][0], hasil_transformasi[1][0]);
    }

private:
    static std::array<std::array<double, 1>, 3> perkalianMatriks(const std::array<std::array<double, 3>, 3>& mat1,
                                                                 const std::array<std::array<double, 1>, 3>& mat2) {
        std::array<std::array<double, 1>, 3> hasil;
        for (int i = 0; i < 3; ++i) {
            hasil[i][0] = 0;
            for (int j = 0; j < 3; ++j) {
                hasil[i][0] += mat1[i][j] * mat2[j][0];
            }
        }
        return hasil;
    }

    static void cetakMatriks(const std::array<std::array<double, 1>, 3>& mat) {
        for (const auto& row : mat) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }

    static void cetakMatriks(const std::array<std::array<double, 3>, 3>& mat) {
        for (const auto& row : mat) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Contoh penggunaan
    double x = 2.0;
    double y = 3.0;
    double skala_x = 2.0;
    double skala_y = 1.5;

    // Melakukan transformasi skala 2D
    auto hasil = Transformasi2D::skala2D(x, y, skala_x, skala_y);

    // Menampilkan hasil transformasi
    std::cout << "\nSesudah transformasi: (" << hasil.first << ", " << hasil.second << ")\n";

    return 0;
}
