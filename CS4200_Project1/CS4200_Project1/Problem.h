#pragma once

#include "State.h"
#include "Action.h"
#include <vector>

using namespace std;

class Problem
{
	
public:
	virtual bool GoalTest(State* state) = 0;
	virtual State* InitialState() = 0;
	virtual vector<Action*> GetActions() = 0;
	virtual State* Result(State* currentState, Action* action) = 0;
};

