#pragma once

#include <vector>
#include "State.h"

using namespace std;

class PuzzleState : public State
{
private:
	vector<int> stateData;
public:
	PuzzleState() {}
	PuzzleState(vector<int> stateData) { this->stateData = stateData; }
	~PuzzleState() {}
	vector<int> StateData() { return stateData; }
};