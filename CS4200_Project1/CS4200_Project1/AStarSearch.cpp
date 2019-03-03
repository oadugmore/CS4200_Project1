#include "AStarSearch.h"
#include <iostream>
#include <queue>

using namespace std;

AStarSearch::Solution* AStarSearch::Search(Problem* problem, Heuristic heuristic)
{
	unique_ptr<Node> node(new Node(problem->InitialState(), nullptr, Action(), 0)); // might need to be shared_ptr?
	priority_queue<Node, vector<Node>, CompareNodes> frontier;
	vector<Node> frontierList; // for searching the frontier
	Solution* solution = new Solution();
	vector<Action> actions = problem->GetActions();
	vector<Node> exploredSet;
	frontier.push(*node);
	frontierList.push_back(*node);

	while (!frontier.empty())
	{
		*node = frontier.top();
		frontier.pop();
		if (problem->GoalTest(node->GetState()))
		{
			solution->finalNode = &(*node);
			break;
		}

		exploredSet.push_back(*node);

		for (int i = 0; i < actions.size(); i++)
		{
			Node* child = ChildNode(problem, heuristic, &*node, actions[i]);
			if (child == nullptr) continue;
			State* childState = child->GetState();
			bool found = false;
			int frontierPos;
			for (int i = 0; i < frontierList.size(); i++)
			{
				if (childState == frontierList[i].GetState())
				{
					found = true;
					frontierPos = i;
					break;
				}
			}
			if (!found)
			{
				for (int i = 0; i < exploredSet.size(); i++)
				{
					if (childState == exploredSet[i].GetState())
					{
						found = true;
						break;
					}
				}
			}

			if (!found)
			{
				frontier.push(*child);
				frontierList.push_back(*child);
			}
			else if (frontierList[frontierPos].GetEstimatedCost() > child->GetEstimatedCost())
			{
				cout << "Replace child in frontier..." << endl;
			}

		}
	}

	return solution;
}

Node* AStarSearch::ChildNode(Problem* problem, Heuristic heuristic, Node* parent, Action action)
{
	//Node* parent = new Node(parent);
	State* state; 
	try
	{
		state = problem->Result(parent->GetState(), action);
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
	
	int estCost = parent->GetPathCost() + heuristic.Estimate(state);
	Node* child = new Node(state, parent, action, estCost);
	return child;
}