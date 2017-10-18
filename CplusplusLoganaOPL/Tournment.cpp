/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  1/Tournament
     Date:  October 18, 2017
     ************************************************************
*/

#include "Tournament.h"
#include <fstream>

// Function Prototypes
Domino parseDomino(string userInput);
vector<string> parseVector(string test);
deque <string> parseQueue(string test);

/* ********************************************************************* 
Function Name: Tournament(Constructor)
Purpose: To intialize the tournament class. 
Parameters: N/A
Return Value: N/A
Local Variables: N/A
Algorithm: Intilize round number to 1, each player's score to 0 and tournament score to 0.
Assistance Received: None 
********************************************************************* */

Tournament::Tournament() {
	roundNumber = 1;
	player1Score = 0;
	player2Score = 0;
	tournaMentScore = 0;
}





bool Tournament::loadFile() {
	cout << "Do you want to load a file? 1: Yes 2: No: ";
	int temp;
	cin >> temp;
	if (temp == 1) {
		string fileName;
		cout << "Enter File Name: ";
		cin >> fileName;

		vector <string> cds;
		vector <string> pds;
		deque  <string> lds;
		vector <string> bds;
		string test;
		int tS = 0;
		int rN = 0;
		int cS = 0;
		int hS = 0;
		string line;

		ifstream f(fileName);

		if (!f) {
			cout << "Error Opening File. Exiting" << endl;
			system("pause");
			exit(1);
		}

		string str1, str2, str3, str4;
		int a;

		//get Tournament Score
		getline(f, line);
		istringstream iss(line);
		iss >> str1 >> str2 >> a;

		tS = a;

		//get Round Number
		getline(f, line);
		istringstream iso(line);
		iso >> str1 >> str2 >> a;

		rN = a;

		//skip lines
		getline(f, line);
		getline(f, line);

		//get computer hands
		getline(f, line);
		test = line;
		cds = parseVector(test);
		for (int i = 1; i < cds.size(); i++) {
			computerHand.push_back(parseDomino(cds[i]));
		}

		//get computer score
		getline(f, line);
		istringstream isw(line);
		isw >> str1 >> a;
		cS = a;

		//skip lines
		getline(f, line);
		getline(f, line);

		//get player hands
		getline(f, line);
		test = line;
		pds = parseVector(test);
		for (int i = 1; i < pds.size(); i++) {
			playerHand.push_back(parseDomino(pds[i]));
		}

		// get player score
		getline(f, line);
		istringstream isv(line);
		isv >> str1 >> a;

		hS = a;

		//skip lines
		getline(f, line);
		getline(f, line);

		//get layout
		getline(f, line);
		test = line.substr(1, line.size() - 2);
		lds = parseQueue(test);
		for (int i = 1; i < lds.size(); i++) {
			layout.push_back(parseDomino(lds[i]));
		}

		//skip two lines
		getline(f, line);
		getline(f, line);

		//get Boneyard
		getline(f, line);
		test = line;
		bds = parseVector(test);
		for (int i = 0; i < bds.size(); i++) {
			boneyard.push_back(parseDomino(bds[i]));
		}

		//skip one line
		getline(f, line);

		//get if passed or not
		getline(f, line);
		istringstream isa(line);
		isa >> str1 >> str2 >> str3 >> str4;

		if (str4.compare("Yes")) {
			p = true;
		}

		//skip line
		getline(f, line);

		//get next player
		getline(f, line);
		istringstream ist(line);
		ist >> str1 >> str2 >> str4;


		if ((str4.compare("Computer")) == 0) {
			t = 2;
		}
		else {
			t = 1;
		}

		//Set tournament parameters

		//cout << "Extracted tour score : " << tS << endl;

		roundNumber = rN;
		player1Score = hS;
		player2Score = cS;
		tournaMentScore = tS;
		loadedFromFile = true;

		return true;

	}

	return false;
}

void Tournament::playGame() {
	//ask if players want to load file

	int playingRound = 1;

	if (loadFile()) {
		playingRound = roundNumber;
	}

	Round round(7 - playingRound);
	roundRemaining = (7 - playingRound);

	if (loadedFromFile) {
		round.player1.hand.hand = playerHand;
		round.player2.hand.hand = computerHand;
		round.layout.boardDominos = layout;
		round.stock.deck = boneyard;
		round.passed = p;
		round.turn = t;
		round.printDetails();
		printTournamentDetails();
		if (round.layout.boardDominos.size() == 0) {
			round.placeFirstDomino();
		}
	}
	else {
		int getTournaMentScore;
		cout << "Enter Tournament Score: ";
		cin >> getTournaMentScore;

		if (getTournaMentScore < 1) {
			cout << "Tournament score should be more than 0. Exiting" << endl;
			system("pause");
			exit(1);
		}
		tournaMentScore = getTournaMentScore;
		round.setHands();
		round.printDetails();
		printTournamentDetails();
		round.placeFirstDomino();
	}

	for (int i = playingRound; i <= 7; i++) {
		if (i != playingRound) {
			round = Round(7 - i);
			round.setHands();
			round.printDetails();
			round.placeFirstDomino();
		}

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
		}
		else if (player2Score >= tournaMentScore) {
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


void Tournament::printTournamentDetails() {
	cout << "Tournment Score: " << tournaMentScore << endl;
	cout << "Player 1 Score:  " << player1Score << endl;
	cout << "Player 2 Score:  " << player2Score << endl;
	cout << "Turn:            " << t << endl;
	cout << "Passed:          " << p << endl;
	cout << endl;
	system("pause");
}

vector<string> parseVector(string test) {
	vector<string> cds;
	string temp;
	stringstream playerHand(test);
	while (playerHand >> temp) {
		cds.push_back(temp);
	}
	return cds;
}

deque <string> parseQueue(string test) {
	deque<string> cds;
	string temp;
	stringstream playerHand(test);
	while (playerHand >> temp) {
		cds.push_back(temp);
	}
	return cds;
}

Domino parseDomino(string userInput) {

	int sideOne = stoi(userInput.substr(0, 1));
	int sideTwo = stoi(userInput.substr(2, 1));

	Domino domino(sideOne, sideTwo);
	return domino;
}
