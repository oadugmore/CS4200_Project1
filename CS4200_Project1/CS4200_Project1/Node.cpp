#include "Node.h"

Node::Node(State* state, Node* parent, Action* action, int pathCost, int estimatedCost)
{
	this->state = state;
	this->parent = parent;
	this->action = action;
	this->pathCost = pathCost;
	this->estimatedCost = estimatedCost;
}

int Node::GetPathCost()
{
	return pathCost;
}

State* Node::GetState()
{
	return state;
}

Node* Node::GetParent()
{
	return parent;
}

int Node::GetEstimatedCost()
{
	return estimatedCost;
}