#include "EightPuzzleProblem.h"

EightPuzzleProblem::EightPuzzleProblem(PuzzleState initialState)
{
	this->initialState = initialState;
}

State EightPuzzleProblem::InitialState() 
{ 
	return initialState; 
}

vector<Action> GetActions()
{
	vector<MoveAction> actions;//({ MoveAction::Down, MoveAction::Up, MoveAction::Right, MoveAction::Left });
	for (int i = 0; i < 4; i++)
	{
		actions.push_back(MoveAction(static_cast<MoveAction::MoveActionType>(i)));
	}
	return static_cast<vector<Action>>(actions);
}

bool EightPuzzleProblem::GoalTest(PuzzleState state)
{
	for (int i = 0; i < STATE_SIZE; i++)
	{
		if (state.StateData()[i] != i)
			return false;
	}
	return true;
}

int EightPuzzleProblem::LocateEmptyTile(vector<int> stateData)
{
	for (int i = 0; i < STATE_SIZE; i++)
	{
		if (stateData[i] == 0) return i;
	}
	return -1;
}

void EightPuzzleProblem::Swap(int& a, int& b)
{
	swap(a, b);
}

PuzzleState* EightPuzzleProblem::Result(PuzzleState currentState, MoveAction action)
{
	int emptyTileLocation = LocateEmptyTile(currentState.StateData()); // locate the empty tile
	vector<int> newStateData(currentState.StateData()); // copy of currentState that we can manipulate and return

	switch (action.GetType())
	{
	case MoveAction::Left:
		if (emptyTileLocation == 0 || emptyTileLocation == 3 || emptyTileLocation == 6)
		{
			throw MoveAction::InvalidMoveException();
		}
		Swap(newStateData[emptyTileLocation], newStateData[emptyTileLocation - 1]);
		break;
	case MoveAction::Right:
		if (emptyTileLocation == 2 || emptyTileLocation == 5 || emptyTileLocation == 8)
		{
			throw MoveAction::InvalidMoveException();
		}
		Swap(newStateData[emptyTileLocation], newStateData[emptyTileLocation + 1]);
		break;
	case MoveAction::Up:
		if (emptyTileLocation >= 0 && emptyTileLocation <= 2)
		{
			throw MoveAction::InvalidMoveException();
		}
		Swap(newStateData[emptyTileLocation], newStateData[emptyTileLocation - 3]);
		break;
	case MoveAction::Down:
		if (emptyTileLocation >= 6 && emptyTileLocation <= 8)
		{
			throw MoveAction::InvalidMoveException();
		}
		Swap(newStateData[emptyTileLocation], newStateData[emptyTileLocation + 3]);
		break;
	default:
		break;
	}
	return new PuzzleState(newStateData);
}
