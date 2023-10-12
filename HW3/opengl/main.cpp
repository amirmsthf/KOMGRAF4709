/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#endif
#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>

int round(float n) {
    if (n - (int)n < 0.5)
        return (int)n;
    return (int)(n + 0.5);
}

void DDA(int x0, int y0, int xn, int yn) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);  // Warna putih

    int dx = xn - x0;
    int dy = yn - y0;

    int step;

    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    float x_increment = float(dx) / step;
    float y_increment = float(dy) / step;

    float x = x0;
    float y = y0;

    glBegin(GL_POINTS);

    for (int i = 0; i <= step; i++) {
        glVertex2i(round(x), round(y));
        x += x_increment;
        y += y_increment;
    }

    glEnd();
    glFlush();
}

void display() {
    int x0 = 12, y0 = 1, xn = 2, yn = 8;
    DDA(x0, y0, xn, yn);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Warna latar belakang hitam
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 15, 0, 10);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
