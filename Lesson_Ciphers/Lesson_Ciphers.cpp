// Lesson_Ciphers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

struct structData {
	string Original, Modified;
};

int main()
{
    std::cout << "Hello World!\n"; 

	int intUserSelection;
	int intNumberVowels = 0;
	structData Data1;
	char chrCompare[5] = { 'a','e','i','o','u' };
	
	
	do {
		cout << endl << "1. Enter string, 2. Update String, 3. Return String, 4.Exit" << endl;
		cout << "Your selection: "; cin >> intUserSelection;

		switch (intUserSelection)
		{
		case 1: cout << "Please enter the string without numbers: "; cin >> Data1.Original; Data1.Modified = Data1.Original; break;
		case 2: 
			for (int j = 0; j < Data1.Original.length(); j++) {
				for (int i = 0; i < 5; i++) {
					if (Data1.Original.at(j) == chrCompare[i]) {
						Data1.Modified.replace(j, 1, to_string(i+1));
						intNumberVowels++;
					}
				}
			}
			cout << Data1.Modified;
			break;
		case 3: 
			for (int i = 0; i < 5; i++) {
				int x = Data1.Modified.find(to_string(i + 1));
				while (x<Data1.Modified.size())
				{
					string temp(1, chrCompare[i]);
					Data1.Modified.replace(x, 1, temp);
					x = Data1.Modified.find(to_string(i + 1));
					intNumberVowels--;
				}
			}
			cout << Data1.Modified;
			break;
		default:
			break;
		}
	} while (intUserSelection != 4);

	cout << "Thanks for using the app!";

	return 0;

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
