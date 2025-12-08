#include <iostream>
#include <conio.h>

using namespace std;

void arrOutput(char a[10][10]) {
    system("CLS");
    for (int i = 0; i < 10; i++) {
        cout << '|';
        for (int g = 0; g < 10; g++)
            cout << a[i][g];
        cout << '|';
        cout << endl;
    }
}


void main()
{
    char a[10][10];
    for (int i = 0; i < 10; i++)
        for (int g = 0; g < 10; g++)
            a[i][g] = '-';
    char pers = '*';

    int i = 0;
    int j = 0;
    a[i][j] = pers;
    arrOutput(a);
    while (true) {
        int ch = _getch();

        if (ch == 27) break;

        switch (ch) {
        case 72:
            if (i > 0) {
                a[i][j] = '-';
                i--;
                a[i][j] = pers;
                arrOutput(a);
            }
            break;
        case 80:
            if (i < 9) {
                a[i][j] = '-';
                i++;
                a[i][j] = pers;
                arrOutput(a);
            }
            break;
        case 75:
            if (j > 0) {
                a[i][j] = '-';
                j--;
                a[i][j] = pers;
                arrOutput(a);
            }
            break;
        case 77:
            if (j < 9) {
                a[i][j] = '-';
                j++;
                a[i][j] = pers;
                arrOutput(a);
            }
            break;
        }
    }

    arrOutput(a);
}