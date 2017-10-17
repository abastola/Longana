#include "Computer.h"
#include "stdafx.h"

int Computer::getInput(int requiredSide) {
	int temp = -1;
	int moveCOde = findIfMovePossible(requiredSide);
	//If No Move Possible
	if (moveCOde == -1) {

		//if not drawn yet
		if (!drawn) {
			cout << "\nPlayer 2 will draw a card from boneyard." << endl;
			system("pause");
			drawn = true;
			return -1;
		}

		//if drawn then passW
		else {
			passed = true;
			cout << "\nPlayer 2 will pass." << endl;
			system("pause");
			return -2;
		}
	}
	else {
		string userInput = to_string((moveCOde % 100) / 10) + "-" + to_string((moveCOde % 100) % 10);
		int sideOne = stoi(userInput.substr(0, 1));
		int sideTwo = stoi(userInput.substr(2, 1));
		temp = validiateInput(sideOne, sideTwo);
		return temp;
	}

}