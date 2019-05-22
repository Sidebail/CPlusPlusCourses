/**
Assignment 1
Vladimir Vatsurin
200363172
*/

//F(t) = 33.2 + 16.8t

#include <iostream>
#include <string>

using namespace std;

/*
Check the input if year is integer and is greater than 2005
*/
bool checkInput(int input) {
	if (input > 2005 && typeid(input)==typeid(2005)) {
		return true;
	}
	else {
		return false;
	}
}

/*
Main function. Promts the user for input, handles it using the checkInput fucntion and outputs the result while making the expression F(t) = 33.2 + 16.8t
*/
int main() {
	string s;

	start:
	cout << "Welcome to the Take Away modeller." << endl;
	cout << "Please enter a year to model the billions of fast food charges that is greater than 2005. Note:" << endl;
	cout << "-If you enter 2005 or less you will be re - asked to provide a valid year" << endl;
	cout << "- To exit the application please enter  \"0\"" << endl;
	cout << "What year would you like to model : " << endl;

	cin >> s;

	int t = std::stoi(s);

	if (checkInput(t)) {
		cout << "The predicted sales in billions of dollars in " << t << " is $" << 33.2 + 16.8 * (t - 2005) << " Billions" << endl << endl;
	}
	else {
		if (t == 0) {
			exit(0);
		}
		else {
			cout << "The year you entered is invalid. Please try again." << endl;
			cout << endl;
			goto start;
		}
	}

	goto start;
	return 0;
	
}

