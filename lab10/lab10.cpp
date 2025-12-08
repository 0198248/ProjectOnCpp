#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void arrOutput(int a[5][5]) {
    cout << "----------------------------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << '|';
        for (int g = 0; g < 5; g++)
            if (g >= 4) {
                cout << a[i][g];
                string strA = to_string(a[i][g]);
                for (int l = 0; l < (4 - strA.length()); l++)
                    cout << " ";
            }
            else {
                cout << a[i][g];
                string strA = to_string(a[i][g]);
                for (int l = 0; l < (5 - strA.length()); l++)
                cout << " ";
            }
        cout << '|';
        cout << endl;
    }
}

int min(int a[5][5]) {
    int min = a[0][0];
    for (int i = 0; i < 5; i++)
        for (int g = 0; g < 5; g++)
            if (min < a[i][g]) min = a[i][g];
    return min;
}
int max(int a[5][5]) {
    int max = a[0][0];
    for (int i = 0; i < 5; i++)
        for (int g = 0; g < 5; g++)
            if (max > a[i][g]) max = a[i][g];
    return max;
}
int summ(int a[5][5]) {
    int summ = 0;
    for (int i = 0; i < 5; i++)
        for (int g = 0; g < 5; g++)
            summ += a[i][g];
    return summ;
}
int average(int a[5][5]) {
    int av = 0;
    int count = 0;
    for (int i = 0; i < 5; i++)
        for (int g = 0; g < 5; g++) {
            count++;
            av += a[i][g];
        }
    return av / count;
}
void even(int a[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int g = 0; g < 5; g++) {
            if ((a[i][g] % 2) == 0) a[i][g] = 0;
        }
}
void transpose(int a[5][5]) {
    int b[5][5];
    for (int i = 0; i < 5; i++)
        for (int g = 0; g < 5; g++) {
            b[i][g] = a[i][g];
        }
    for (int i = 0; i < 5; i++)
        for (int g = 0; g < 5; g++) {
            a[i][g] = b[g][i];
        }
}

void main()
{
    int a[5][5];
    srand(time(NULL));
    for(int i = 0; i < 5; i++)
        for (int g = 0; g < 5; g++) {
            a[i][g] = rand() % 9999;
        }
    arrOutput(a);
    even(a);
    arrOutput(a);
    transpose(a);
    arrOutput(a);
}