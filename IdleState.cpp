#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include "IdleState.h"
#include "StateMachine.h"

IdleState::IdleState()
	:State() {
	std::cout << "Constructing IdleState" << std::endl;
}

IdleState::~IdleState() {
	std::cout << "Destroying IdleState" << std::endl;
}

bool IdleState::prepare() {
	std::cout << "IdleState::prepare()" << std::endl;
	return true;
}

bool IdleState::process() {
	auto retVal{ false };
	std::cout << "IdleState::process()" << std::endl;
	while (true) {
		char c = _getch();
		if (c == 'n') {
			std::cout << "Switching to InitializationState" << std::endl;
			retVal = true;
			break;
		}
		else if (c == 'q') {
			std::cout << "Exit state machine from IdleState" << std::endl;
			retVal = false;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return retVal;
}

State* IdleState::getNextState(bool result, StateMachine* pMachine) {
	State* nextState{ nullptr };
	if (result) {
		nextState = pMachine->getInitializationState();
	}
	return nextState;
}
