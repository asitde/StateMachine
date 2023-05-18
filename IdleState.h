#ifndef IDLE_STATE_H
#define IDLE_STATE_H

#include "State.h"

class IdleState : public State {

public:
	IdleState();
	~IdleState() override;

public:
	bool prepare() override;
	bool process() override;
	State* getNextState(bool result, StateMachine* pMachine) override;
};

#endif // !IDLE_STATE_H
