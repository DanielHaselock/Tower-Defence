#include "pch.h"
#include "Player.h"

void TD::Player::UpdateMoney(sf::RenderWindow& my_window, int money, sf::Font my_font)
{

	my_text.setFont(my_font);
	my_text.setString(std::to_string(money) + "$");
	my_text.setCharacterSize(70);
	my_text.setPosition(650, 580);
	my_window.draw(my_text);




}

void TD::Player::UpdateLives(sf::RenderWindow& my_window, int lives, sf::Font my_font)
{
	my_text.setFont(my_font);
	my_text.setString(std::to_string(lives) + "lives");
	my_text.setCharacterSize(70);
	my_text.setPosition(850, 580);
	my_window.draw(my_text);
}


