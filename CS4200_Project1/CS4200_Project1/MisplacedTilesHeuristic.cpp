#include "MisplacedTilesHeuristic.h"


int MisplacedTilesHeuristic::Estimate(State* state)
{
	vector<int> stateData = (static_cast<PuzzleState*>(state))->StateData();
	int total = 0;
	for (int i = 0; i < STATE_SIZE; i++)
	{
		if (stateData[i] != i) total++;
	}
	return total;
}