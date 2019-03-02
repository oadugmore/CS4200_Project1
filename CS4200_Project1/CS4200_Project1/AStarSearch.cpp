#include "AStarSearch.h"
#include <iostream>
#include <queue>

using namespace std;


AStarSearch::Solution* AStarSearch::Search(Problem problem, Heuristic heuristic)
{
	
	unique_ptr<Node> node((problem.InitialState(), 0);
	priority_queue<Node> frontier;
	Solution* solution = new Solution;
	vector<Node> exploredSet;
	frontier.push(node);

	while (!frontier.empty())
	{

	}

	return solution;
}
Node* AStarSearch::ChildNode(Problem problem, Heuristic heuristic, Node parent, Action action)
{
	Node* child = new Node;

	return child;
}