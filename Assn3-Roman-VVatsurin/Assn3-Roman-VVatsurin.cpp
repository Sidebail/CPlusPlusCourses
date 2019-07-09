// Assn3-Roman-VVatsurin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* TODO: COMMENT THAT SHIT OUT*/
#include <iostream>
#include <string>
using namespace std;

int menuInput = 0;
void mainMenu();
int RomanToTen(string roman);
string TenToRoman(int ten);



int RomanToTen(string roman) {
	int output = 0;
	string newRoman = roman;
	for (int i = 0; i < roman.length() - 1; i++) {
		string temp = { roman[i],roman[i + 1] };
		if (temp == "IV") {roman.replace(i, 2, "II"); roman.insert(i+1,"II");};
		if (temp == "IX") { roman.replace(i, 2, "VI"); roman.insert(i+1,"III");};
		if (temp == "XL") { roman.replace(i, 2, "XX"); roman.insert(i+1,"XX");};
		if (temp == "XC") { roman.replace(i, 2, "LX"); roman.insert(i+1,"XXX");};
		if (temp == "CD") { roman.replace(i, 2, "CC"); roman.insert(i+1,"CC");};
		if (temp == "CM") { roman.replace(i, 2, "DC"); roman.insert(i+1,"CCC");};
	}
	cout << roman << endl;
	for (int i = 0; i < roman.length(); i++) {
	
		switch (roman[i])
		{
		case 'I': output = output + 1; break;
		case 'V': output = output + 5; break;
		case 'X': output = output + 10; break;
		case 'L': output = output + 50; break;
		case 'C': output = output + 100; break;
		case 'D': output = output + 500; break;
		case 'M': output = output + 1000; break;
		default:
			break;
		}
	}

	return output;

}

string TenToRoman(int ten) {
	string output = "";
	while(ten >= 1000) { ten -= 1000; output.append(1, 'M'); }
	while (ten >= 500) { ten -= 500; output.append(1, 'D'); }
	while (ten >= 100) { ten -= 100; output.append(1, 'C'); }
	while (ten >= 50) { ten -= 50; output.append(1, 'L'); }
	while (ten >= 10) { ten -= 10; output.append(1, 'X'); }
	while (ten >= 5) { ten -= 5; output.append(1, 'V'); }
	while (ten >= 1) { ten -= 1; output.append(1, 'I'); }

	for (int i = 0; i < output.length() - 3; i++) {
		string temp = { output[i],output[i + 1],output[i + 2],output[i + 3]};
		if (temp == "IIII") { if (output[i - 1] == 'V') { output.replace(i - 1, 5, "IX"); } else { output.replace(i, 4, "IV"); } };
		if (temp == "XXXX") { if (output[i - 1] == 'L') { output.replace(i - 1, 5, "XC"); } else { output.replace(i, 4, "XL"); } };
		if (temp == "CCCC") { if (output[i - 1] == 'D') { output.replace(i - 1, 5, "CM"); } else { output.replace(i, 4, "CD"); } };
	}

	return output;
}

string AddRomans(string rom1, string rom2) {
	int ten1 = RomanToTen(rom1);
	int ten2 = RomanToTen(rom2);
	return TenToRoman(ten1 + ten2);
}

void inputController(int menuInput) {
	string romanInput;
	int tenInput;
	string addFirstInp;
	string addSecondInp;
	switch (menuInput)
	{
	case 1: 
		cout << "Please, type in correct Roman number: ";
		cin >> romanInput;
		cout << "Your Roman number: " << romanInput << endl;
		cout << "In Base 10 this is: " << RomanToTen(romanInput) << endl;
		mainMenu();
		break;
	case 2:
		cout << "Please, type in base 10 number(greater then 0, less then 9999): ";
		cin >> tenInput;
		if (tenInput < 0 || tenInput > 9999) { cout << "Sorry, invalid input, returning to main menu" << endl << endl; mainMenu(); break; }
		cout << "Your Base 10 number: " << tenInput << endl;
		cout << "In Roman numerals this is: " << TenToRoman(tenInput) << endl;
		mainMenu(); 
		break;
	case 3: 
		cout << "Please, type in first valid roman number: ";
		cin >> addFirstInp;
		cout << "Please, type in first valid roman number: ";
		cin >> addSecondInp;
		cout << "Sum of " << addFirstInp << " and " << addSecondInp << " = " << AddRomans(addFirstInp, addSecondInp) << endl;
		mainMenu();
		break;
	case 4: cout << "Spasibo!" << endl; exit(4);
	default:
		cout << "Wrong input! Try Again!" << endl;
		mainMenu();
		break;
	}
}

/*Main menu output*/
void mainMenu() {
	cout << endl << "1. Roman numeral to base 10" << endl;
	cout << "2. Base 10 to Roman numeral" << endl;
	cout << "3. Add 2 Romans numerals" << endl;
	cout << "4. Exit" << endl;
	cin >> menuInput;
	inputController(menuInput);
}

int main()
{
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
