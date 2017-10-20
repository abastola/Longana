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
Function Name: 
	Tournament(Constructor)
Purpose: 
	To intialize the tournament class. 
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	Intilize round number to 1, each player's score to 0 and tournament score to 0.
Assistance Received: 
	None 
********************************************************************* */

Tournament::Tournament() {
	roundNumber = 1;
	player1Score = 0;
	player2Score = 0;
	tournaMentScore = 0;
}

/* ********************************************************************* 
Function Name: 
	playGame
Purpose: 
	Loads the tournament.
	Plays the entire tournaments. 
	Calculates score after each round.
	Finds the winner at the end. 
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	int roundNumber: Current Round Number
	int RemainingRound: Rounds Remaining
	Round round: Round object for a particular round. 
	int player1Score: Temp variable to store player 1 score. 
	int player2Score: Temp variable to store player 2 score. 
	int tournamentScore: Temp variable to store tournament score. 
	int n: Temp variable to store the turn
Algorithm: 
	Start the tournament through file load or new game.
	Set the tournament parameters.
	Play the rounds.
	After each round ends, get the total scores and see if the game ended. 
	End the game of score of player > tournament score or if all round are done.
Assistance Received: 
	None 
********************************************************************* */

void Tournament::playGame() {
	//set round to 1
	int playingRound = 1;

	//Asks if user wants to load a file
	if (loadFile()) {
		
		//set the playingRound to roundNumber that loadFile() function sets.
		playingRound = roundNumber;
	}

	//Set the round with enginer: (7-Round Number)
	Round round(7 - playingRound);
	
	//Update the remaining round value
	roundRemaining = (7 - playingRound);

	//if loaded from file 
	if (loadedFromFile) {
		
		//set the round parameters
		round.player1.hand.hand = playerHand;
		round.player2.hand.hand = computerHand;
		round.layout.boardDominos = layout;
		round.stock.deck = boneyard;
		round.passed = p;
		round.turn = t;
		round.printDetails();
		
		//Print the tournament details
		printTournamentDetails();
		
		//if no engine placed in boneyard during file load, place the first domino
		if (round.layout.boardDominos.size() == 0) {
			round.placeFirstDomino();
		}
	}
	// In case of new game load (ie no file load)
	else {
		
		//temp value to store user input (tournament score)
		int getTournaMentScore;
		
		//get user input for tournament score
		cout << "Enter Tournament Score: ";
		cin >> getTournaMentScore;

		//validiate the score. Only accept > 1. No negative.
		if (getTournaMentScore < 1) {
			cout << "Tournament score should be more than 0. Exiting" << endl;
			
			//End the game in case of invalid input.
			system("pause");
			exit(1);
		}
		
		//set the tournament credentials
		tournaMentScore = getTournaMentScore;
		round.setHands();
		round.printDetails();
		printTournamentDetails();
		round.placeFirstDomino();
	}
	
	//play the rounds
	for (int i = playingRound; i <= 7; i++) {
		
		//if first new game round, set the hands and place first domino (engine)
		if (i != playingRound) {
			round = Round(7 - i);
			round.setHands();
			round.printDetails();
			round.placeFirstDomino();
		}
		
		
		//play the round until round completion
		while (true) {

			//check if stock is empty and both player have passed.
			if ((round.isStockEmpty()) && (round.getCountPassed() == 2)) {
				
				//if yes end the game.
				cout << "Game Ended. Empty Boneyard" << endl;
				
				//get player points
				int player1Points = round.getPlayer2Sum();
				int player2Points = round.getPlayer1Sum();
				
				//compare and display the winner
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
				
				//end the round through break;
				break;
			}
			
			//play the round
			//n store the player who won the round
			int n = round.findTurn();
			
			//check who won and display results
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
		
		
		//Dispaly the scores after each round
		cout << "\nScore Board: \n" << endl;
		cout << "Player 1: " << player1Score << endl;
		cout << "Player 2: " << player2Score << endl;
		
		
		//check if players won the tournament
		//if yes display the result
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
		
		//loop to begin another round
		cout << "Beginning another round. ";
		system("pause");
	}
	
	
	//if all rounds end without getting highest score, display the winner who has highest point or draw. 
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

/* ********************************************************************* 
Function Name: 
	loadFile
Purpose:
	Ask if user wants to load the file. 
	Load a serialization file.
	Parses the file
	Gets/updates tournament parameters.
Parameters: 
	N/A
Return Value: 
	True if user loads file, false if doesn't.
Local Variables: 
	in temp: store the userselection
	string fileName: store the filename
	string line: stores the extracted line from the file
Algorithm: 
	Go through each line. 
	Get the line. 
	Parse the line and get required information.
	Set the tournament parameters.
	
Assistance Received: 
	None 
********************************************************************* */

bool Tournament::loadFile() {
	
	//ask user if they want to load file
	cout << "Do you want to load a file? 1: Yes 2: No: ";
	
	//get user select
	int temp;
	cin >> temp;
	
	// if user wants to load file
	if (temp == 1) {
		
		//get filename;
		string fileName;
		cout << "Enter File Name: ";
		cin >> fileName;
		
		//temp variables to extract data
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
		
		//open file
		ifstream f(fileName);

		//check if file can be opened
		if (!f) {
			cout << "Error Opening File. Exiting" << endl;
			system("pause");
			exit(1);
		}
		
		//temp variables
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

		//skip two lines
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
		roundNumber = rN;
		player1Score = hS;
		player2Score = cS;
		tournaMentScore = tS;
		loadedFromFile = true;

		//return true for fileload
		return true;

	}

	//return false if file not loaded
	return false;
}


/* ********************************************************************* 
Function Name: 
	printTournamentDetails
Purpose:
	Print tournament details like score, turn, passed or not.
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	Print the details	
Assistance Received: 
	None 
********************************************************************* */

void Tournament::printTournamentDetails() {
	cout << "Tournment Score: " << tournaMentScore << endl;
	cout << "Player 1 Score:  " << player1Score << endl;
	cout << "Player 2 Score:  " << player2Score << endl;
	cout << "Turn:            " << t << endl;
	cout << "Passed:          " << p << endl;
	cout << endl;
	system("pause");
}

/* ********************************************************************* 
Function Name: 
	parseVector
Purpose:
	parses a line to extract dominos for player hands
Parameters: 
	string test: line containing dominos
Return Value: 
	vector<string> of all parsed domino data
Local Variables: 
	vector<string> cds: vector of parsed dominos.
	string temp: store string after the space
	stringstream playerHand: To extract string after spaces
Algorithm: 
	FInd space in the string
	get the domino.
	add to vector
	return vector
Assistance Received: 
	None 
********************************************************************* */

vector<string> parseVector(string test) {
	
	//vector to store domino
	vector<string> cds;
	
	//temp to store the extract stream
	string temp;
	
	//extract the string after the space
	stringstream playerHand(test);
	
	//loop through spaces
	while (playerHand >> temp) {
		
		//push to vector
		cds.push_back(temp);
	}
	
	//return the vector
	return cds;
}

/* ********************************************************************* 
Function Name: 
	parseQueue
Purpose:
	parses a line to extract dominos for player hands
Parameters: 
	string test: line containing dominos
Return Value: 
	dequeing> of all parsed domino data
Local Variables: 
	deque<string> cds: deque arsed dominos.
	string temp: store string after the space
	stringstream playerHand: To extract string after spaces
Algorithm: 
	FInd space in the string
	get the domino.
	add to deque
	return vector
Assistance Received: 
	None 
********************************************************************* */

deque <string> parseQueue(string test) {
	//deque to store extracted dominos
	deque<string> cds;
	
	//temp to store the extract stream
	string temp;
	
	//extract the string after the space
	stringstream playerHand(test);
	
	//loop through spaces
	while (playerHand >> temp) {
		
		//push to deque
		cds.push_back(temp);
	}
	
	//return the deque
	return cds;
}

/* ********************************************************************* 
Function Name: 
	parseDomino
Purpose:
	parse a string to domino
Parameters: 
	string userInput: domino
Return Value: 
	Domino Object with sides parsed from userInput
Local Variables: 
	N/A
Algorithm: 
	Get side1 and side2.
	return the Domino(side1, side2)
Assistance Received: 
	None 
********************************************************************* */

Domino parseDomino(string userInput) {
	
	//change string to int and return the domino
	return Domino(stoi(userInput.substr(0, 1)), stoi(userInput.substr(2, 1)));
}
