#include "pch.h"
namespace TD
{


	class MouseClickEvent
	{
	public:
		MouseClickEvent(sf::Mouse::Button Button, sf::Event::EventType Event);

		sf::Mouse::Button Button;
		sf::Event::EventType Event;
		bool operator<(const MouseClickEvent& my_MouseClickEvent) const;

	};
}