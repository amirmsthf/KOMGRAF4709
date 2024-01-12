#include <iostream>
using namespace std;

// kode kliping
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// batas window
const int xmin = 1;
const int ymin = 1;
const int xmax = 4;
const int ymax = 5;

// fungsi untuk menghitung kode kliping
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

// Algoritma Clipping Cohen-Sutherland
void cohenSutherland(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // garis sepenuhnya di dalam window
            accept = true;
            break;
        } else if (code1 & code2) {
            // garis sepenuhnya di luar window
            break;
        } else {
            // garis potong window, hitung titik potong
            int x, y;
            int codeOut = code1 ? code1 : code2;

            if (codeOut & TOP) {
                // potong garis dengan batas atas window
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & BOTTOM) {
                // potong garis dengan batas bawah window
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (codeOut & RIGHT) {
                // potong garis dengan batas kanan window
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (codeOut & LEFT) {
                // potong garis dengan batas kiri window
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            // ganti titik potong dengan titik luar window
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    // output hasil
    if (accept) {
        cout << "Garis diterima: (" << x1 << ", " << y1 << ") dan (" << x2 << ", " << y2 << ")" << endl;
    } else {
        cout << "Garis ditolak." << endl;
    }
}

int main() {
    // contoh penggunaan
    cohenSutherland(3, 4, 5, 6);
    return 0;
}
