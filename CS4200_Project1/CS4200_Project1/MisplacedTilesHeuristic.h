#pragma once
#include "Heuristic.h"
#include "EightPuzzleProblem.h"

class MisplacedTilesHeuristic :
	public Heuristic
{
public:
	int Estimate(State* state);
};

