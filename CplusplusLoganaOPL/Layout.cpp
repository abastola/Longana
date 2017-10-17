#include "Layout.h"

Layout::Layout() {

}

Domino Layout::getLeft() {
	return boardDominos[0];
}

Domino Layout::getRight() {
	return boardDominos[boardDominos.size()-1];
}

void Layout::insertLeft(Domino a) {
	boardDominos.push_front(a);
}

void Layout::insertRight(Domino a) {
	boardDominos.push_back(a);
}

void Layout::printBoard() {
	cout << "\nBoard  Layout: ";
	cout << "L - ";
	for (Domino i : boardDominos) {
		i.printDomino();
	}
	cout << " - R" << endl;

	cout << "\n----------------------------------------------------------------\n" << endl;
}