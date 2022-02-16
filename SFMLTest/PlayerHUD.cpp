#include "pch.h"
#include "PlayerHUD.h"
#include <iostream>
using namespace TD;
void PlayerHUD::Init_GameMenu(int x, int y, char const* file, PlayerHUD& Player, Renderer& renderer)
{

	HUDWindow* My_HUDWindow = new HUDWindow();
	sf::Vector2i my_vector(x, y);

	Sprite& my_main_menu_sprite = renderer.CreateSprite(*renderer.LoadTextureFile(file), my_vector, 0);
	my_main_menu_sprite.setScale(renderer.get_window()->get_window().getSize().x / my_main_menu_sprite.getGlobalBounds().width,
		renderer.get_window()->get_window().getSize().y / my_main_menu_sprite.getGlobalBounds().height);
	My_HUDWindow->sprite = &my_main_menu_sprite;
	Player.Windows.push_back(My_HUDWindow);

}
void PlayerHUD::Init_Buttons(int x, int y, char const** file, PlayerHUD& Player, Renderer& renderer, std::function<void(int x ,int y)> my_function2)
{

	HUDButton* my_Button = Player.Windows[0]->AddButton<HUDButton>();
	
	Sprite& my_sprite2 = renderer.CreateSprite(*renderer.LoadTextureFile(file[0]), sf::Vector2i(x,y), 0);
	my_Button->my_Sprite = &my_sprite2;
	my_Button->my_Sprite->setPosition((float)x, (float)y);

	my_Button->HoveredSprite->setTexture(*renderer.LoadTextureFile(file[1]));
	my_Button->HoveredSprite->setPosition((float)x, (float)y);

	my_Button->ClickedSprite->setTexture(*renderer.LoadTextureFile(file[2]));
	my_Button->ClickedSprite->setPosition((float)x, (float)y);

	my_Button->Default_sprite->setTexture(*renderer.LoadTextureFile(file[0]));
	my_Button->Default_sprite->setPosition((float)x, (float)y);


	my_Button->my_function = my_function2;




}

void PlayerHUD::ClearWindows()
{
	for (int x = 0; x < Windows.size(); x++)
	{
		Windows[x]->Clear();
	}
}


void PlayerHUD::Init_Game(int x, int y, char const* file, PlayerHUD& Player, Renderer& renderer)
{
	HUDWindow* My_HUDWindow = new HUDWindow();
	sf::Vector2i my_vector(x, y);

	Sprite& my_main_menu_sprite = renderer.CreateSprite(*renderer.LoadTextureFile(file), my_vector, 0);
	my_main_menu_sprite.setScale(renderer.get_window()->get_window().getSize().x / my_main_menu_sprite.getGlobalBounds().width, 1);
	My_HUDWindow->sprite = &my_main_menu_sprite;
	Player.Windows.push_back(My_HUDWindow);
}

void PlayerHUD::Init_Pause()
{

}

void PlayerHUD::Init_GameOver()
{

}
