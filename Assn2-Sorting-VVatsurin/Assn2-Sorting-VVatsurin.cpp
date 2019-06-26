// Assn2-Sorting-VVatsurin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <chrono>
#include <algorithm> //http://www.cplusplus.com/reference/algorithm/max/
using namespace std;
// Declaring variables that program will use. This includes:
// - Two arays. One for for the initial state, second for sorting
// - Menu enumerator for the menu controller
// - Time variables, counters
// - inputController Function
int numArr[20];
int initArr[20];
enum menuPhase { home, sorting };
menuPhase currentPhase;
int tBubble;
int tCounting;
int tSelection;
bool isInitialized = false;

int execCount = 0;
int dataSetsGenereated = 0;

void inputController(int input);

/**
	A function that shows up the main menu and handles the input
*/
void showMenu() {
	cout << "Please make your selection from the following:" << endl;
	cout << "    1.  Define Random Number List" << endl;
	cout << "    2.  Sort Number List" << endl;
	cout << "    3.  Sorting Statistics" << endl;
	cout << "    4.  Exit" << endl << endl;
	currentPhase = home;
	
	int input = 0;

	cin >> input;
	inputController(input);
}
/**
	A function that shows up the sorting menu and handles the input
*/
void showSortingMenu() {
	cout << "What sorting algorithm would you like to use?" << endl;
	cout << "    1.  Selection Sort" << endl;
	cout << "    2.  Bubble Sort" << endl;
	cout << "    3.  Counting Sort" << endl << endl;
	currentPhase = sorting;

	int input = 0;

	cin >> input;
	inputController(input);
}

/**
	A function that sets the random numbers into the initial array + increment the counter
*/
void setRandomNumbers() {
	srand(time(NULL));
	for (int i = 0; i <= size(numArr); i++) {
		
		initArr[i] = (rand()%101);
		
	}
	tBubble = 0;
	tCounting = 0;
	tSelection = 0;
	isInitialized = true;
	dataSetsGenereated++;
}

/*

Example had gotten from https://ru.wikipedia.org/wiki/Сортировка_пузырьком 

*/
/*
* Sorting function - BUBBLE METHOD
*
*/
void sortFunctionBubble() {
	//t = clock();
	//t / CLOCKS_PER_SEC;
	execCount++;
	for (int i = 0; i < size(initArr); i++)
	{
		numArr[i] = initArr[i];
	}

	auto start = std::chrono::high_resolution_clock::now();
	int i = 0;
	int buffer;
	bool isSwapped = false;
	while (i < size(numArr)) {
		if (i + 1 != size(numArr) && numArr[i] > numArr[i + 1]) {
			buffer = numArr[i];
			numArr[i] = numArr[i + 1];
			numArr[i + 1] = buffer;
			isSwapped = true;
		}
		i++;
		if (i == size(numArr) && isSwapped == true) {
			isSwapped = false;
			i = 0;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();

tBubble = chrono::duration_cast<chrono::microseconds>(end - start).count();
}

/*
* Sorting fucntion - SELECTION METHOD
*
*/
void sortFunctionSelection() {
	execCount++;
	for (int i = 0; i < size(initArr); i++)
	{
		numArr[i] = initArr[i];
	}

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < size(numArr) - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size(numArr); j++)
		{
			if (numArr[j] < numArr[min]) {
				min = j;
			}
		}

		if (min != i) {
			swap(numArr[i], numArr[min]);
			min = i;
		}
	}

	auto end = std::chrono::high_resolution_clock::now();

	tSelection = chrono::duration_cast<chrono::microseconds>(end - start).count();
}

/*
* Sorting fucntion - COUNTING METHOD
*
*/

void sortFunctionCounting() {
	execCount++;
	for (int i = 0; i < size(initArr); i++)
	{
		numArr[i] = initArr[i];
	}

	auto start = std::chrono::high_resolution_clock::now();

	int countArr[101];
	for (int i = 0; i < size(countArr); i++) {
		countArr[i] = 0;
	}

	for (int i = 0; i < size(numArr); i++) {
		countArr[numArr[i]]++;
	}


	int prevCounter = 0;
	for (int i = 0; i < size(countArr); i++) {
		if (countArr[i] != 0)
		{

			for (int j = 0; j < countArr[i]; j++)
			{

				numArr[prevCounter] = i;
				prevCounter++;
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();

	tCounting = chrono::duration_cast<chrono::microseconds>(end - start).count();
}

/*
* Function that outputs the array contents
*/
void outputArray() {
	cout << "Array:" << endl;
	for (int i = 0; i < size(numArr); i++) {
		cout << numArr[i] << " ";
	}
	cout << endl;
}

/*
	Function that outputs time as a string, if it's 0 then it will output 'N/A'
*/
string outputTime(int input) {
	if (input == 0)
	{
		return "N/A";

	}

	return to_string(input);
}

/*
	Function that outputs the fastest sorting alogrithm executed
*/
string outputFastestSort() {
	int min = (tSelection > tBubble) ? tBubble : tSelection;
	int smallestTime = ((min > tCounting) ? tCounting : min);
	if (smallestTime == tSelection) { return "Selection sort"; }
	if (smallestTime == tBubble) { return "Bubble sort"; }
	if (smallestTime == tCounting) { return "Counting sort"; }


}
/*
Function that return the smallest time of a fucntion workflow
*/
int outputSmallestTime() {
	int min = (tSelection > tBubble) ? tBubble : tSelection;
	return ((min > tCounting) ? tCounting : min);
}
/*
Controller for user unput, defines what to execute and what to show based on the user choice and the current state
*/
void inputController(int input) {
	switch (currentPhase)
	{
	case home: 
		switch (input)
		{
		case 1: 
			setRandomNumbers();
			cout << "Random numbers are assigned" << endl;
			cout << "The random data is: ";
			for (int i = 0; i < size(initArr); i++)
			{
				cout << initArr[i] << " ";
			}
			cout << endl << endl;
			showMenu();
			break;
		case 2: 
			if (!isInitialized) {
				cout << "Random array has not been intialized! Please, define the random array first (option 1)" << endl;
				showMenu();
				break;
			}
			showSortingMenu();
			break;
		case 3:
			cout << "Sorting staticstics:" << endl;
			cout << "    1. Selection sort: " << outputTime(tSelection) << endl;
			cout << "    2. Bubble sort:    " << outputTime(tBubble) << endl;
			cout << "    3. Counting sort:  " << outputTime(tCounting) << endl << endl;

			showMenu();
			break;
		case 4:
			if (!isInitialized) { cout << "Thank you for using the application!" << endl; exit(250); }
			cout << "Thank you for using the application!" << endl;
			cout << "Number of data sets generated:       " << dataSetsGenereated << endl;
			cout << "Number of sort alogorithms executed: " << execCount << endl;
			cout << "Fastest sort was the: " << outputFastestSort() << "    " << outputSmallestTime() << " microseconds";
			exit(255);
		default:
			cout << endl << endl << "WRONG INPUT! WRONG INPUT! WRONG INPUT! -------> RETURNING TO MAIN MENU" << endl;
			showMenu();
			break;
		}
		break;
	case sorting:
		switch (input)
		{
		case 1:
			sortFunctionSelection();
			cout << "Original Data: ";
			for (int i = 0; i < size(initArr); i++)
			{
				cout << initArr[i] << " ";
			}
			cout << endl << "Sorted Data: ";
			for (int i = 0; i < size(numArr); i++)
			{
				cout << numArr[i] << " ";
			}
			cout << endl << "Sorting Time: " << tSelection << endl;
			showMenu();
			break;
		case 2:
			sortFunctionBubble();
			cout << "Original Data: ";
			for (int i = 0; i < size(initArr); i++)
			{
				cout << initArr[i] << " ";
			}
			cout << endl << "Sorted Data: ";
			for (int i = 0; i < size(numArr); i++)
			{
				cout << numArr[i] << " ";
			}
			cout << endl << "Sorting Time: " << tBubble << endl;
			showMenu();
			break;
		case 3:
			sortFunctionCounting();
			cout << "Original Data: ";
			for (int i = 0; i < size(initArr); i++)
			{
				cout << initArr[i] << " ";
			}
			cout << endl << "Sorted Data: ";
			for (int i = 0; i < size(numArr); i++)
			{
				cout << numArr[i] << " ";
			}
			cout << endl << "Sorting Time: " << tCounting << endl;
			showMenu();
			break;
		default:
			cout << endl << endl << "WRONG INPUT! WRONG INPUT! WRONG INPUT! -------> RETURNING TO MAIN MENU" << endl;
			showMenu();
			break;
		}
		break;
	default:
		break;
	}
}

// Default main method. Executes the menu loop.
int main()
{
	cout << "Welcome to the Sorting Algorithm Tool" << endl << endl;
    
	showMenu();	
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
