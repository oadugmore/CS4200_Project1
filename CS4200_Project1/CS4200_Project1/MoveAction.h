#pragma once

#include "Action.h"
#include <exception>

class MoveAction : public Action
{
public:
	enum MoveActionType
	{
		Up, Down, Left, Right
	};
	//static exception InvalidMoveException;
	MoveActionType GetType() { return type; }
	MoveAction(MoveActionType type) { this->type = type; }
	MoveAction();
private:
	MoveActionType type;
};