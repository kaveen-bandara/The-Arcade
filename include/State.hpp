#pragma once

#include <SFML/System/Time.hpp>
using namespace sf;

namespace Engine
{
	class State
	{
	public:
		State() {};
		virtual ~State() {};

		virtual void init() = 0;
		virtual void processInput() = 0;
		virtual void update(Time deltaTime) = 0;
		virtual void draw() = 0;

		virtual void pause() {};
		virtual void start() {};
	};
}