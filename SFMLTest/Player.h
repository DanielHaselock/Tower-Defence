#pragma once
#include "PlayerHUD.h"


namespace TD
{


	class Player
	{
	public:
		Player()
		{
			money = 0;
			base_health = 0;
		};
		PlayerHUD HUD;
		unsigned int money;
		unsigned int base_health;
		unsigned int lives = 20;



		sf::Text my_text;


		void UpdateMoney(sf::RenderWindow& my_window, int amount, sf::Font my_font);
		void UpdateLives(sf::RenderWindow& my_window, int lives, sf::Font my_font);
	};
}