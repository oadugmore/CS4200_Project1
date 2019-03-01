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
		Node finalNode;
	};
	AStarSearch();
	~AStarSearch();
	Solution* Search(Problem problem, Heuristic heuristic);
	Node* ChildNode(Problem problem, Heuristic heuristic, Node parent, Action action);
};

