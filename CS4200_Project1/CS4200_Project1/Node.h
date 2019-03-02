#pragma once

#include "State.h"
#include "Action.h"

class Node
{
private:
	//vector<int> state;
	//int state[9];
	State state;
	Node* parent;
	//EightPuzzleProblem::MoveAction action;
	Action action;
	int pathCost; // g(n)
	int estimatedCost; // g(n) + h(n)
	int depth;
public:
	Node();
	Node(State initialState, int pathCost);
	State* GetState();
	~Node();
};

