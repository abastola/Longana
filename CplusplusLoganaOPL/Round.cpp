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
	cout << "\nPlayer 1 Hand: \n";
	player1.printHand();
	cout << "\n\nPlayer 2 Hand: \n";
	player2.printHand();
	cout << "\n\nRound Stock: \n";
	stock.printDeck();
}

void Round::findTurn() {
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
}

void Round::playTurn(Player *player) {
	
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

	int playingDominoIndex = player->getInput();

	cout << "WIll play " << playingDominoIndex << endl;
	
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
	layout.printBoard();

}



