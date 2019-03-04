#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include "EightPuzzleProblem.h"
#include "AStarSearch.h"
#include "MisplacedTilesHeuristic.h"
#include "TileDistanceHeuristic.h"


void printState(PuzzleState state)
{
	for (int i = 0; i < STATE_SIZE; i += 3)
	{
		cout << state.StateData()[i] << " " << state.StateData()[i + 1] << " " << state.StateData()[i + 2] << endl;
	}
}

bool solvable(vector<int> stateData)
{
	int inversions = 0;
	for (int i = 0; i < STATE_SIZE - 1; i++)
	{
		for (int j = i + 1; j < STATE_SIZE; j++)
		{
			if (stateData[i] != 0 && stateData[j] != 0)
				if (stateData[i] > stateData[i + 1]) inversions++;
		}
	}
	return (inversions % 2 == 0);
}

int main()
{
    cout << "Program: Eight-Puzzle-Problem" << endl << endl;
	vector<int> stateData({ 1, 3, 6, 8, 0, 2, 7, 4, 5 });
	bool viable = false;
	while (!viable)
	{
		random_shuffle(stateData.begin(), stateData.end());
		viable = solvable(stateData);
	}

	cout << "Found potential valid state: " << endl;
	printState(stateData);

	PuzzleState sampleState(stateData);
	EightPuzzleProblem problem(sampleState);
	MisplacedTilesHeuristic h1;
	TileDistanceHeuristic h2;
	unique_ptr<AStarSearch::Solution> solution(AStarSearch::Search(&problem, &h2));
	//cout << solutionState << endl;
	// solution(search.Search(problem, h1));
	cout << "Start state: \n";
	printState(sampleState);
	Node n = solution->finalNode;
	unique_ptr<PuzzleState> state(static_cast<PuzzleState*>(n.GetState()));
	cout << "Path from goal to start state:" << endl << endl;
	printState(*state);
	for (int i = 0; i < solution->finalNode.GetPathCost(); i++)
	{
		n = *n.GetParent();
		cout << endl << endl;
		printState(*(static_cast<PuzzleState*>(n.GetState())));
	}

	cout << endl << endl << "Depth: " << solution->finalNode.GetPathCost() << endl;
	cout << "Number of nodes generated: " << solution->nodeCount << endl;
	
	return 0;
}