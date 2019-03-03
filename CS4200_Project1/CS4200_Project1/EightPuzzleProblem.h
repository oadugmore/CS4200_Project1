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
	bool GoalTest(State* state);
	State* InitialState();
	EightPuzzleProblem(PuzzleState initialState);
	State* Result(State* currentState, Action action);
	vector<Action> GetActions();
};

