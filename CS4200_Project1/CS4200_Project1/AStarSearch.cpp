#include "AStarSearch.h"
#include <iostream>
#include <queue>

using namespace std;

AStarSearch::Solution* AStarSearch::Search(Problem problem, Heuristic heuristic)
{
	
	unique_ptr<Node> node(new Node(problem.InitialState(), 0)); // might need to be shared_ptr?
	priority_queue<Node, vector<Node>, CompareNodes> frontier;
	Solution* solution = new Solution();
	vector<Action> actions = problem.GetActions();
	vector<Node> exploredSet;
	frontier.push(*node);


	while (!frontier.empty())
	{
		*node = frontier.top();
		frontier.pop();
		if (problem.GoalTest(*node->GetState()))
		{
			solution->finalNode = &(*node);
			break;
		}
		// add node to explored

		for (int i = 0; i < actions.size(); i++)
		{
			
		}
	}

	return solution;
}
Node* AStarSearch::ChildNode(Problem problem, Heuristic heuristic, Node parent, Action action)
{
	Node* child = new Node;

	return child;
}