// temp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>


int mainMenu();
char tempMenu();
int userTemp();
using namespace std;
char tempMenuChoice = 'c';
int main()
{

	cout << "Welcome to the substance identifier." << endl << endl;
	string substances[5] = { "Water","Mercury","Copper","Silver","Gold" };
	int boilTemp[5] = { 100, 357, 1187, 2193, 2660 };
	int userChoice = mainMenu();
	//char tempScale = tempMenu();

	if (userChoice == 1) {
		tempMenuChoice = tempMenu();
	}
	else if (userChoice == 2) {
		cout << tempMenuChoice;
		int userTemperature = userTemp();
		cout << tempMenuChoice << "//" << userTemperature;
		//int x = std::distance(boilTemp, std::find(boilTemp, boilTemp + 4, userTemp));	
		//cout << substances[x];
	}
	else if (userChoice == 3) {
		return 0;
	}
}
int mainMenu() {
	int uc;

	cout << "Please select from the following :" << endl << endl;
	cout << "1. Select Temperature Scale" << endl;
	cout << "2. Enter Observed Boiling Point" << endl;
	cout << "3. Exit" << endl << endl;
	cout << "Your selection: ";
	cin >> uc;
	cout << "\n________" << endl;
	return uc;
}
char tempMenu() {
	char temp;
	cout << "Please enter the desired temperature scale from the following :" << endl << endl;
	cout << "C or c – Degrees Celsius" << endl;
	cout << "F or f – Degrees Fahrenheit" << endl;
	cout << "K or k – Degrees Kelvin" << endl << endl;
	cout << "Your selection: ";
	cin >> temp;
	cout << "\n________" << endl;
	mainMenu();
	return temp;
}
int userTemp() {
	int ut;
	cout << "Please enter the observed boiling point in : ";
	cin >> ut;
	if (tempMenuChoice == 'c') {
		return ut;
	}
	else if (tempMenuChoice == 'f') {
		return (ut - 32) * 5 / 9;
	}
	else if (tempMenuChoice == 'k') {
		return ut - 273;
	}
}


