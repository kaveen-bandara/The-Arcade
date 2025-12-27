
#include "../include/StateMap.hpp"

Engine::StateMap::StateMap() : m_add(false), m_replace(false), m_remove(false)
{
}

Engine::StateMap::~StateMap()
{
}

void Engine::StateMap::add(unique_ptr<State> toAdd, bool replace = false)
{
	m_add = true;
	m_newState = move(toAdd);
	m_replace = replace;
}

void Engine::StateMap::popCurrent()
{
	m_remove = true;
}

void Engine::StateMap::processStateChange()
{
	if (m_remove && (!m_stateStack.empty()))
	{
		m_stateStack.pop();

		if (!m_stateStack.empty())
		{
			m_stateStack.top()->start();
		}

		m_remove = false;
	}

	if (m_add)
	{
		if (m_replace && (!m_stateStack.empty()))
		{
			m_stateStack.pop();
			m_replace = false;
		}

		if (!m_stateStack.empty())
		{
			m_stateStack.top()->pause();
		}

		m_stateStack.push(move(m_newState));
		m_add = false;
	}
}

unique_ptr<Engine::State>& Engine::StateMap::getCurrent()
{
	return m_stateStack.top();
}