#pragma once

#include "State.h"

class Problem
{
	
public:
	template<class T>
	bool GoalTest(T state);
	virtual State InitialState() { return State(); }
};

