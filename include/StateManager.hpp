#pragma once

#include <memory>
#include <stack>

#include "../include/State.hpp"

namespace Engine
{
	class StateManager
	{
	private:
		std::stack<std::unique_ptr<State>> m_stateStack;
		std::unique_ptr<State> m_newState;

		bool m_add;
		bool m_replace;
		bool m_remove;

	public:
		StateManager();
		~StateManager();

		void add(std::unique_ptr<State> toAdd, bool replace = false);
		void popCurrent();
		void processStateChange();
		std::unique_ptr<State>& getCurrent();
	};
}
