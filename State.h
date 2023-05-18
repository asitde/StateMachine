#ifndef STATE_H
#define STATE_H

class StateMachine;

class State {

public:
	State();
	virtual ~State();

public:
	virtual bool prepare() = 0;
	virtual bool process() = 0;
	virtual State* getNextState(bool result, StateMachine* pMachine) = 0;
};
#endif // !STATE_H

