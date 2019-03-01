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
	static Solution* Search(Problem problem, Heuristic heuristic);
	static Node* ChildNode(Problem problem, Heuristic heuristic, Node parent, Action action);
};

