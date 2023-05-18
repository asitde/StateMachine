// StateMachineApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>
#include "StateMachine.h"

int main()
{
    std::cout << "State machine implementation" << std::endl;
	StateMachine appStateMachine;
	appStateMachine.start();
	while (true) {
		if (appStateMachine.isRunning()) {
			std::cout << "State machine has started running." << std::endl;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	while (true) {
		if (!appStateMachine.isRunning()) {
			std::cout << "State machine has stopped" << std::endl;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

