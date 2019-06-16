// Assn2-Battery-VVatsurin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void inputController(int input);

struct BATTERY {
	double voltage;
	double energy;
	double capacity;
	string type;
	void display() {
		cout << "Battery charasteristics: " << endl;
		cout << "Voltage - " << voltage << " V" << endl;
		cout << "Current energy - " << energy << " J" << endl;
		cout << "Battery capacity - " << capacity << " J" << endl;
		cout << "Type - " << type << endl << endl;
	};
};

BATTERY power_device(double deviceCurrent, double time, BATTERY battery) {
	//P= I * V; W = P * t; W = I * V * t
	if (deviceCurrent * battery.voltage * time <= battery.energy)
	{
		battery.energy = battery.energy - deviceCurrent * time * battery.voltage;
		cout << "The device is charged. Battery has " << battery.energy << " J" << endl;
	}
	else {
		cout << "Not enough energy to power-up the device. Battery has " << battery.energy << " J" << ", while " << deviceCurrent * battery.voltage * time << " J needed" <<  endl;
	}

	return battery;
}

double max_time(BATTERY battery, double deviceCurrent) {
	//(a > b) ? a : b;
	return (battery.energy > 0) ? battery.energy / (deviceCurrent * battery.voltage) : 0;
}

BATTERY recharge(BATTERY battery) {
	battery.energy = battery.capacity;
	return battery;
}

/*  double voltage;
	double energy;
	double capacity;
	string type;
*/
BATTERY duracel = {
	12,
	5 * 1000000,
	5 * 1000000,
	"Lithium"
};

/*
	MENU
*/

void mainMenu() {
	int choice = 0;
	cout << "Welcome to the battery management utility" << endl;
	cout << "Please, choose one of the options: " << endl;
	cout << "1. Power up a device" << endl;
	cout << "2. Check the expected work time for a device using the battery" << endl;
	cout << "3. Recharge the battery" << endl;
	cout << "4. Get a new battery" << endl;
	cout << "5. Exit" << endl;
	cin >> choice;
	inputController(choice);
}

void inputController(int input) {
	switch (input)
	{
	case 1: 
		double deviceAmps;
		double time;
		cout << "Input the current in Amps of the suggested device: ";
		cin >> deviceAmps;
		cout << endl << "Input the desired work time in seconds: ";
		cin >> time;
		cout << endl;
		duracel = power_device(deviceAmps, time, duracel);
		cout << endl;
		mainMenu();
		break;
	case 2: 
		double deviceAmps2;
		cout << "Input the current in Amps of the suggested device: ";
		cin >> deviceAmps2;
		cout << "The expected worktime is: " << max_time(duracel, deviceAmps2) << endl;
		mainMenu();
		break;
	case 3:
		duracel = recharge(duracel);
		cout << "Battery is fully charged!" << endl;
		mainMenu();
		break;
	case 4:
		duracel = {
			12,
			5 * 1000000,
			5 * 1000000,
			"Lithium"
		};
		cout << "Battery is changed to a new one!" << endl;
		duracel.display();
		mainMenu();
		break;
	case 5:
		cout << "Thank you for using the app!";
		exit(118);
	default:
		cout << "Wrong input! Try again!" << endl;
		mainMenu();
		break;
	}
}

int main()
{
	duracel = power_device(4, 15 * 60, duracel);
	
	cout << "Battery can power up the 8 amp light for " << max_time(duracel, 8) << endl;
	
	duracel = recharge(duracel);
	
	cout << "Battery can power up the 8 amp light for " << max_time(duracel, 8) << endl;
	mainMenu();
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
