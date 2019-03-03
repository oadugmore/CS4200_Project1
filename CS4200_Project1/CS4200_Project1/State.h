#pragma once
class State
{
public:

	virtual bool operator==(const State &other) = 0;
};