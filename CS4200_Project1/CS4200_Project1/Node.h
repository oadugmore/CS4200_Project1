#pragma once

#include "EightPuzzleProblem.h"

using namespace std;



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
	~Node();
};

