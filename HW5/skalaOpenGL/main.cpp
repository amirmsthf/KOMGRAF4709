#include <GL/glut.h>
#include <iostream>
#include <vector>

std::vector<std::vector<double>> originalMatrix; // matriks awal
std::vector<std::vector<double>> scaledMatrix;   // matriks setelah transformasi skala
double scaleX, scaleY;                           // faktor skala untuk sumbu x dan y

// menampilkan matriks ke layar
void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << " ";
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
            double scaledValue = matrix[i][j];
            if (j == 0) {
                scaledValue *= scaleX;
            } else if (j == 1) {
                scaledValue *= scaleY;
            }
            row.push_back(scaledValue);
        }
        result.push_back(row);
    }

    return result;
}

// fungsi untuk menggambar matriks dalam bentuk garis
void drawMatrix(const std::vector<std::vector<double>>& matrix) {
    glBegin(GL_LINES);
    for (size_t i = 0; i < matrix.size(); ++i) {
        glVertex2d(matrix[i][0], matrix[i][1]);
        if (i < matrix.size() - 1) {
            glVertex2d(matrix[i + 1][0], matrix[i + 1][1]);
        } else {
            // menghubungkan titik terakhir ke titik pertama agar membentuk poligon
            glVertex2d(matrix[0][0], matrix[0][1]);
        }
    }
    glEnd();
}

// fungsi untuk menggambar matriks sebelum dan sesudah transformasi skala
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // menampilkan matriks awal
    glPushMatrix();
    glTranslatef(-0.5f, 0.0f, 0.0f); // posisikan matriks awal ke kiri
    drawMatrix(originalMatrix);
    glPopMatrix();

    // menampilkan matriks setelah transformasi skala
    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.0f); // posisikan matriks setelah transformasi skala ke kanan
    drawMatrix(scaledMatrix);
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    size_t rows, cols;
    std::cout << "Masukkan jumlah baris matriks: ";
    std::cin >> rows;
    std::cout << "Masukkan jumlah kolom matriks: ";
    std::cin >> cols;

    std::cout << "Masukkan elemen-elemen matriks:" << std::endl;
    for (size_t i = 0; i < rows; ++i) {
        std::vector<double> row;
        for (size_t j = 0; j < cols; ++j) {
            double element;
            std::cout << "Baris " << i + 1 << ", Kolom " << j + 1 << ": ";
            std::cin >> element;
            row.push_back(element);
        }
        originalMatrix.push_back(row);
    }

    std::cout << "Masukkan faktor skala untuk sumbu x: ";
    std::cin >> scaleX;
    std::cout << "Masukkan faktor skala untuk sumbu y: ";
    std::cin >> scaleY;

    scaledMatrix = scaleMatrix(originalMatrix, scaleX, scaleY);

    // inisialisasi OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutCreateWindow("OpenGL Skala Matriks");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
