#include <iostream>
#include <locale>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

string defX(int* Des, int* coef);
string parabol(int* coef);
int twoParabols();
int generateC(int min, int max);
int fixedC();

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
				a[i] = generateC(-100, 100);
				if (i == 0 && a[i] == 0)
					a[i]++;
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

			cout << defX(&D, a) << endl;
		}

		//restart option

		string restart;
		restart:
		cout << "what you want?  (Y - Restart, N - Parabola properties, G - Restart and generate another coefs, P - Go to two parabols, C - Go to discriminant table with fixed coefficients): ";
		cin >> restart;
		cout << endl;
		char g = 'g';
		char p = 'p';
		char c = 'c';
		if (restart.length() > 1 || (tolower(restart[0]) != y && tolower(restart[0]) != n && tolower(restart[0]) != g && tolower(restart[0]) != p && tolower(restart[0]) != c)) {
			cout << "you must enter one value (Y or N)" << endl;
			goto restart;
		}
		else if (tolower(restart[0]) == y) continue;
		else if (tolower(restart[0]) == g) goto generateC;
		else if (tolower(restart[0]) == p) {
			twoParabols();
			break;
		}
		else if (tolower(restart[0]) == c) {
			fixedC();
			break;
		}
		else { 
			//checking the properties of a parabola based on coefficients

			cout << parabol(a) << endl; 
			break;
		}

	}

	

	return 0;
}

string defX(int* D, int* coef) {
	if (*D < 0)
		return "no roots";

	else if (*D == 0) {
		double x = ((0.0f - *(coef + 1)) + sqrt(*D)) / (2.0f * *coef);
		string out = "x = " + to_string(x);
		return out;
	}

	else if (*D > 0) {
		double x1 = ((0.0f - *(coef + 1)) + sqrt(*D)) / (2.0f * *coef);
		double x2 = ((0.0f - *(coef + 1)) - sqrt(*D)) / (2.0f * *coef);
		string out = "x1 = " + to_string(x1) + "; x2 = " + to_string(x2);
		return out;
	}
	else return "error";
};

string parabol(int* coef) {
	//y = ax^2 + bx + c

	string result = "";

	//checking the direction of the branches
	if (*coef > 0) 
		result += "The branches of the parabola point upwards. ";
	else 
		result += "The branches of the parabola point downward. ";

	//top x
	int topx = 0 - (*(coef + 1) / (2 * (*coef)));
	result += "top x = " + to_string(topx) + " ";

	//top y
	int topy = (*coef * (topx * topx)) + (*(coef + 1) * topx) + *(coef + 2);
	result += "top y = " + to_string(topy) + " ";

	//Definition area
	result += "Definition area is (-inf, +inf). ";

	//Value range
	if (*coef > 0) 
		result += "Value range is [" + to_string(topy) + ", +inf). ";
	else
		result += "Value range is (-inf, " + to_string(topy) + "]. ";

	return result;
}


int generateC(int min, int max) {
	if (min < 0)
		max -= min;
	int i = (rand() % max) + min;
	srand(time(NULL) + i);
	return i;
}


int twoParabols() {

	//setting the values of parabols

	string a;
	char n = 'n';
	char y = 'y';
	int parabolA[3];
	int parabolB[3];
	par:
	cout << "Do you want to automatically generate numbers? (Y/N): ";
	cin >> a;
	cout << endl;
	if (a.length() > 1 || (tolower(a[0]) != y && tolower(a[0]) != n)) {
		cout << "you must enter one value (Y or N)" << endl;
		goto par;
	}

	else if (tolower(a[0]) == y) {
		for (int p = 0; p < 3; p++) {
			parabolA[p] = generateC(-100, 100);
			if (p == 0 && parabolA[p] == 0) parabolA[p]++;
			parabolB[p] = generateC(-100, 100);
			if (p == 0 && parabolB[p] == 0) parabolB[p]++;
		}
		cout << "generated numbers of first parabola:" << endl;
		for (int p = 0; p < 3; p++) {
			if (p == 2) cout << parabolA[p];
			else cout << parabolA[p] << ", ";
		}
		cout << endl;
		cout << "generated numbers of second parabola:" << endl;
		for (int p = 0; p < 3; p++) {
			if (p == 2) cout << parabolB[p];
			else cout << parabolB[p] << ", ";
		}
		cout << endl;
	}

	else if (tolower(a[0]) == n) {
		for (int p = 0; p < 3; p++) {
			ParA:
			cout << "Enter the value " << p + 1 << " of the first parabola: ";
			cin >> parabolA[p];
			cout << endl;
			if (p == 0 && parabolA[p] == 0) {
				cout << "coefficient 1 cannot = 0" << endl;
				goto ParA;
			}
			ParB:
			cout << "Enter the value " << p + 1 << " of the second parabola: ";
			cin >> parabolB[p];
			cout << endl;
			if (p == 0 && parabolB[p] == 0) {
				cout << "coefficient 1 cannot = 0" << endl;
				goto ParB;
			}
		}
	}

	else {
		cout << "ERROR" << endl;
		return 0;
	}
	//checking parabols parameters

	cout << "first parabola: " << parabol(parabolA) << endl;
	cout << "second parabola: " << parabol(parabolB) << endl;

	//checking if they intersect
	int parR[3];
	parR[0] = parabolA[0] - parabolB[0];
	parR[1] = parabolA[1] - parabolB[1];
	parR[2] = parabolA[2] - parabolB[2];
	float Des = (parR[1] * parR[1]) - (4 * (parR[0] * parR[2]));
	if (Des < 0) {
		cout << "parabols do not intersect" << endl;
	}
	else if (Des == 0) {
		cout << "parabols intersect in one point:" << endl;
		float x = ((0 - parR[1]) + sqrt(Des)) / (2 * parR[0]);
		float y = (parabolA[0] * (x * x)) + (parabolA[1] * x) + parabolA[2];
		cout << "( " << x << ", " << y << ")" << endl;
	}
	else if (Des > 0) {
		cout << "parabols intersect in two points:" << endl;
		float x1 = ((0 - parR[1]) + sqrt(Des)) / (2 * parR[0]);
		float y1 = (parabolA[0] * (x1 * x1)) + (parabolA[1] * x1) + parabolA[2];
		cout << "( " << x1 << ", " << y1 << ")" << endl;

		float x2 = ((0 - parR[1]) - sqrt(Des)) / (2 * parR[0]);
		float y2 = (parabolB[0] * (x2 * x2)) + (parabolB[1] * x2) + parabolB[2];
		cout << "( " << x2 << ", " << y2 << ")" << endl;
	}
	return 0;
}

int fixedC() {
	string f;
	string s;
	char a = 'a';
	char b = 'b';
	char c = 'c';
	int coef[3];

	//determining the values that will be fixed

firstN:

	//first value

	cout << "enter the first value you will fixed (a, b, c): "; cin >> f; cout << endl;
	if (f.length() > 1 || (tolower(f[0]) != a && tolower(f[0]) != b && tolower(f[0]) != c)) {
		cout << "you must enter one value (a, b or c)" << endl;
		goto firstN;
	}

secondN:

	//second value

	cout << "enter the second value you will fixed (a, b, c): "; cin >> s; cout << endl;
	if (s.length() > 1 || (tolower(s[0]) != a && tolower(s[0]) != b && tolower(s[0]) != c)) {
		cout << "you must enter one value (a, b or c)" << endl;
		goto secondN;
	}

	else if (tolower(f[0]) == tolower(s[0])) {
		cout << "you will fixed only two values" << endl;
		goto secondN;
	}
	//setting these values

	else {
		char y = 'y';
		char n = 'n';
		string gen;
		int s1 = 0;
		int s2 = 0;
		int s3 = 0;
	gen:

		//generating values or writing them manually

		cout << "Do you want generate the values? (Y/n): "; cin >> gen; cout << endl;
		if (gen.length() > 1 || (tolower(gen[0]) != y && tolower(gen[0]) != n)) {
			cout << "you must enter one value (Y or N)" << endl;
			goto gen;
		}

		//manually

		else if (tolower(gen[0]) == n) {
			if (tolower(f[0]) == a) {
				s1 = 1;
				cout << "enter the coef a: "; cin >> coef[0]; cout << endl;
			}
			else if (tolower(f[0]) == b) {
				s2 = 1;
				cout << "enter the coef b: "; cin >> coef[1]; cout << endl;
			}
			else if (tolower(f[0]) == c) {
				s3 = 1;
				cout << "enter the coef c: "; cin >> coef[2]; cout << endl;
			}
			if (tolower(s[0]) == a) {
				s1 = 1;
				cout << "enter the coef a: "; cin >> coef[0]; cout << endl;
			}
			else if (tolower(s[0]) == b) {
				s2 = 1;
				cout << "enter the coef b: "; cin >> coef[1]; cout << endl;
			}
			else if (tolower(s[0]) == c) {
				s3 = 1;
				cout << "enter the coef c: "; cin >> coef[2]; cout << endl;
			}
		}
		
		//generating

		else if (tolower(gen[0]) == y) {
			if (tolower(f[0]) == a) {
				s1 = 1; 
				coef[0] = generateC(-100, 100);
				cout << "coefficiant a is: " << coef[0] << endl;
			}
			else if (tolower(f[0]) == b) {
				s2 = 1;
				coef[1] = generateC(-100, 100);
				cout << "coefficiant b is: " << coef[1] << endl;
			}
			else if (tolower(f[0]) == c) {
				s3 = 1;
				coef[2] = generateC(-100, 100);
				cout << "coefficiant c is: " << coef[2] << endl;
			}
			if (tolower(s[0]) == a) {
				s1 = 1;
				coef[0] = generateC(-100, 100);
				cout << "coefficiant a is: " << coef[0] << endl;
			}
			else if (tolower(s[0]) == b) {
				s2 = 1;
				coef[1] = generateC(-100, 100);
				cout << "coefficiant b is: " << coef[1] << endl;
			}
			else if (tolower(s[0]) == c) {
				s3 = 1;
				coef[2] = generateC(-100, 100);
				cout << "coefficiant c is: " << coef[2] << endl;
			}
		}

		//creating and displaying a discriminant table

		cout << "number that is being moved / discriminant" << endl;
		if (s1 == 0) {
			for (int i = -10; i <= 10; i++) {
				coef[0] = i;
				int d = (coef[1] * coef[1]) - (4 * coef[0] * coef[2]);
				cout << i << "  /  " << d << endl;
			}
		}
		else if (s2 == 0) {
			for (int i = -10; i <= 10; i++) {
				coef[1] = i;
				int d = (coef[1] * coef[1]) - (4 * coef[0] * coef[2]);
				cout << i << "  /  " << d << endl;
			}
		}
		else if (s3 == 0) {
			for (int i = -10; i <= 10; i++) {
				coef[2] = i;
				int d = (coef[1] * coef[1]) - (4 * coef[0] * coef[2]);
				cout << i << "  /  " << d << endl;
			}
		}
	}
	return 0;
}