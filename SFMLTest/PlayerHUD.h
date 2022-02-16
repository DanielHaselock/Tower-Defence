#pragma once
#include <vector>
#include "HUDWindow.h"
namespace TD
{
	class PlayerHUD
	{

	public:
		std::vector<HUDWindow*> Windows;
		void ClearWindows();
		void static Init_Game(int x, int y, char const* file, PlayerHUD& Player, Renderer& renderer);
		void Init_Pause();
		void Init_GameOver();
		static void Init_Buttons(int x, int y, char const** file, PlayerHUD& Player, Renderer& renderer, std::function<void(int x, int y)> my_function2);
		static void Init_GameMenu(int x, int y, char const* file, PlayerHUD& Player, Renderer& renderer);
		Sprite& CreateSprite(const sf::Texture& my_Texture, sf::Vector2i position);


	};
}