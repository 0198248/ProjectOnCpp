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
	cout << "������� �����: " << pow(a, b) << " ���i��: " << sqrtf(a * -1) << " abs: " << abs(a) << " ����������: " << ceil(a) << " ������ �����: " << fabs(a) << endl; //�������� � �������

	bool c = 0;
	if (!c) cout << "bool is false" << endl; else cout << "bool is true" << endl; //�������� � �������� ����������

	string d = "Hello";
	char h[] = "Hello";
	cout << "word: " << d << endl;
	cout << "length: " << d.length() << " substr: " << d.substr(2, 3) << " �� �����i�: " << d.find("llo") + 1 << "; toupper | tolower: "; for (int x = 0; x < strlen(h); x++) putchar(toupper(h[x])); cout << " | "; for (int x = 0; x < strlen(h); x++) putchar(tolower(h[x])); cout << endl; //�������� � �������

	int geo1, geo2;
	cout << "����i�� ������� 1� ������� ������������: "; cin >> geo1;
	cout << "����i�� ������� 2� ������� ������������: "; cin >> geo2;
	cout << "������� �i������i: " << sqrt(pow(geo1, 2) + pow(geo2, 2)) << endl; //���������� ������� ������������

	geo1 += geo2;
	cout << "���� ����i�: " << geo1 << endl; //���������� ���� �����..

	return 0; 
}