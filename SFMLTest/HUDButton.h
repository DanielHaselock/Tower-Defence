#pragma once
#include "Sprite.h"
#include <SFML/System/Vector2.hpp>
#include <functional>
namespace TD
{


	class HUDButton
	{
	public:
		HUDButton();
		Sprite* my_Sprite;
		Sprite* HoveredSprite;
		Sprite* ClickedSprite;
		Sprite* Default_sprite;
		sf::Vector2i RelativePosition;
		std::function<void(int, int)> my_function;


	};
}