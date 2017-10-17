#include <vector>
#include "Domino.h"


class Stock {
private:
	

public:
	Stock();
	std::vector<Domino> deck;
	void shuffleTheDeck();
	std::vector<Domino> DistributeAHand();
	Domino getTopDominoFromDeck();
	void printDeck();

	std::vector<Domino> getStock();


};
