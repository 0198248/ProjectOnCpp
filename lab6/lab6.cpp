#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

void main() {
	SetConsoleOutputCP(1251);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	float a, b, c, d;
start:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "введіть значення a, b, c (нпаприклад: 2, 5, 3): ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> a >> b >> c;
	cout << endl;
	d = (b * b) - (4 * a * c);
	if (a == 0) {
		cout << "Помилка (1-й коефіцієнт не може = 0)" << endl;
	}
	else if (d < 0) {
		cout << "Рівняння не має коренів" << endl;
		goto start;
	}
	else if (d == 0) {
		cout << "x = " << (-b - d) / (2 * a) << endl;
	}
	else if (d > 0) {
		cout << "x1 = " << (-b - d) / (2 * a) << endl;
		cout << "x2 = " << (-b + d) / (2 * a) << endl;
	}
}