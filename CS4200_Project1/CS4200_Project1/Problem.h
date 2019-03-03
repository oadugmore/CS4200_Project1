#pragma once

#include "State.h"
#include "Action.h"
#include <vector>

using namespace std;

class Problem
{
	
public:
	virtual bool GoalTest(State state) { return false; }
	virtual State InitialState() { return State(); }
	virtual vector<Action> GetActions() { return vector<Action>(); }
};

