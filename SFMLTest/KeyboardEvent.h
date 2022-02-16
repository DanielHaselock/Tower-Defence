#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
namespace TD
{


	class KeyboardEvent
	{
	public:
		sf::Keyboard::Key Keycode;
		sf::Event::EventType Event;
		bool operator<(const KeyboardEvent& my_KeyboardEvent) const;
	};
}