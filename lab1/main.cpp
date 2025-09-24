#include <iostream>
#include <locale>
#include <math.h>
#include <cstring>

using namespace std;

int main() {

	setlocale(LC_ALL, "uk_UA");

	float a = 1.04f;
	cout << "number0: " << a << endl;
	int b = 4;
	a -= b;
	cout << "number1: " << a << endl;
	cout << "квадрат числа: " << pow(a, b) << " корiнь: " << sqrtf(a * -1) << " abs: " << abs(a) << " округлення: " << ceil(a) << " модуль числа: " << fabs(a) << endl; //операції з числами

	bool c = 0;
	if (!c) cout << "bool is false" << endl; else cout << "bool is true" << endl; //операції з булевими значеннями

	string d = "Hello";
	char h[] = "Hello";
	cout << "word: " << d << endl;
	cout << "length: " << d.length() << " substr: " << d.substr(2, 3) << " на позицiї: " << d.find("llo") + 1 << "; toupper | tolower: "; for (int x = 0; x < strlen(h); x++) putchar(toupper(h[x])); cout << " | "; for (int x = 0; x < strlen(h); x++) putchar(tolower(h[x])); cout << endl; //операції з рядками

	int geo1, geo2;
	cout << "Введiть довжину 1ї сторони прямокутника: "; cin >> geo1;
	cout << "Введiть довжину 2ї сторони прямокутника: "; cin >> geo2;
	cout << "Довжина дiагоналi: " << sqrt(pow(geo1, 2) + pow(geo2, 2)) << endl; //обчислення діагоналі прямокутника

	geo1 += geo2;
	cout << "сума сторiн: " << geo1 << endl; //обчислення суми сторін..

	return 0; 
}