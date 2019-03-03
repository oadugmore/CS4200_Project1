#pragma once

#include "Action.h"
#include <exception>

using namespace std;

class MoveAction : public Action
{
public:
	enum MoveActionType
	{
		Up, Down, Left, Right
	};
	struct InvalidMoveException : public exception { };
	MoveActionType GetType() { return type; }
	MoveAction(MoveActionType type) { this->type = type; }
	void Dummy() {}
private:
	MoveActionType type;
};