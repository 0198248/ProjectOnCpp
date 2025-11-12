#include <iostream>
#include <ctime>

using namespace std;

int generate(int min, int max);
void PIN(int PINn, int balance);

void openMenu(int PINn, int balance) {
	cout << ">> view balance (1)" << endl;
	cout << ">> deposit funds (2)" << endl;
	cout << ">> withdraw funds (3)" << endl;
	cout << ">> log out (4)" << endl;
	actionC:

	cout << "choose action: ";
	int action;
	cin >> action;
	cout << endl;

	switch (action) {
	case 1:
		cout << "Your balance: " << balance << endl << endl;
		openMenu(PINn, balance);
		break;
	case 2:
		depos:
		int deposit;
		cout << "the amount you want to deposit: ";
		cin >> deposit;
		cout << endl;
		if (deposit > 0)
			balance += deposit;
		else {
			cout << "wrong number" << endl;
			goto depos;
		}
		openMenu(PINn, balance);
		break;
	case 3:
		int withdraw;
		with1:
		cout << "the amount you want to withdraw: ";
		cin >> withdraw;
		cout << endl;

		if (balance > withdraw)
			if (withdraw > 0)
				balance -= withdraw;
			else {
				cout << "wrong number" << endl;
				goto with1;
			}
		else
			cout << "Your balance is too low" << endl;
		openMenu(PINn, balance);
		break;
	case 4:
		PIN(PINn, balance);
		break;
	default:
		cout << "error (enter the number (1-4))" << endl;
		goto actionC;
		break;
	}
}
void PIN(int PINn, int balance) {
	int num;
	p1:
	cout << "Enter the PIN: ";
	cin >> num;
	cout << endl;
	if (PINn == num)
		openMenu(PINn, balance);
	else {
		cout << "PIN is incorrect" << endl;
		goto p1;
	}
}

int main()
{
	srand(time(NULL));
    setlocale(LC_ALL, "uk_UA");

	int balance = generate(0, 10000);
	int PINn;

	cout << "enter new PIN : ";
	cin >> PINn;
	cout << endl << endl;

	PIN(PINn, balance);


}

int generate(int min, int max) {
	if (min < 0)
		max -= min;
	int i = (rand() % max) + min;
	srand(time(NULL) + i);
	return i;
}