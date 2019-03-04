#pragma once
#include <iostream>

using namespace std;

class State
{
public:

	virtual bool operator==(const State &other)
	{
		cout << "Wrong method!" << endl;
		return false;
	}
};