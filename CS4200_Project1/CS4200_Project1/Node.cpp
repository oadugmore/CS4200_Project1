#include "Node.h"


Node::Node()
{
}

Node::Node(State initialState, int pathCost)
{
	this->state = initialState;
	this->pathCost = pathCost;
}

State* Node::GetState()
{
	return &state;
}


Node::~Node()
{
}
