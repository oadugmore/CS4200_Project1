#include "pch.h"
#include "EightPuzzleProblem.h"



EightPuzzleProblem::EightPuzzleProblem()
{
}


EightPuzzleProblem::~EightPuzzleProblem()
{
}

int EightPuzzleProblem::LocateEmptyTile(vector<int> state)
{
	for (int i = 0; i < STATE_SIZE; i++)
	{
		if (state[i] == 0) return i;
	}
}

void EightPuzzleProblem::Swap(int& a, int& b)
{
	swap(a, b);
}

vector<int> EightPuzzleProblem::Result(static vector<int> currentState, Action action)
{
	int emptyTileLocation = LocateEmptyTile(currentState); // locate the empty tile
	vector<int> newState (currentState); // copy of currentState that we can manipulate and return

	switch (action)
	{
	case EightPuzzleProblem::Left:
		if (emptyTileLocation == 0 || emptyTileLocation == 3 || emptyTileLocation == 6)
		{
			throw InvalidMoveException;
		}
		Swap(newState[emptyTileLocation], newState[emptyTileLocation - 1]);
		break;
	case EightPuzzleProblem::Right:
		if (emptyTileLocation == 2 || emptyTileLocation == 5 || emptyTileLocation == 8)
		{
			throw InvalidMoveException;
		}
		Swap(newState[emptyTileLocation], newState[emptyTileLocation + 1]);
		break;
	case EightPuzzleProblem::Up:
		if (emptyTileLocation >= 0 && emptyTileLocation <= 2)
		{
			throw InvalidMoveException;
		}
		Swap(newState[emptyTileLocation], newState[emptyTileLocation - 3]);
		break;
	case EightPuzzleProblem::Down:
		if (emptyTileLocation >= 6 && emptyTileLocation <= 8)
		{
			throw InvalidMoveException;
		}
		Swap(newState[emptyTileLocation], newState[emptyTileLocation + 3]);
		break;
	default:
		break;
	}
	return newState;
}
