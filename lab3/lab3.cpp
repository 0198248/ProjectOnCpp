#include <iostream>
#include <locale>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

string defX(int D, int coef[3]);
string parabol(int coef[3]);
string twoParabols();

int main() {
	setlocale(LC_ALL, "uk_UA");

	srand(time(NULL));
	
	int a[3] = { 0,0,0 };

	while (true) {
		string randN;
		random:
		cout << "do you want generate random coefs? (Y - Yes, N - No): ";
		cin >> randN;
		cout << endl;
		char y = 'y';
		char n = 'n';
		

		if (randN.length() > 1 || (tolower(randN[0]) != y && tolower(randN[0]) != n)) {
			cout << "you must enter one value (Y or N)" << endl;
			goto random;
		}
		else if (tolower(randN[0]) == y) {
			//generate random coefs
			generateC:
			for (int i = 0; i < (sizeof(a) / sizeof(*a)); i++) {
				a[i] = (rand() % 200) - 100;
				if (i == 0 && a[i] == 0)
					a[i]++;
				srand(time(NULL) + a[i]);
				

			}
			cout << "a = " << a[0] << endl << "b = " << a[1] << endl << "c = " << a[2] << endl;
		}
		else if (tolower(randN[0]) == n) {
			//input coefs
			for (int i = 0; i < (sizeof(a) / sizeof(*a)); i++) {
				cout << "enter coefficient" << i + 1 << ": ";
				cin >> a[i];
				cout << endl;
			}
			//check coefs
			checkC:
			for (int i = 0; i < (sizeof(a) / sizeof(*a)); i++) {
				if (a[i] > 100 || a[i] < -100)
					cout << "coef" << i + 1 << " out of range -100 -- 100" << endl;
				else if (a[i] <= 100 || a[i] >= -100)
					cout << "coef" << i + 1 << " in range -100 -- 100" << endl;
				else {
					cout << "incorrect coefficient value, write another number: ";
					cin >> a[i];
					cout << endl;
					goto checkC;
				}
			}
		}

		//definition of discriminant
		if (a[0] == 0)
			cout << "the first value cannot be 0" << endl;
		else {
			int D = (a[1] * a[1]) - (4 * (a[0] * a[2]));
			cout << "discriminant = " << D << endl;

			//determination of unknowns
			cout << defX(D, a) << endl;
		}

		//restart option
		string restart;
		restart:
		cout << "do you want restart or go to parabola?  (Y - Restart, N - Parabola properties, G - restart and generate another coefs): ";
		cin >> restart;
		cout << endl;
		char g = 'g';
		if (restart.length() > 1 || (tolower(restart[0]) != y && tolower(restart[0]) != n && tolower(restart[0]) != g)) {
			cout << "you must enter one value (Y or N)" << endl;
			goto restart;
		}
		else if (tolower(restart[0]) == y) continue;
		else if (tolower(restart[0]) == g) goto generateC;
		else { 
			//checking the properties of a parabola based on coefficients
			cout << parabol(a) << endl; 
			break;
		}
	}

	

	return 0;
}

string defX(int D, int coef[3]) {
	if (D < 0)
		return "no roots";

	else if (D == 0) {
		double x = ((0.0f - coef[1]) + sqrt(D)) / (2.0f * coef[0]);
		string out = "x = " + to_string(x);
		return out;
	}

	else if (D > 0) {
		double x1 = ((0.0f - coef[1]) + sqrt(D)) / (2.0f * coef[0]);
		double x2 = ((0.0f - coef[1]) - sqrt(D)) / (2.0f * coef[0]);
		string out = "x1 = " + to_string(x1) + "; x2 = " + to_string(x2);
		return out;
	}
	else return "error";
};

string parabol(int coef[3]) {
	//y = ax^2 + bx + c

	string result = "";

	//checking the direction of the branches
	if (coef[0] > 0) 
		result += "The branches of the parabola point upwards. ";
	else 
		result += "The branches of the parabola point downward. ";

	//top x
	int topx = -(coef[1] / (2 * coef[0]));
	result += "top x = " + to_string(topx) + " ";

	//top y
	int topy = (coef[0] * (topx * topx)) + (coef[1] * topx) + coef[2];
	result += "top y = " + to_string(topy) + " ";

	//Definition area
	result += "Definition area is (-inf, +inf). ";

	//Value range
	if (coef[0] > 0) 
		result += "Value range is [" + to_string(topy) + ", +inf). ";
	else
		result += "Value range is (-inf, " + to_string(topy) + "]. ";

	return result;
}

string twoParabols() {

}