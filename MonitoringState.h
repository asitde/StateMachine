#ifndef MONITORING_STATE_H
#define MONITORING_STATE_H

#include "State.h"

class MonitoringState : public State {

public:
	MonitoringState();
	~MonitoringState() override;

public:
	bool prepare() override;
	bool process() override;
	State* getNextState(bool result, StateMachine* pMachine) override;
};

#endif // !MONITORING_STATE_H