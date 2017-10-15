#include "stdafx.h"
#include "Round.h"

void lineBreak() {
	cout << "\n";
}

int main() {
	
	Round round(6);
	round.setHands();
	round.printDetails();

	system("pause");
}

