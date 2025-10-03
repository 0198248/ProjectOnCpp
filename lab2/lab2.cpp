#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>


using namespace std;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "uk_UA");

	const int number = 1 + (rand() << (1 + rand() % 10)) % 10000000;
	float floatPointNumber = 4.48f;
	char percent = '%';
	string text = "Hello World"; //creating variables and assigning values

	cout << "random number is: " << number << endl
		<< "float number is: " << floatPointNumber << endl
		<< "char is: " << percent << endl
		<< "text is: " << text << endl; //output of values


	int Unum;
	cout << "enter the number by which to divide the random number: ";
	cin >> Unum; //getting  1 number

	Unum = number / Unum;
	cout << Unum << endl; //operation with number

	time_t timestamp;
	time(&timestamp);

	cout << "date: " << ctime(&timestamp) << endl; //date output

	int numbers[5];
	for (int i = 0; i < 5; i++) {
		cout << endl << "enter number" << i + 1 << ": ";
		cin >> numbers[i];
	}												//getting numbers

	int length = (sizeof numbers / sizeof * numbers);

	int average = numbers[0];
	for (int i = 0; i < length; i++) {
		average += numbers[i];
	}
	cout << endl << "average:" << average / length << endl; //average of these numbers

	int min = numbers[0];
	for (int i = 0; i < length; i++)
		if (min > numbers[i]) min = numbers[i];
	cout << "minimum number is: " << min << endl;   //minimum of these numbers

	int max = numbers[0];
	for (int i = 0; i < length; i++)
		if (max < numbers[i]) max = numbers[i];
	cout << "maximum number is: " << max << endl; //maximum of these numbers

	int sum = numbers[0];
	for (int i = 1; i < length; i++)
		sum += numbers[i];
	cout << "summa of numbers is: " << sum << endl; //summa of these numbers

	return 0;
}