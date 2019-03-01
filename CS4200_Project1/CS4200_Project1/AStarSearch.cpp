#include "AStarSearch.h"
#include <queue>

using namespace std;

AStarSearch::AStarSearch()
{
}


AStarSearch::~AStarSearch()
{
}

AStarSearch::Solution* AStarSearch::Search(Problem problem, Heuristic heuristic)
{
	Node node(problem.InitialState(), 0);
	priority_queue<Node> frontier;
	Solution* solution = new Solution;

	return solution;
}
Node* AStarSearch::ChildNode(Problem problem, Heuristic heuristic, Node parent, Action action)
{
	Node* child = new Node;

	return child;
}