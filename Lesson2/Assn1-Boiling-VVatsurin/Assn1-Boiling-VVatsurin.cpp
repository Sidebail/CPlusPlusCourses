// Assn1-Boiling-VVatsurin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct SUBSTANCE
{
	string name;
	double boilingTemp = 0;
};

char currentScale = 'C';

void changeScale(char scaleLetter) {
	try
	{
		switch (scaleLetter)
		{
		case 'c':
		case 'C':
			currentScale = 'C';
			break;
		case 'k':
		case 'K':
			currentScale = 'K';
			break;
		case 'f':
		case 'F':
			currentScale = 'F';
			break;
		default:
			cout << "Wrong scale letter! Try again! Error code: 30" << endl;
			break;
		}
	}
	catch (const std::exception&)
	{

	}
}


string outputSubstance(double input, SUBSTANCE substances[]) {

	for (int i = 0; i <= sizeof(substances); i++)
	{
		switch (currentScale)
		{
		case 'C': 
			if ((substances[i].boilingTemp * 0.95) <= input && input <= (substances[i].boilingTemp * 1.05)) {
				cout << substances[i].boilingTemp * 0.95 << " / " << input << substances[i].boilingTemp * 1.05;
				return "The substance is " + substances[i].name;
				
			}
			break;
		case 'K':
			if ((((substances[i].boilingTemp + 273) * 0.95) <= input && input <= ((substances[i].boilingTemp + 273) * 1.05))) {
				return "The substance is " + substances[i].name;
			}
			break;
		case 'F':
			if ((((substances[i].boilingTemp * 9 / 5 + 32) * 0.95)) <= input && input <= ((substances[i].boilingTemp * 9 / 5) + 32) * 1.05) {
				return "The substance is " + substances[i].name;
			}
			break;
		default:
			break;
		}

	}
	return "Sorry, but the substance is unknown!";
}

void createMenu() {
	cout << endl << "Welcome to the substance identifier" << endl;
	cout << "Please select from the following :" << endl;
	cout << "1. Select Temperature Scale" << endl;
	cout << "2. Enter Observed Boiling Point" << endl;
	cout << "3. Exit" << endl;
	cout << "Your selection: ";
}


int main()
{
	
	SUBSTANCE water;
	water.name = "Water";
	water.boilingTemp = 100;
	SUBSTANCE mercury;
	mercury.name = "Mercury";
	mercury.boilingTemp = 357;
	SUBSTANCE copper;
	copper.name = "Copper";
	copper.boilingTemp = 1187;
	SUBSTANCE silver;
	silver.name = "Silver";
	silver.boilingTemp = 2193;
	SUBSTANCE gold;
	gold.name = "Gold";
	gold.boilingTemp = 2660;

	SUBSTANCE substances[5] = { water, mercury, copper, silver, gold };

	bool bProgEnded = false;
	while (!bProgEnded) {

		createMenu();
		int selectionNumber = 0;

		cin >> selectionNumber;

		cout << selectionNumber << endl;;

		switch (selectionNumber)
		{
		case 1:
			cout << "Please, enter the desired temperature scale from the following:" << endl;
			cout << "      C or c - Degrees Celcius" << endl;
			cout << "      K or k - Degrees Kelvin" << endl;
			cout << "      F or f - Degrees Fahrenheit" << endl;
			char scaleLetter;
			cin >> scaleLetter;
			cout << endl;
			changeScale(scaleLetter);
			break;
		case 2:
			cout << "Please, enter the observed boiling point in " << currentScale << ": ";
			double observedPoint;
			cin >> observedPoint;
			cout << endl;
			cout << outputSubstance(observedPoint, substances) << endl;
			break;
		case 3:
			cout << "Thank your for using identifier" << endl;
			exit(123);
			break;
		default:
			cout << "Wrong input! Try again! Error code: 144" << endl;
			break;
		}

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong input! Try again! Error code: 149" << endl;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
