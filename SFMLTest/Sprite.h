#pragma once
#include <SFML/Window/Keyboard.hpp>
namespace TD
{


	class Sprite : public sf::Sprite
	{
	public:
		uint8_t Layer;

		Sprite(uint8_t Layer);


	};
}