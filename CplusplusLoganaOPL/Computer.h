#pragma once
#include "Player.h"

class Computer : public Player {
	public:
		int getInput(int requiredSide);
};
