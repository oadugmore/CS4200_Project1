#pragma once

#include <exception>
#include <vector>
#include "Action.h"
#include "Problem.h"

const int STATE_SIZE = 9;

using namespace std;

class EightPuzzleProblem : public Problem
{
private:
	int LocateEmptyTile(vector<int> state);
	void Swap(int & a, int & b);
public:
	enum MoveActionType
	{
		Up, Down, Left, Right
	};
	class MoveAction : public Action
	{
	private:
		MoveActionType type;
	public:
		MoveActionType GetType() { return type; }
		MoveAction() { };
		MoveAction(MoveActionType type) { this->type = type; }
	};
	exception InvalidMoveException;
	EightPuzzleProblem();
	~EightPuzzleProblem();
	vector<int> Result(vector<int> currentState, MoveAction action);
};

