#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include "MonitoringState.h"
#include "StateMachine.h"

MonitoringState::MonitoringState()
	:State() {
	std::cout << "Constructing MonitoringState" << std::endl;
}

MonitoringState::~MonitoringState() {
	std::cout << "Destroying MonitoringState" << std::endl;
}

bool MonitoringState::prepare() {
	std::cout << "MonitoringState::prepare()" << std::endl;
	return true;
}

bool MonitoringState::process() {
	auto retVal{ false };
	std::cout << "MonitoringState::process()" << std::endl;
	while (true) {
		char c = _getch();
		if (c == 'n') {
			std::cout << "Switching to IdleState" << std::endl;
			retVal = true;
			break;
		}
		else if (c == 'q') {
			std::cout << "Exit state machine from MonitoringState" << std::endl;
			retVal = false;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return retVal;
}

State* MonitoringState::getNextState(bool result, StateMachine* pMachine) {
	State* nextState{ nullptr };
	if (result) {
		nextState = pMachine->getIdleState();
	}
	return nextState;
}