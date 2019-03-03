#include "Node.h"

Node::Node(State* state, Node* parent, Action action, int pathCost)
{
	this->state = state;
	this->parent = parent;
	this->action = action;
	this->pathCost = pathCost;
}

//Node::~Node()
//{
//	if (parent != nullptr) delete parent;
//}

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