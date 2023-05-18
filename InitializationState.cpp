#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include "InitializationState.h"
#include "StateMachine.h"

InitializationState::InitializationState()
	:State() {
	std::cout << "Constructing InitializationState" << std::endl;
}

InitializationState::~InitializationState() {
	std::cout << "Destroying InitializationState" << std::endl;
}

bool InitializationState::prepare() {
	std::cout << "InitializationState::prepare()" << std::endl;
	return true;
}

bool InitializationState::process() {
	auto retVal{ false };
	std::cout << "InitializationState::process()" << std::endl;
	while (true) {
		char c = _getch();
		if (c == 'n') {
			std::cout << "Switching to MonitoringState" << std::endl;
			retVal = true;
			break;
		}
		else if (c == 'q') {
			std::cout << "Exit state machine from InitializationState" << std::endl;
			retVal = false;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return retVal;
}

State* InitializationState::getNextState(bool result, StateMachine* pMachine) {
	State* nextState{ nullptr };
	if (result) {
		nextState = pMachine->getMonitoringState();
	}
	return nextState;
}
