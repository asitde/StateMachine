#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <memory>
#include <mutex>
#include "State.h"

// Forward declarations
class State;
class IdleState;
class InitializationState;
class MonitoringState;

class StateMachine {

public:
	StateMachine();
	~StateMachine();
	void start();
	State* getIdleState();
	State* getInitializationState();
	State* getMonitoringState();
	bool isRunning();

private:
	void run();
	void setRunning(bool b);

private:
	std::unique_ptr<IdleState> m_idleState;
	std::unique_ptr<InitializationState> m_initializationState;
	std::unique_ptr<MonitoringState> m_monitoringState;
	State* m_currentState;
	bool m_isRunning;
	std::mutex m_mutexIsRunning;
};

#endif // !STATE_MACHINE_H