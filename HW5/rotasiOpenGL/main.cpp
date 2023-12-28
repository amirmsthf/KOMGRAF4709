#include <GL/glut.h>
#include <iostream>
#include <cmath>

float angle;
float matrix[3][3] = {{1.0, 0.0, 0.0},
                      {0.0, 1.0, 0.0},
                      {0.0, 0.0, 1.0}};

// fungsi untuk menghitung matriks transformasi rotasi
void rotateMatrix(float matrix[3][3], float angle) {
    float radian = angle * M_PI / 180.0;
    float cosValue = cos(radian);
    float sinValue = sin(radian);

    // isi matriks rotasi
    matrix[0][0] = cosValue;
    matrix[0][1] = -sinValue;
    matrix[1][0] = sinValue;
    matrix[1][1] = cosValue;
    matrix[2][2] = 1.0;
}

// fungsi untuk mengalikan dua matriks
void multiplyMatrix(float result[3][3], float matrix1[3][3], float matrix2[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = 0.0;

            // hitung hasil perkalian matriks
            for (int k = 0; k < 3; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// fungsi untuk menampilkan hasil rotasi menggunakan OpenGL
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINES);

    // gambar garis dari (0,0) ke matriks hasil rotasi
    glVertex2f(0.0, 0.0);
    glVertex2f(matrix[0][0], matrix[1][0]);

    glVertex2f(0.0, 0.0);
    glVertex2f(matrix[0][1], matrix[1][1]);

    glVertex2f(0.0, 0.0);
    glVertex2f(matrix[0][2], matrix[1][2]);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    // input user
    std::cout << "Masukkan sudut rotasi (derajat): ";
    std::cin >> angle;

    // hitung matriks rotasi
    rotateMatrix(matrix, angle);

    // inisialisasi OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Rotasi Matriks");

    // konfigurasi tampilan OpenGL
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    // menetapkan fungsi tampilan
    glutDisplayFunc(display);

    // memulai loop utama OpenGL
    glutMainLoop();

    return 0;
}
