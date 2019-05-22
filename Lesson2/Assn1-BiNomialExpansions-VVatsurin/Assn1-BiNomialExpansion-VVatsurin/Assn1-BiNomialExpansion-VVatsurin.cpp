// Assn1-BiNomialExpansion-VVatsurin.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Student number - 200363172
// Student name - Vladimir Vatsurin

#include <iostream>
using namespace std;

//Initializing the helper variables. Modifiers will be used for substraction in brackets
//Multiplier will contain previous multiplied brackets
int currentModifier = 0;
int curMultiplier = 1;

/*
Initializing the fatorial function. That function gets the number as an input and outputs the factorial of that number
*/
int factorial(int input) {
	int output = 1;
	for (int i = 2; i <= input; i++) {
		output = output * i;
	}
	return output;
}
/*
Initializing the multiplicator function.
That function will be used for counting out the multiplayer for parts of expanded expression
*/
int mult(int n, int x, int y) {
	if (x == n - 1 || y == n - 1) {
		return n;
	}
	else {
		currentModifier++;
		curMultiplier = curMultiplier * (n - currentModifier);
		return (n * curMultiplier) / factorial(currentModifier + 1);
	}


}

/*
This function will output the expanded expression of bi-nomial theorema. 
At first it will write down the initial expression with the first part of expanded expression.
Secondly, it will loop N-1 times for setting the middle parts with the correct multiplier and power values
As last it will add the last part (second value with N power of it)
*/
void outputBinominal(char A, char B, int n) {
	printf("(%c + %c)^\%i = %c^%i + ",A,B,n,A,n);
	for (int i = 1; i < n; i++) {
		printf("%i * %c^%i * %c^%i + ",mult(n, n - i, n - (n - i)),A,n-i,B,n-(n-i));
	}
	printf("%c^%i", B, n);
}


/*
Main function. Thats where program starts. Handles the input, promts and variable declaration.
*/
int main()
{
	char A;
	char B;
	int n;
	cout << "Welcome to the partial binomial expansion tool." << endl;
	cout << "Please enter the below terms. If either the A or B term is set to 0 the application will exit and n must" << endl;
	cout << "be greater than 0 as an integer value. Please enter a single value for both A and B at this time." << endl;
	
	cout << "Enter the A Term: " << endl;
	cin >> A;
	if (A == '0') { cout << "Thank you for using the application" << endl; exit(69); }
	cout << "Enter the B Term: " << endl;
	cin >> B;
	if (B == '0') { cout << "Thank you for using the application" << endl; exit(69); }
	inN:
	cout << "Enter the n term: " << endl;
	cin >> n;
	if (n <= 0) { cout << "The n term must be greater than 0. Please try again" << endl; goto inN; }

	cout << "Your expanded solution:" << endl;
	outputBinominal(A, B, n);
}

/*
Welcome to the partial binomial expansion tool.
Please enter the below terms. If either the A or B term is set to 0 the application will exit and n must
be greater than 0 as an integer value. Please enter a single value for both A and B at this time.
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
