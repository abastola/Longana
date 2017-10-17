#include "stdafx.h"
#include "Round.h"
#include "Layout.h"

void lineBreak() {
	cout << "\n";
}

int main() {
	Round round(6);
	round.setHands();
	round.printDetails();
	round.placeFirstDomino();
	round.findTurn();

	system("pause");
}

