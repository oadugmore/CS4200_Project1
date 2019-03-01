#pragma once

#include "State.h"

class Problem
{
	
public:
	virtual bool GoalTest(State state);
	virtual State InitialState();
};

