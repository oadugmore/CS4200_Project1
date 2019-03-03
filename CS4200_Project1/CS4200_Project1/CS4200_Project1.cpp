#include <iostream>
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

int main()
{
    std::cout << "Program: Eight-Puzzle-Problem" << endl << endl;
	vector<int> sampleStateData({ 1, 0, 2, 3, 4, 5, 6, 7, 8 });
	PuzzleState sampleState(sampleStateData);
	EightPuzzleProblem problem(sampleState);
	MisplacedTilesHeuristic h1;
	TileDistanceHeuristic h2;
	unique_ptr<AStarSearch::Solution> solution(AStarSearch::Search(&problem, &h1));
	//cout << solutionState << endl;
	// solution(search.Search(problem, h1));
	cout << "Start state: \n";
	printState(sampleState);
	//cout << endl << "Move down" << endl << endl;
	//unique_ptr<PuzzleState> newState (problem.Result(sampleState, MoveAction(MoveAction::Down)));
	//cout << "Ran result function. Sample state: \n";
	//printState(sampleStateData);
	//cout << "New state:\n";
	//printState(newState->StateData());
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
	
	return 0;
}