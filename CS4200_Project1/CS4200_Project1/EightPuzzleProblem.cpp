#include "EightPuzzleProblem.h"

EightPuzzleProblem::EightPuzzleProblem(PuzzleState initialState)
{
	this->initialState = initialState;
}

State* EightPuzzleProblem::InitialState() 
{ 
	return &initialState; 
}

vector<Action*> EightPuzzleProblem::GetActions()
{
	vector<Action*> actions;
	for (int i = 0; i < 4; i++)
	{
		MoveAction* a = new MoveAction(static_cast<MoveAction::MoveActionType>(i)); // delete heap data
		actions.push_back(a);
	}
	return actions;
}

bool EightPuzzleProblem::GoalTest(State* state)
{
	for (int i = 0; i < STATE_SIZE; i++)
	{
		if (static_cast<PuzzleState*>(state)->StateData()[i] != i)
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

State* EightPuzzleProblem::Result(State* currentState, Action* action)
{
	PuzzleState* state = static_cast<PuzzleState*>(currentState);
	int emptyTileLocation = LocateEmptyTile(state->StateData()); // locate the empty tile
	vector<int> newStateData(state->StateData()); // copy of currentState that we can manipulate and return

	switch (static_cast<MoveAction*>(action)->GetType())
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
	return static_cast<State*>(new PuzzleState(newStateData));
}
