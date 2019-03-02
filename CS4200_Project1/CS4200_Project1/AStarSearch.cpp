#include "AStarSearch.h"
#include <iostream>
#include <queue>

using namespace std;

AStarSearch::Solution* AStarSearch::Search(Problem problem, Heuristic heuristic)
{
	
	unique_ptr<Node> node(new Node(problem.InitialState(), 0));
	priority_queue<Node, vector<Node>, CompareNodes> frontier;
	Solution* solution = new Solution();
	vector<Node> exploredSet;
	frontier.push(*node);

	while (!frontier.empty())
	{
		frontier.pop();
	}

	return solution;
}
Node* AStarSearch::ChildNode(Problem problem, Heuristic heuristic, Node parent, Action action)
{
	Node* child = new Node;

	return child;
}