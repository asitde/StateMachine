#include <iostream>
#include <thread>
#include "StateMachine.h"
#include "IdleState.h"
#include "InitializationState.h"
#include "MonitoringState.h"

StateMachine::StateMachine()
	: m_idleState(std::make_unique<IdleState>())
	, m_initializationState(std::make_unique<InitializationState>())
	, m_monitoringState(std::make_unique<MonitoringState>())
	, m_currentState(m_idleState.get())
	, m_isRunning(false)
{
	std::cout << "Constructing StateMachine" << std::endl;
}

StateMachine::~StateMachine() {
	std::cout << "Destroying StateMachine" << std::endl;
}

State* StateMachine::getIdleState() {
	return m_idleState.get();
}

State* StateMachine::getInitializationState() {
	return m_initializationState.get();
}

State* StateMachine::getMonitoringState() {
	return m_monitoringState.get();
}

void StateMachine::start() {
	std::thread stateMachineThread{ &StateMachine::run, this };
	stateMachineThread.detach();
}

void StateMachine::run() {
	setRunning(true);
	while (m_currentState) {
		m_currentState->prepare();
		bool result{ m_currentState->process() };
		m_currentState = m_currentState->getNextState(result, this);
	}
	setRunning(false);
}

bool StateMachine::isRunning() {
	std::lock_guard<std::mutex> lock{ m_mutexIsRunning };
	return m_isRunning;
}

void StateMachine::setRunning(bool b) {
	std::lock_guard<std::mutex> lock{ m_mutexIsRunning };
	m_isRunning = b;
}