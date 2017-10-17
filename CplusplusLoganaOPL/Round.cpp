#include "stdafx.h"
#include "Round.h"

Round::Round(int a) {
	countPassed = 0;
	passed = false;
	turn = 1;
	engine = a;
	enginePresent = false;
	gameEnded = false;
}

int Round::getCountPassed() {
	return countPassed;
}

bool Round::isStockEmpty() {
	return (stock.getStock()).empty();
}

void Round::setHands() {
	stock.shuffleTheDeck();
	player2.setHand(Hand(stock.DistributeAHand()));
	player1.setHand(Hand(stock.DistributeAHand()));
	if (player1.hand.findEngine(engine)) {
		enginePresent = true;
		turn = 1;
	}
	if (player2.hand.findEngine(engine)) {
		enginePresent = true;
		turn = 2;
	}
}

void Round::printDetails() {
	cout << "\nPlayer 1 Hand: ";
	player1.printHand();
	cout << "\nPlayer 2 Hand: ";
	player2.printHand();
	cout << "\nRound " << (7 - engine) << " Stock: ";
	stock.printDeck();
	layout.printBoard();
}

int Round::findTurn() {
	if (player1.isHandEmpty()) {
		return 1;
	}
	if (player2.isHandEmpty()) {
		return 2;
	}
	if (turn == 1) {
		cout << "\nPlayer 1 turn." << endl;
		playTurn(&player1);
		turn = 2;
	}
	else {
		cout << "\nPlayer 2 turn." << endl;
		playTurn(&player2);
		turn = 1;
	}
	printDetails();
	return -1;
}

void Round::playTurn(Player *player) {

	//Try to put on original side
	Domino temp;
	int requiredSide;
	if (turn == 1) {
		temp = layout.getLeft();
		if (temp.Flipped()) {
			requiredSide = temp.getSideTwo();
		}
		else {
			requiredSide = temp.getSideOne();
		}
	}
	else {
		temp = layout.getRight();
		if (temp.Flipped()) {
			requiredSide = temp.getSideOne();
		}
		else {
			requiredSide = temp.getSideTwo();
		}
	}

	int playingDominoIndex = -1;
	bool requiredSideOne = true;

	while (true) {
		playingDominoIndex = player->getInput(requiredSide);
		if (playingDominoIndex < 0) {
			if (playingDominoIndex == -1) {
				if ((stock.getStock()).size() == 0) {
					countPassed++;
					cout << "\nPlayer" << turn << "Passed because of empty boneyard." << endl;
					return;
				}
				else {
					player->hand.addDomino(stock.getTopDominoFromDeck());
				}
				printDetails();
				continue;
			}
			if (playingDominoIndex == -2) {
				passed = true;
				countPassed++;
				cout << "\nPlayer" << turn << "Passed." << endl;
				return;
			}
		}
		temp = player->hand.getDomino(playingDominoIndex);

		//check if returned domino is double

		if (temp.getSideOne() == temp.getSideTwo()) {
			if (turn == 1) {
				cout << "\nWhich side do you want to put the double? 1 for Left and 2 for right: ";
				int inputSide = 0;
				cin >> inputSide;
				if (inputSide == 1) {
					layout.insertLeft(temp);
				}
				else {
					layout.insertRight(temp);
				}
			}
			else {
				layout.insertLeft(temp);
			}
			countPassed = 0;

			cout << "\nPlayer" << turn << " placed ";
			temp.printDomino();
			cout << endl;
			player->hand.removeDomino(playingDominoIndex);
			return;
		}

		if (temp.getSideOne() == requiredSide) {
			requiredSideOne = true;
			break;
		}
		if (temp.getSideTwo() == requiredSide) {
			requiredSideOne = false;
			break;
		}

		cout << "Invalid Domino Selection. Select one with matching PIP." << endl;
	}

	if (requiredSideOne) {
		if (turn == 1) {
			temp.setFlipped();
		}
	}
	else {
		if (turn == 2) {
			temp.setFlipped();
		}
	}

	if (turn == 1) {
		layout.insertLeft(temp);
	}
	else {
		layout.insertRight(temp);
	}
	countPassed = 0;
	cout << "\nPlayer" << turn << " placed ";
	temp.printDomino();
	cout << endl;
	player->hand.removeDomino(playingDominoIndex);

}

void Round::placeFirstDomino() {
	while (true) {
		if (!enginePresent) {
			cout << "\n\nEngine Not Found. Drawing one domino from stock." << endl;
			player1.hand.addDomino(stock.getTopDominoFromDeck());
			player2.hand.addDomino(stock.getTopDominoFromDeck());
			printDetails();

			if (player1.hand.findEngine(engine)) {
				enginePresent = true;
				turn = 1;
			}
			if (player2.hand.findEngine(engine)) {
				enginePresent = true;
				turn = 2;
			}
		}
		else {
			cout << "\n\nEngine Found. Starting the game." << endl;
			break;
		}
	}

	cout << "\nPlayer " << turn << " starts first." << endl;
	cout << "\nPlayer " << turn << " placed Engine: " << engine << "-" << engine << endl;

	if (turn == 1) {
		int temp = player1.hand.findDominoWithTwoSides(engine, engine);
		layout.insertLeft(player1.hand.getDomino(temp));
		player1.deleteDominoFromHand(temp);
		turn = 2;
	}
	else {
		int temp = player2.hand.findDominoWithTwoSides(engine, engine);
		layout.insertLeft(player2.hand.getDomino(temp));
		player2.deleteDominoFromHand(temp);
		turn = 1;
	}

	printDetails();

}

int Round::getPlayer1Sum() {
	return player1.getSumOfHands();
}

int Round::getPlayer2Sum() {
	return player2.getSumOfHands();
}



