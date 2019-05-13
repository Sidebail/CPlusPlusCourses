/**
Assignment 1
Vladimir Vatsurin
200363172
*/

//F(t) = 33.2 + 16.8t

#include <iostream>

using namespace std;

bool checkInput(int input) {
	if (input > 2005) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int t = 0;

	start:
	cout << "Welcome to the Take Away modeller." << endl;
	cout << "Please enter a year to model the billions of fast food charges that is greater than 2005. Note:" << endl;
	cout << "-If you enter 2005 or less you will be re - asked to provide a valid year" << endl;
	cout << "- To exit the application please enter “0”" << endl;
	cout << "What year would you like to model : " << endl;

	cin >> t;

	if (checkInput(t)) {
		cout << "The predicted sales in billions of dollars in "<< t << " is $" << 33.2 + 16.8 * (t-2005) << " Billions" << endl;
	}
	else {
		cout << "The year you entered is invalid. Please try again." << endl;
		goto start;
	}

	return 0;
	
}

