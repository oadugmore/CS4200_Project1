// CS4200_Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "EightPuzzleProblem.h"
#include "AStarSearch.h"
#include "MisplacedTilesHeuristic.h"
#include "TileDistanceHeuristic.h"

void printState(vector<int> state)
{
	for (int i = 0; i < STATE_SIZE; i += 3)
	{
		cout << state[i] << " " << state[i + 1] << " " << state[i + 2] << endl;
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
	EightPuzzleProblem problem;
	MisplacedTilesHeuristic h1;
	TileDistanceHeuristic h2;
	AStarSearch search;
	unique_ptr<AStarSearch::Solution> solution(search.Search(problem, h1));
	vector<int> sampleState({ 0, 1, 2, 3, 4, 5, 6, 7, 8 });
	cout << "Sample state: \n";
	printState(sampleState);
	vector<int> newState = problem.Result(sampleState, EightPuzzleProblem::MoveAction(EightPuzzleProblem::Down));
	cout << "Ran result function. Sample state: \n";
	printState(sampleState);
	cout << "New state:\n";
	printState(newState);
	
}
