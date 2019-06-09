// Sample_OverloadedFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Room
{
	double dblLength, dblWidth, dblHeight;
	char chrWallColour, chrCeilingColour;
	int intExist;
};

Room fnDefineRoom(Room, string);
void fnCalcArea(double& dblAreaWall, double& dblAreaCeiling, Room CurrentRoom);
void fnDisplaySummary(double, double, Room);

int main()
{
	int intUserSelection;
	Room roomKitchen, roomBedroom;
	double dblAreaWall, dblAreaCeiling;
	roomKitchen.intExist = 0; roomBedroom.intExist = 0;

	do
	{
		cout << "\nPlease make your selection from the following" << endl;
		cout << "1. Set Kitchen Parameters" << endl << "2. Set Bedroom Parameters" << endl << "3. Room Summary" << endl << "4. Exit" << endl << endl;
		cout << "Your selection: "; cin >> intUserSelection;

		if (intUserSelection == 1)
		{
			roomKitchen = fnDefineRoom(roomKitchen, "Kitchen");
		}
		else if (intUserSelection == 2)
		{
			roomBedroom = fnDefineRoom(roomBedroom, "Bedroom");
		}
		else if (intUserSelection == 3)
		{
			cout << "Room Summary:" << endl;

			if (roomKitchen.intExist == 1)
			{
				fnCalcArea(dblAreaWall, dblAreaCeiling, roomKitchen);

				fnDisplaySummary(dblAreaWall, dblAreaCeiling, roomKitchen);
			}
			if (roomBedroom.intExist == 1)
			{
				fnCalcArea(dblAreaWall, dblAreaCeiling, roomBedroom);
				fnDisplaySummary(dblAreaWall, dblAreaCeiling, roomBedroom);
			}
			if (roomBedroom.intExist == 0 && roomKitchen.intExist == 0)
				cout << "Sorry no rooms defined." << endl;
		}
		else if (intUserSelection != 4)
			cout << "Selection not understood, please try again" << endl << endl;

	} while (intUserSelection != 4);
	cout << "Thank you." << endl;
	return 0;
}

Room fnDefineRoom(Room CurrentRoom, string name) {
	cout << name <<" Length: "; cin >> CurrentRoom.dblLength;
	cout << name << " Width: "; cin >> CurrentRoom.dblWidth;
	cout << name << " Height: "; cin >> CurrentRoom.dblHeight;
	cout << name << " Wall Colour: "; cin >> CurrentRoom.chrWallColour;
	cout << name << " Ceiling Colour: "; cin >> CurrentRoom.chrCeilingColour;
	CurrentRoom.intExist = 1;
	return CurrentRoom;
}

void fnCalcArea(double& dblAreaWall, double& dblAreaCeiling, Room CurrentRoom) {
	dblAreaWall = (2 * CurrentRoom.dblLength * CurrentRoom.dblHeight) + (2 * CurrentRoom.dblWidth * CurrentRoom.dblHeight);
	dblAreaCeiling = CurrentRoom.dblLength * CurrentRoom.dblWidth;
}

void fnDisplaySummary(double dblAreaWall, double dblAreaCeiling, Room CurrentRoom) {
	cout << "Wall area: " << dblAreaWall << endl;
	if (CurrentRoom.chrWallColour == 'g')
		cout << "Wall colour: Green" << endl;
	else if (CurrentRoom.chrWallColour == 'b')
		cout << "Wall colour: Blue" << endl;
	else
		cout << "Wall colour is too fancy" << endl;

	cout << "Ceiling area: " << dblAreaCeiling << endl;
	if (CurrentRoom.chrCeilingColour == 'g')
		cout << "Ceiling colour: Green" << endl;
	else if (CurrentRoom.chrCeilingColour == 'b')
		cout << "Ceiling colour: Blue" << endl;
	else
		cout << "Ceiling colour is too fancy" << endl;
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
