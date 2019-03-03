#include "TileDistanceHeuristic.h"



int TileDistanceHeuristic::Estimate(State* state)
{
	vector<int> stateData = (static_cast<PuzzleState*>(state))->StateData();
	int total = 0;
	for (int i = 0; i < STATE_SIZE; i++)
	{
		total += abs(stateData[i] - i);
	}
	return total;
}