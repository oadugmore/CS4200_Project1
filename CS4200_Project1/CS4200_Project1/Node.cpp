#include "Node.h"

Node::Node(State initialState, int pathCost)
{
	this->state = initialState;
	this->pathCost = pathCost;
}

//Node::~Node()
//{
//	if (parent != nullptr) delete parent;
//}

State* Node::GetState()
{
	return &state;
}

int Node::GetEstimatedCost()
{
	return estimatedCost;
}