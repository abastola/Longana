#include "Player.h"
#include "Hand.h"
#include "stdafx.h"

Player::Player() {
	score = 0;
	passed = false;
	drawn = false;
}

//Get sum of hands
int Player::getSumOfHands() {
	int sum=0;
	for (Domino i : hand.getHand()) {
		sum = sum+ i.getSum();
	}
	return sum;

}

//Return -1 to draw
//Return -2 to pass
//Return else for domino input

int Player::getInput(int requiredSide) {
	int temp = -1;
	while (true) {
		string userInput;
		cout << "Enter a Domino or Pass or Draw or Help or Exit: ";
		cin >> userInput;

		//if user enters exit, exit the game
		if (userInput.compare("Exit") == 0) {
			exit(1);
		}

		//if user enters pass or draw, check if valid 
		if ((userInput.compare("Pass") == 0) || (userInput.compare("Draw") == 0)) {

			int moveCOde = findIfMovePossible(requiredSide);

			//if no move possible
			if (moveCOde == -1) {

				//if not drawn yet
				if (!drawn) {
					cout << "\nDraw Possible. A card will be drawn for you." << endl;
					drawn = true;
					return -1;
				}

				//if drawn then pass
				else {
					passed = true;
					return -2;
				}
			}
			else {
				cout << "\nInvalid Pass/Draw. Move Possible. " << endl;
				cout << "Hint: Play " << (moveCOde % 100) / 10 << "-" << (moveCOde % 100) % 10 << endl;
			}
			continue;
		}

		//if user asks for help
		if (userInput.compare("Help") == 0) {

			int moveCOde = findIfMovePossible(requiredSide);

			//if move possible
			if (moveCOde >= 100) {
				cout << "Hint: On Left Play " << (moveCOde % 100) / 10 << "-" << (moveCOde % 100) % 10 << endl;
			}
			else {
				cout << "\nNo moves possible. Hint: Pass or Draw " << endl;
			}
			continue;
		}


		if (userInput.length() != 3) {
			continue;
		}

		int sideOne = stoi(userInput.substr(0, 1));
		int sideTwo = stoi(userInput.substr(2, 1));

		temp = validiateInput(sideOne, sideTwo);
		if (temp != -1) {
			drawn = false;
			break;
		}
		cout << "Invalid Input/Selection." << endl;
	}

	return temp;

}

int Player::validiateInput(int a, int b) {
	int count = 0;
	for (Domino i : hand.getHand()) {
		if ((i.getSideOne() == a) && (i.getSideTwo() == b)) {
			return count;
		}
		count++;
	}
	return -1;
}

// Return > 100 if non-double possible
// Return > 200 if double possible

int Player::findIfMovePossible(int requiredSide) {
	int count = 0;
	int returnCode = -1;
	for (Domino i : hand.getHand()) {
		if (i.getSideOne() != i.getSideTwo()) {
			if ((i.getSideOne() == requiredSide) || (i.getSideTwo() == requiredSide)) {

				return (100 + i.getSideOne() * 10 + i.getSideTwo());
			}
		}
		else {
			returnCode = (200 + i.getSideOne() * 10 + i.getSideTwo());
		}
		count++;
	}
	return returnCode;
}

int Player::calculateScore() {
	int count = 0;
	for (Domino i : hand.getHand()) {
		count += i.getSum();
	}
	return count;
}

void Player::updateScore(int a) {
	score += a;
}

void Player::setHand(Hand h) {
	hand = h;
}

void Player::printHand() {
	for (Domino i : hand.getHand()) {
		i.printDomino();
	}
}

void Player::deleteDominoFromHand(int index) {
	hand.removeDomino(index);
}

bool Player::isHandEmpty() {
	return hand.getHand().empty();
}

