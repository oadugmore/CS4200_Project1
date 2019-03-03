#pragma once

#include "State.h"
#include "Action.h"

class Node
{
private:
	//vector<int> state;
	//int state[9];
	State* state;
	Node* parent;
	//EightPuzzleProblem::MoveAction action;
	Action action;
	int pathCost; // g(n)
	int estimatedCost; // g(n) + h(n)
	int depth;
public:
	Node(State* state, Node* parent, Action action, int pathCost);
	Node() {}
	//~Node();
	Node* GetParent();
	State* GetState();
	int GetEstimatedCost();
	int GetPathCost();
};

class CompareNodes
{
public:
	bool operator() (Node a, Node b)
	{
		return a.GetEstimatedCost() > b.GetEstimatedCost();
	}
};
