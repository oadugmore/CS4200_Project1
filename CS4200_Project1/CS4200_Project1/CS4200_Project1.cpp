#include <iostream>
#include "EightPuzzleProblem.h"
#include "AStarSearch.h"
#include "MisplacedTilesHeuristic.h"
#include "TileDistanceHeuristic.h"

void printState(vector<int> state)
{
	for (int i = 0; i < STATE_SIZE; i += 3)
	{
		cout << state[i] << " " << state[i + 1] << " " << state[i + 2] << endl;
	}
}

int main()
{
    std::cout << "Hello World!\n";
	EightPuzzleProblem problem;
	MisplacedTilesHeuristic h1;
	TileDistanceHeuristic h2;
	AStarSearch search;
	unique_ptr<AStarSearch::Solution> solution(AStarSearch::Search(problem, h1));
	// solution(search.Search(problem, h1));
	vector<int> sampleStateData({ 0, 1, 2, 3, 4, 5, 6, 7, 8 });
	PuzzleState sampleState(sampleStateData);
	cout << "Sample state: \n";
	printState(sampleStateData);
	unique_ptr<PuzzleState> newState (problem.Result(sampleState, MoveAction(MoveAction::Down)));
	cout << "Ran result function. Sample state: \n";
	printState(sampleStateData);
	cout << "New state:\n";
	printState(newState->StateData());
	
}