#pragma once

#include <vector>
#include <iostream>
#include "State.h"

using namespace std;

class PuzzleState : public State
{
private:
	vector<int> stateData;
public:
	PuzzleState() {}
	PuzzleState(vector<int> stateData) { this->stateData = stateData; }
	vector<int> StateData() const { return stateData; }
	bool operator==(const State &other)
	{
		//cout << "Compared states" << endl;
		for (int i = 0; i < stateData.size(); i++)
		{
			if (static_cast<const PuzzleState*>(&other)->StateData()[i] != stateData[i]) return false;
		}
		return true;
	}
	
};