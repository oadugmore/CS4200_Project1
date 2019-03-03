#pragma once

#include "Node.h"
#include "Problem.h"
#include "Heuristic.h"
#include "Action.h"


class AStarSearch
{
public:
	struct Solution
	{
		Solution() {}
		Node finalNode;
		int nodeCount = 0;
	};
	static Solution* Search(Problem* problem, Heuristic* heuristic);
private:
	static Node* ChildNode(Problem* problem, Heuristic* heuristic, shared_ptr<Node> parent, Action* action);
};

