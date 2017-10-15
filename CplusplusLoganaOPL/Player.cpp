#include "Player.h"
#include "Hand.h"
#include "stdafx.h"

Player::Player() {
	score = 0;
	passed = false;
}

int Player::getInput() {
	int temp = -1;
	while (true) {
		string userInput;
		cout << "Enter a Domino or Pass: ";
		cin >> userInput;
		if (userInput.compare("Pass") == 0) {
			break;
		}
		if (userInput.length() != 3) {
			continue;
		}

		int sideOne = stoi(userInput.substr(0, 1));
		int sideTwo = stoi(userInput.substr(2, 1));

		temp = validiateInput(sideOne, sideTwo);
		if (temp != -1) {
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

