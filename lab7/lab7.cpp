#include <iostream>

#include <math.h>

using namespace std;

void main()
{
    int height;
    cout << "Enter the triangle height: ";
    cin >> height;
    cout << endl;

    int inrow = 1 + height * 2;
    int Side = floor(inrow / 2);

    for (int g = 0; g < height; g++) {
        for (int i = 0; i < Side; i++) {
            cout << " ";
        }
        for (int i = 0; i < inrow - Side * 2; i++) {
            cout << "^";
        }
        for (int i = 0; i < Side; i++) {
            cout << " ";
        }
        cout << endl;
        Side--;
    }
}