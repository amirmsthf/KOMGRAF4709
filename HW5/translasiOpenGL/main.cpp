#include <GL/glut.h>
#include <iostream>
#include <iomanip>
#include <vector>

double x_awal, y_awal; // titik awal

// melakukan translasi titik (x, y) dengan matriks transformasi translasi
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

// fungsi untuk menggambar titik
void drawPoint(double x, double y) {
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
}

// fungsi display untuk menampilkan titik sebelum dan sesudah translasi
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // menampilkan titik awal
    glBegin(GL_POINTS);
    glVertex2d(x_awal, y_awal);
    glEnd();

    // matriks transformasi translasi
    std::vector<std::vector<double>> matriks_translasi = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0}
    };

    // melakukan translasi
    translasi(x_awal, y_awal, matriks_translasi);

    // menampilkan titik setelah translasi
    glBegin(GL_POINTS);
    glVertex2d(x_awal, y_awal);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    x_awal = 2;
    y_awal = 4;

    std::cout << "Titik awal: (" << x_awal << ", " << y_awal << ")\n";

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Translasi Titik");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
