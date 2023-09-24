#include <iostream>

using namespace std;

int a11=1; int a12=3; int a21=2; int a22=4;
int b11=1; int b12=1; int b21=0; int b22=0;

void penjumlahan(){
    cout << "A+B = " << "|" << a11+b11 << " " << a12+b12 << "|" << endl;
    cout << "      " << "|" << a21+b21 << " " << a22+b22 << "|" << endl;
    cout << endl;
}

void pengurangan(){
    cout << "A-B = " << "|" << a11-b11 << " " << a12-b12 << "|" << endl;
    cout << "      " << "|" << a21-b21 << " " << a22-b22 << "|" << endl;
    cout << endl;
}

void perkalian(){
    cout << "AxB = " << "|" << a11*b11+a12*b21 << " " << a11*b12+a12*b22 << "|" << endl;
    cout << "      " << "|" << a21*b11+a22*b21 << " " << a21*b12+a22*b22 << "|" << endl;
    cout << endl;
}

int main()
{
    int pilih;

    cout << "Matriks" << endl;
    cout << "A = |1 3|" << endl;
    cout << "    |2 4|" << endl;
    cout << endl;
    cout << "B = |1 1|" << endl;
    cout << "    |0 0|" << endl;
    cout << "______________________________" << endl;
    for (int i = 0; i < 999; i++) {
        cout << "Pilihan :" << endl;
        cout << "1. Penjumlahan" << endl;
        cout << "2. Pengurangan" << endl;
        cout << "3. Perkalian" << endl;
        cout << "______________________________" << endl;
        cin >> pilih;

        if (pilih==1){
            penjumlahan();
        } else if(pilih==2){
            pengurangan();
        } else {
            perkalian();
        }
    }
    return 0;
}
