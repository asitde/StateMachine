#ifndef INITIALIZATION_STATE_H
#define INITIALIZATION_STATE_H

#include "State.h"

class InitializationState : public State {

public:
	InitializationState();
	~InitializationState() override;

public:
	bool prepare() override;
	bool process() override;
	State* getNextState(bool result, StateMachine* pMachine) override;
};

#endif // !INITIALIZATION_STATE_H