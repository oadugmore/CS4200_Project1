#pragma once

#include "EightPuzzleProblem.h"

using namespace std;



class Node
{
private:
	//vector<int> state;
	int state[9];
	Node* parent;
	EightPuzzleProblem::Action action;
	int pathCost;
	int depth;
public:
	Node();
	~Node();
};

