#pragma once

#include <exception>
#include <vector>

const int STATE_SIZE = 9;

using namespace std;

class EightPuzzleProblem
{
public:
	enum Action
	{
		Left, Right, Up, Down
	};
	exception InvalidMoveException;
	EightPuzzleProblem();
	~EightPuzzleProblem();
	int LocateEmptyTile(vector<int> state);
	void Swap(int & a, int & b);
	vector<int> Result(vector<int> currentState, Action action);
};

