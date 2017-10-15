#include <vector>
#include "Domino.h"


class Stock {
private:
	std::vector<Domino> deck;

public:
	Stock();
	void shuffleTheDeck();
	std::vector<Domino> DistributeAHand();
	Domino getTopDominoFromDeck();
	void printDeck();

	std::vector<Domino> getStock();


};
