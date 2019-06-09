// Assn2-Sorting-VVatsurin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#define RANGE 255
using namespace std;

void showMenu() {
	cout << "Please make your selection from the following:" << endl;
	cout << "    1.  Define Random Number List" << endl;
	cout << "    2.  Sort Number List" << endl;
	cout << "    3.  Sorting Statistics" << endl;
	cout << "    4.  Exit" << endl << endl;
}

void showSortingMenu() {
	cout << "What sorting algorithm would you like to use?" << endl;
	cout << "    1.  Selection Sort" << endl;
	cout << "    2.  Bubble Sort" << endl;
	cout << "    3.  Counting Sort" << endl << endl;
}

int numArr[20];

void setRandomNumbers() {
	srand(time(NULL));
	for (int i = 0; i <= size(numArr); i++) {
		
		numArr[i] = (rand()%101);
		cout << numArr[i] << endl;
	}
}

/*

Example had gotten from https://ru.wikipedia.org/wiki/Сортировка_пузырьком 

*/
void sortFunctionBubble(int t) {
	//t = clock();
	//t / CLOCKS_PER_SEC;
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
	
	t = chrono::duration_cast<chrono::microseconds>(end - start).count();
	cout << "TIME " << t << endl;
}

void sortFunctionSelection(int t) {
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

	t = chrono::duration_cast<chrono::microseconds>(end - start).count();
	cout << "TIME " << t << endl;
}

void sortFunctionCounting(int t) {
	
}

void outputArray() {
	cout << "Array:" << endl;
	for (int i = 0; i < size(numArr); i++) {
		cout << numArr[i] << endl;
	}
}

int main()
{
	int t = 0;
	cout << "Welcome to the Sorting Algorithm Tool" << endl << endl;
    cout << "Hello World!\n"; 

	setRandomNumbers();
	sortFunctionCounting(t);
	outputArray();
	


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
