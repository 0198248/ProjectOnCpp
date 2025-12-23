#include <iostream>
#include <cmath>

using namespace std;

float SUM(float n1, float n2) {
	return n1 + n2;
}
bool SNum(float num) {
	if (num == (float)(round(num))) {
		return true;
	}
	return false;
}

void Factorial(float num) {
	int fact = 1;
	for (int i = 1; i <= num; i++) {
		fact *= i;
	}
	cout << "Factorial is: " << fact << endl;
}

void Average(int a[]) {
	float sum = 0;
	for (int i = 0; i < (sizeof(a) / sizeof(*a)); i++) {
		sum += a[i];
	}

	cout << "Average is:" << sum / (sizeof(a) / sizeof(*a)) << endl;
}

int Fibonachi(int num) {
	if (num != 1 && num != 0) {
		return Fibonachi(num - 1) + Fibonachi(num - 2);
	}
	else
		return num;

}
int main()
{
	float num1, num2;

	cout << "enter the number 1: ";
	cin >> num1;
	cout << endl;

	cout << "enter the number 2: ";
	cin >> num2;
	cout << endl;

	if (SNum(SUM(num1, num2)))
		cout << "number is simple" << endl;

	if (SNum(SUM(num1, num2))) {
		Factorial(SUM(num1, num2));
	}

	int a[5];

	cout << "numbers is: ";

	for (int i = 0; i < (sizeof(a) / sizeof(*a)); i++) {
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;

	Average(a);

	if (SNum(SUM(num1, num2))) {
		cout << "Fibonachi is: " << Fibonachi((int)round(SUM(num1, num2))) << endl;
	}

	return 0;
}
