#include "Tournament.h"

Tournament::Tournament() {
	roundNumber = 1;
	player1Score = 0;
	player2Score = 0;
	tournaMentScore = 5;
}

bool Tournament::loadFile() {
	cout << "Do you want to load a file? 1 for Yes. 2 for No.";
	int temp;
	cin >> temp;

	return false;
}

void Tournament::playGame() {
	//ask if players want to load file

	if (loadFile()) {
		//loadFile
	}

	roundNumber = 2;
	int startingRound = roundNumber;

	for (int i = 0; i <= 2; i++) {
		Round round(2 - i);
		round.setHands();
		round.printDetails();
		round.placeFirstDomino();

		while (true) {

			if ((round.isStockEmpty()) && (round.getCountPassed() == 2)) {
				cout << "Game Ended. Empty Boneyard" << endl;
				int player1Points = round.getPlayer2Sum();
				int player2Points = round.getPlayer1Sum();

				if (player1Points > player2Points) {
					cout << "Game Ended. Player 1 wins." << endl;
					cout << "Player 1 Points: " << round.getPlayer2Sum() << endl;
					player1Score += round.getPlayer2Sum();
				}

				if (player2Points > player1Points) {
					cout << "Game Ended. Player 2 wins." << endl;
					cout << "Player 2 Points: " << round.getPlayer1Sum() << endl;
					player2Score += round.getPlayer1Sum();
				}

				break;
			}

			int n = round.findTurn();
			if (n == 1) {
				cout << "Game Ended. Player 1 wins." << endl;
				cout << "Player 1 Points: " << round.getPlayer2Sum() << endl;
				player1Score += round.getPlayer2Sum();
				break;
			}

			if (n == 2) {
				cout << "Game Ended. Player 2 wins." << endl;
				cout << "Player 2 Points: " << round.getPlayer1Sum() << endl;
				player2Score += round.getPlayer1Sum();
				break;
			}
		}

		cout << "\nScore Board: \n" << endl;
		cout << "Player 1: " << player1Score << endl;
		cout << "Player 2: " << player2Score << endl;

		if (player1Score >= tournaMentScore) {
			cout << "\n\n\n------------------------------" << endl;
			cout << "  Player 1 wins the tournament." << endl;
			cout << " ------------------------------" << endl;
			return;
		}else if (player2Score >= tournaMentScore){
			cout << "\n\n\n\n------------------------------" << endl;
			cout << "  Player 2 wins the tournament." << endl;
			cout << " ------------------------------" << endl;
			return;
		}

		cout << "Beginning another round. ";
		system("pause");
	}

	if (player1Score > player2Score) {
		cout << "\n\n\n------------------------------" << endl;
		cout << "  Player 1 wins the tournament." << endl;
		cout << " ------------------------------" << endl;
		return;
	}
	else if (player1Score < player2Score) {
		cout << " \n\n\n\n------------------------------" << endl;
		cout << "  Player 2 wins the tournament." << endl;
		cout << "------------------------------" << endl;
		return;
	}
	else {
		cout << " \n\n\n\n------------------------------" << endl;
		cout << "                   It's a draw." << endl;
		cout << " ------------------------------" << endl;
		return;
	}


}