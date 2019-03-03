#pragma once
#include "State.h"

class Heuristic
{
public:
	virtual int Estimate(State* state) { return 0; }
};

