#pragma once
#include <iostream>
#include "State.h"
#include "Action.h"

using namespace std;

class Node
{
private:
	//vector<int> state;
	//int state[9];
	State* state;
	shared_ptr<Node> parent;
	//EightPuzzleProblem::MoveAction action;
	Action* action;
	int pathCost; // g(n)
	int estimatedCost; // g(n) + h(n)
	int depth;
public:
	Node(State* state, shared_ptr<Node> parent, Action* action, int pathCost, int estimatedCost);
	Node() {}
	shared_ptr<Node> GetParent();
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
