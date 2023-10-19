#include <GL/glut.h>
#include <stdio.h>

int x0 = 3, y0 = 9;
int x1 = 1, y1 = 5;

void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int x, y;
    int p = 2 * dy - dx;

    if (x0 > x1) {
        x = x1;
        y = y1;
        x1 = x0;
    } else {
        x = x0;
        y = y0;
    }

    glPointSize(2.0);
    glBegin(GL_POINTS);

    glVertex2i(x, y);

    for (int i = 0; x < x1; i++) {
        x++;
        if (p < 0) {
            p += 2 * dy;
        } else {
            y++;
            p += 2 * (dy - dx);
        }
        glVertex2i(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    drawLine(x0, y0, x1, y1);
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 10, 0, 10);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bresenham Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
