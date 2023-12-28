#include <iostream>
#include <array>
#include <cmath>

class Transformasi2D {
public:
    static std::pair<double, double> rotasi2D(double x, double y, double theta) {
        // matriks awal
        std::array<std::array<double, 1>, 3> matriks_awal = {{
            {x},
            {y},
            {1}
        }};

        // matriks rotasi 2D
        std::array<std::array<double, 3>, 3> matriks_rotasi = {{
            {std::cos(theta), -std::sin(theta), 0},
            {std::sin(theta), std::cos(theta), 0},
            {0, 0, 1}
        }};

        // mencetak P
        std::cout << "Matriks P(x, y) = " << std::endl;
        cetakMatriks(matriks_awal);

        // perkalian matriks
        auto hasil_rotasi = perkalianMatriks(matriks_rotasi, matriks_awal);

        // matriks hasil transformasi rotasi
        std::cout << "\nHasil Matriks Transformasi :" << std::endl;
        cetakMatriks(matriks_rotasi);

        // mengembalikan hasil rotasi (koordinat x, y)
        return std::make_pair(hasil_rotasi[0][0], hasil_rotasi[1][0]);
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
    // implementasi
    double x = 2.0;
    double y = 3.0;
    double theta = M_PI / 6.0;  // mengubah sudut ke radian

    // melakukan rotasi 2D
    auto hasil = Transformasi2D::rotasi2D(x, y, theta);

    // menampilkan hasil rotasi
    std::cout << "\nSesudah rotasi: (" << hasil.first << ", " << hasil.second << ")\n";

    return 0;
}
