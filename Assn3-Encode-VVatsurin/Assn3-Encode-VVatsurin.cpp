// Assn3-Encode-VVatsurin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Assn3-Encode-VVatsurin.h"
using namespace std;

int menuInput = 0;
string original = "";
string prepared = "";
string encryptedXOR = "";
string encryptedCeaser = "";
string encryptedVigenere = "";
string decryptedVig = ""; // TAPE TIME!

char key;
int keyNum;
string keyVig;

char vigTable[26][26];

char input[100];

enum menuState{ start, ciphersEnc, ciphersDec};
enum menuState currentState;
void mainMenu();
void ciphersMenu();
void decipherMenu();

void populateVigTable() {
	for (int i = 0; i < 26; i++) {
		for (int j = 97; j < 123; j++) {
			int x = 0;
			if (j + i > 122) { x = 26; }
			vigTable[i][j - 97] = char(j+i-x);
			
		}
	}
}

void printVigTable() {
	for (int i = 0; i < 26; i++) {
		cout << endl;
		for (int j = 0; j < 26; j++) {
			cout << vigTable[i][j] << " ";
		}
	}
}

bool stringHasNumbers(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < 'a' || str[i] > 'z') {
			return true;
		}
	}

	return false;
}

string prepareString(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			str.erase(i, 1);
		}
		else {
			str[i] = tolower(str[i]);
		}

	}

	return str;
}


///////////////////////////////////////////
void EncryptXOR(char key, string str) {
	string output = "";
	cout << endl << "ASCII decimal numbers of each character: ";
	for (int i = 0; i < str.length(); i++) {
		//cout << (str[i] ^ key) << "  ";
		output.append(1,char(str[i]^key));
	}

	cout << endl;
	encryptedXOR = output;
}

string DecryptXOR(char key, string cipher) {
	string output = "";

	for (int i = 0; i < cipher.length(); i++) {
		output.append(1, key^cipher[i]);
	}

	return output;
}



/////////////////////////////////////////////

void EncryptVig(string key, string str) {
	string output = "";

	while (str.length() > key.length()) {
		//cout << str.length() << "//" << key.length() << endl;
		key.append(key);
		//cout << key << endl;
	}

	keyVig = key;

	for (int i = 0; i < str.length(); i++) {
		//cout << key[i] << " + " << str[i] << " = " << vigTable[int(key[i])-97][int(str[i])-97] << endl;
		output.append(1, vigTable[int(key[i])-97][int(str[i])-97]);
	}

	encryptedVigenere = output;
}

void DecryptVig(string key, string cipher) {
	string output = "";

	while (cipher.length() > key.length()) {
		//cout << str.length() << "//" << key.length() << endl;
		key.append(key);
		//cout << key << endl;
	}

	keyVig = key;

	for (int i = 0; i < cipher.length(); i++) {
		string temp = vigTable[int(key[i]) - 97];
		//cout << key[i] << " + " << char(temp.find(cipher[i]) + 97) << " = " << vigTable[1][temp.find(cipher[i])] << endl;
		output.append(1, char(temp.find(cipher[i]) + 97));
	}

	decryptedVig = output;
}


//////////////////////////////////////////////
void EncryptCeasar(int key, string str) {
	string output = "";

	for (int i = 0; i < str.length(); i++) {
		output.append(1, char((int(str[i] + key) % 97) % 26 + 97));
	}

	encryptedCeaser = output;
}

string DecryptCeasar(char key, string cipher) {
	string output = "";

	for (int i = 0; i < cipher.length(); i++) {
		output.append(1, char(((int(cipher[i] - key) + 26) % 97) % 26 + 97));
	}

	return output;
}
/////////////////////////////////////////////





void inputController(int menuInput) {
	
	switch (currentState)
	{
	case start:
		switch (menuInput)
		{
		case 1: 
			cout << "Please, enter a valid string, without numbers: " << endl; /////////CHECK!
			cin >> original;
			prepared = prepareString(original);
			cout << "Prepared string: " << prepared << endl;
			encryptedXOR = "";
			encryptedCeaser = "";
			encryptedVigenere = "";
			mainMenu();
			break;
		case 2:
			if (original != "")
			{
				ciphersMenu();
			}
			else {
				cout << "Original string is missing! Moving back to menu" << endl;
				mainMenu();
			}
			break;
		case 3: 
			if (encryptedXOR != "" || encryptedCeaser != "" || encryptedVigenere != "") {
				decipherMenu();
			}
			else {
				cout << "No encrypted string is found! Moving back to menu" << endl;
				mainMenu();
			}
			break;
		case 4:
			cout << "Thank you for using the app!";
			exit(777);
		default:
			cout << "Wrong input! Back to menu..." << endl << endl;
			mainMenu();
			break;
		}
		break;
	case ciphersEnc:
		switch (menuInput)
		{
		case 1:
			cout << "Enter the key: ";
			cin >> key;
			cout << "Original string: " << original << endl;
			cout << "Prepared string: " << prepared << endl;
			EncryptXOR(key, prepared);
			cout << "Encrypted string: " << encryptedXOR << endl;

			mainMenu();
			break;
		case 2:
			cout << "Enter the key: ";
			cin >> keyNum;
			cout << "Original string: " << original << endl;
			cout << "Prepared string: " << prepared << endl;
			EncryptCeasar(keyNum, prepared);
			cout << "Encrypted string: " << encryptedCeaser << endl;
			mainMenu();
			break;
		case 3:
			cout << "Enter the key, it has to have more than 3 letters, no numbers or spaces: ";
			cin >> keyVig;
			keyVig = prepareString(keyVig);
			if (stringHasNumbers(keyVig) || keyVig.length() < 3) {
				cout << "Key is not valid! Moving to main menu..." << endl;
				mainMenu();
				break;
			}
			else {
				cout << "Original string: " << original << endl;
				cout << "Prepared string: " << prepared << endl;
				EncryptVig(keyVig, prepared);
				cout << "Keyword: " << keyVig << endl;
				cout << "Encrypted string: " << encryptedVigenere << endl<<endl;

				mainMenu();
				break;

			}
		default:
			cout << "Wrong input! Back to menu..." << endl << endl;
			mainMenu();
			break;
		}
		break;
	case ciphersDec:
		switch (menuInput)
		{
		case 1:
			if (encryptedXOR != "") {
				cout << "Enter the key: ";
				cin >> key;
				cout << "Prepared string: " << prepared << endl;
				cout << "Encrypted string: " << encryptedXOR << endl;
				cout << "Decrypted string: " << DecryptXOR(key, encryptedXOR) << endl;
				mainMenu();
			}
			else {
				cout << "No encrypted string is found! Moving back to menu" << endl;
				mainMenu();
			}
			break;
		case 2:
			if (encryptedCeaser != "") {
				cout << "Enter the key: ";
				cin >> keyNum;
				cout << "Prepared string: " << prepared << endl;
				cout << "Encrypted string: " << encryptedCeaser << endl;
				cout << "Decrypted string: " << DecryptCeasar(keyNum, encryptedCeaser) << endl;
				mainMenu();
			}
			else {
				cout << "No encrypted string is found! Moving back to menu" << endl;
				mainMenu();
			}
			break;
		case 3:
			if (encryptedVigenere != "") {
				cout << "Enter the key, it has to have more than 3 letters, no numbers or spaces: ";
				cin >> keyVig;
				keyVig = prepareString(keyVig);
				if (stringHasNumbers(keyVig) || keyVig.length() < 3) {
					cout << "Key is not valid! Moving to main menu..." << endl;
					mainMenu();
					break;
				}
				else {
					cout << "Original string: " << original << endl;
					cout << "Prepared string: " << prepared << endl;
					cout << "Encrypted string: " << encryptedVigenere << endl;
					DecryptVig(keyVig, encryptedVigenere);
					cout << "Keyword: " << keyVig << endl;
					cout << "Decrypted string: " << decryptedVig << endl;
					mainMenu();
					break;

				}
			}
			else {
				cout << "No encrypted string is found! Moving back to menu" << endl;
				mainMenu();
			}
			break;
		default:
			cout << "Wrong input! Back to menu..." << endl << endl;
			mainMenu();
			break;
		}
		break;
	default:
		break;
	}
}


/*Main menu output*/
void mainMenu() {

	currentState = start;
	cout << endl << "1. Enter the string data" << endl;
	cout << "2. Encrypt the string" << endl;
	cout << "3. Decrypt the string" << endl;
	cout << "4. Exit" << endl;
	cin >> menuInput;
	inputController(menuInput);
}

void ciphersMenu() {
	currentState = ciphersEnc;
	cout << endl << "1. XOR Cipher" << endl;
	cout << "2. Ceaser Cipher" << endl;
	cout << "3. Vigenere cipher" << endl;
	cin >> menuInput;
	inputController(menuInput);
}

void decipherMenu() {
	currentState = ciphersDec;
	cout << endl << "1. XOR Decipher" << endl;
	cout << "2. Ceaser Decipher" << endl;
	cout << "3. Vigenere Decipher" << endl;
	cin >> menuInput;
	inputController(menuInput);
}

int main()
{
	cout << "Welcome to the Encryption assignment! Please, choose items from popping up menus!" << endl << endl;
	populateVigTable();
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
