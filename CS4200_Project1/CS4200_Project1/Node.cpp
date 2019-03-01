#include "Node.h"


Node::Node()
{
}

Node::Node(State initialState, int pathCost)
{
	this->state = initialState;
	this->pathCost = pathCost;
}


Node::~Node()
{
}
