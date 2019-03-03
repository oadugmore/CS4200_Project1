#pragma once
#include "Heuristic.h"
#include "EightPuzzleProblem.h"

class TileDistanceHeuristic :
	public Heuristic
{
public:
	int Estimate(State* state);
};

