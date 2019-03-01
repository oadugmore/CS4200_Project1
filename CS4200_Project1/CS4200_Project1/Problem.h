#pragma once

#include "State.h"

class Problem
{
	
public:
	virtual bool GoalTest(State state) { return false; }
	virtual State InitialState() { return State(); }
};

