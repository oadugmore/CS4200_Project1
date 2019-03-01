#pragma once

#include <vector>
#include "State.h"

class PuzzleState :
	public State
{
public:
	PuzzleState();
	~PuzzleState();
	vector<int> StateData() {};
};

