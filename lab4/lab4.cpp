#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum typeOfTemperature
{
	Celsius,   //0
	Farengeytus,   //1
	Kelvinum //2
};

int returnInCelsius(typeOfTemperature type, int value) {
	if (type == 0)
		return value;
	else if (type == 1) {
		int farengetum = (value - 32) * (5 / 9);
		return farengetum;
	}
	else if (type == 2) {
		if (value < 0) {
			cout << "error: kelvinum cannot be minus" << endl;
		}
		else {
			int kelvinum = value - 273.15;
			return kelvinum;
		}
	}
	else 
		cout << "error in calculations (100)" << endl;
}

int doOperation(typeOfTemperature inType, int value, typeOfTemperature outType) {
	int celsius = returnInCelsius(inType, value);
	if (outType == 0)
		return celsius;
	else if (outType == 1) {
		int farengetum = (celsius * (9 / 5)) + 32;
		return farengetum;
	}
	else if (outType == 2) {
		int kelvinum = celsius + 273.15;
		return kelvinum;
	}
	else 
		cout << "error of calculations (101)" << endl;
}

int main() {
	setlocale(LC_ALL, "uk_UA");

	string Temp;
temp1:

	cout << "Enter value of temperature and type of temperature(C - celsius, F - farengetum, K - kelvinum)(like (366F or -77K or 8545413C)):";
	cin >> Temp;
	cout << endl;
	char k = 'k', c = 'c', f = 'f';
	typeOfTemperature inType;

	if (tolower(Temp[Temp.length() - 1]) != k && tolower(Temp[Temp.length() - 1]) != c && tolower(Temp[Temp.length() - 1]) != f) {
		cout << "error in input (Enter like (77F or  55K)) (000)" << endl;
		Temp = "";
		goto temp1;
	}
	else if (tolower(Temp[Temp.length() - 1]) == c)
		inType = Celsius;
	else if (tolower(Temp[Temp.length() - 1]) == k)
		inType = Kelvinum;
	else if (tolower(Temp[Temp.length() - 1]) == f)
		inType = Farengeytus;

	Temp.pop_back();

	string TempWithoutType = Temp;

	int tempValue;
	try {
		tempValue = stoi(TempWithoutType);
	}
	catch (const invalid_argument&) {
		cout << "error in input (Enter like (777F or  55K) (001))" << endl;
		goto temp1;
	}

	string typeTemp;
temp2:
	cout << "enter the temperature value you want to convert this to(C - celsius, F - farengetum, K - kelvinum):";
	cin >> typeTemp;
	cout << endl;
	typeOfTemperature outType;

	if (typeTemp.length() > 1 || (tolower(typeTemp[0]) != k && tolower(typeTemp[0]) != c && tolower(typeTemp[0]) != f)) {
		cout << "error in input (Enter like (k) or (f)) (000)" << endl;
		typeTemp = "";
		goto temp2;
	}
	else if (tolower(typeTemp[0]) == c)
		outType = Celsius;
	else if (tolower(typeTemp[0]) == k)
		outType = Kelvinum;
	else if (tolower(typeTemp[0]) == f)
		outType = Farengeytus;

	cout << doOperation(inType, tempValue, outType);

	return 0;
}