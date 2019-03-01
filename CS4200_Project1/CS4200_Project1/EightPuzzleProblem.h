#pragma once

#include <vector>
#include "Problem.h"
#include "MoveAction.h"
#include "PuzzleState.h"

const int STATE_SIZE = 9;

using namespace std;

class EightPuzzleProblem : public Problem
{
private:
	PuzzleState initialState;
	int LocateEmptyTile(vector<int> stateData);
	void Swap(int & a, int & b);
public:
	bool GoalTest(PuzzleState state);
	State InitialState();
	EightPuzzleProblem();
	~EightPuzzleProblem();
	PuzzleState* Result(PuzzleState currentState, MoveAction action);
};

