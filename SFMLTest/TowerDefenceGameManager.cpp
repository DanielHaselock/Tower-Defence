#include "pch.h"
#include "TowerDefenceGameManager.h"
#include "HUDWindow.h"
#include <iostream>
#include "NormalTower.h"
#include "StunTower.h"
#include "ExplosiveTower.h"
using namespace TD;
TowerDefenceGameManager TowerDefenceGameManager::my_Static_TowerDefenceGameManager;

TowerDefenceGameManager& TowerDefenceGameManager::GetInstance()
{
	return my_Static_TowerDefenceGameManager;

}
void TowerDefenceGameManager::Update()
{
	UpdateDeltaTime();
	EnemyArmy.UpAllEnemies(this->DeltaTime);

	for (int i = 0; i < Map.getTowers().size(); i++)
	{
		if (Map.getTowers()[i] != towerChoose)
		{
			Map.getTowers()[i]->Update(EnemyArmy, renderer, DeltaTime, player);
		}


	}


	renderer.DrawSprites();




}
void TowerDefenceGameManager::Init(InputScanner* m_inputScanner)
{
	this->m_inputScanner = m_inputScanner;
}
void TowerDefenceGameManager::setWindow(Window* my_window)
{

	this->renderer.setWindow(my_window);

}

void TowerDefenceGameManager::Init_GameMenu()
{
	m_inputScanner->ClearInputActions();

	char const* File[3]
	{
		"Assets/hud/PNG/squareRed.png",
		"Assets/hud/PNG/squareBlue.png",
		"Assets/hud/PNG/squareGreen.png",
	};


	PlayerHUD::Init_GameMenu(0, 0, "Assets/hud/PNG/metalPanel.png", player.HUD, renderer);

	std::function<void(int x, int y)> my_function2 = [this](int x, int y)
	{
		CurrentState = GameState::RUNNING;
		map_choose = "Assets/maps/level1.cfg";

	};
	std::function<void(int x, int y)> my_function3 = [this](int x, int y)
	{
		CurrentState = GameState::RUNNING;
		map_choose = "Assets/maps/level2.cfg";

	};
	std::function<void(int x, int y)> my_function4 = [this](int x, int y)
	{
		CurrentState = GameState::RUNNING;
		map_choose = "Assets/maps/level3.cfg";

	};

	PlayerHUD::Init_Buttons(100, 100, File, player.HUD, renderer, my_function2);
	PlayerHUD::Init_Buttons(100, 300, File, player.HUD, renderer, my_function3);
	PlayerHUD::Init_Buttons(100, 500, File, player.HUD, renderer, my_function4);

	this->CurrentState = GameState::MAIN_MENU;

	KeyboardEvent esc_key;
	esc_key.Keycode = sf::Keyboard::Escape;
	esc_key.Event = sf::Event::KeyPressed;

	m_inputScanner->AddKeyboardAction(esc_key, renderer.get_window()->quit_window);


	KeyboardEvent p_key{};
	p_key.Keycode = sf::Keyboard::P;
	p_key.Event = sf::Event::KeyPressed;

	InputScanner::KeyboardAction actionKey = [this]() {CurrentState = GameState::RUNNING; };

	m_inputScanner->AddKeyboardAction(p_key, actionKey);

	Player& my_player = this->player;
	MouseClickEvent left_click(sf::Mouse::Button::Left, sf::Event::MouseButtonPressed);
	InputScanner::MouseClickAction actionMouse = [my_player](sf::Mouse::Button button, int x, int y)
	{
		for (int i = 0; i < my_player.HUD.Windows.size(); i++)
		{
			for (int j = 0; j < my_player.HUD.Windows[i]->Buttons.size(); j++)
			{
				if (my_player.HUD.Windows[i]->Buttons[j]->my_Sprite->getGlobalBounds().contains((float)x, (float)y))
				{

					my_player.HUD.Windows[i]->Buttons[j]->my_Sprite->setTexture(*my_player.HUD.Windows[i]->Buttons[j]->ClickedSprite->getTexture());
					my_player.HUD.Windows[i]->Buttons[j]->my_function(x, y);
				}
				else
				{
					my_player.HUD.Windows[i]->Buttons[j]->my_Sprite->setTexture(*my_player.HUD.Windows[i]->Buttons[j]->Default_sprite->getTexture());

				}



			}



		}



	};

	m_inputScanner->AddMouseAction(left_click, actionMouse);

}




void TowerDefenceGameManager::Init_Game()
{
	Bullet::init_image(this->getRenderer());
	m_inputScanner->ClearInputActions();
	std::string file = map_choose;
	Map.BuildFromFile(file, renderer, EnemyArmy);

	player.base_health = Map.HQ_life;
	player.money = Map.budget;



	KeyboardEvent esc_key;
	esc_key.Keycode = sf::Keyboard::Escape;
	esc_key.Event = sf::Event::KeyPressed;

	PlayerHUD::Init_Game(0, 576, "Assets/hud/PNG/metalPanel.png", player.HUD, renderer);



	char const* File[3]
	{

		 "Assets/textures/PNG/Default Size/towerDefense_tile249.png",
		 "Assets/textures/PNG/Default Size/towerDefense_tile249.png",
		 "Assets/textures/PNG/Default Size/towerDefense_tile249.png"

	};

	char const* File2[3]
	{

		 "Assets/textures/PNG/Default Size/towerDefense_tile206.png",
		 "Assets/textures/PNG/Default Size/towerDefense_tile206.png",
		 "Assets/textures/PNG/Default Size/towerDefense_tile206.png"

	};

	char const* File3[3]
	{

		 "Assets/textures/PNG/Default Size/towerDefense_tile291.png",
		 "Assets/textures/PNG/Default Size/towerDefense_tile291.png",
		 "Assets/textures/PNG/Default Size/towerDefense_tile291.png"

	};

	std::function<void(int x, int y)> a = [this, File](int x, int y)
	{
		if (towerChoose != nullptr)
		{
			return;
		}
		Sprite* my_sprite = &this->renderer.CreateSprite(*this->getRenderer().GetTexture(File[0]), sf::Vector2i(100, 600), 1);

		sf::Vector2i pos(x, y);
		ITower* tow = Map.AddTower<NormalTower>(pos);
		tow->sprite = my_sprite;
		towerChoose = tow;
	};

	std::function<void(int x, int y)> b = [this, File2](int x, int y)
	{
		if (towerChoose != nullptr)
		{
			return;
		}
		Sprite* my_sprite = &this->renderer.CreateSprite(*this->getRenderer().GetTexture(File2[0]), sf::Vector2i(300, 600), 1);

		sf::Vector2i pos(x, y);
		ITower* tow = Map.AddTower<ExplosiveTower>(pos);
		tow->sprite = my_sprite;
		towerChoose = tow;

	};
	std::function<void(int x, int y)> c = [this, File3](int x, int y)
	{
		if (towerChoose != nullptr)
		{
			return;
		}
		Sprite* my_sprite = &this->renderer.CreateSprite(*this->getRenderer().GetTexture(File3[0]), sf::Vector2i(500, 600), 1);

		sf::Vector2i pos(x, y);
		ITower* tow = Map.AddTower<StunTower>(pos);
		tow->sprite = my_sprite;
		towerChoose = tow;
	};


	player.HUD.Init_Buttons(100, 600, File, player.HUD, renderer, a);




	player.HUD.Init_Buttons(300, 600, File2, player.HUD, renderer, b);



	player.HUD.Init_Buttons(500, 600, File3, player.HUD, renderer, c);


	InputScanner::MouseClickAction click_button = [this](sf::Mouse::Button button, int x, int y)
	{
		for (int i = 0; i < player.HUD.Windows.size(); i++)
		{
			for (int j = 0; j < player.HUD.Windows[i]->Buttons.size(); j++)
			{
				HUDButton* my_button = player.HUD.Windows[i]->Buttons[j];
				if (my_button->my_Sprite->getGlobalBounds().contains((float)x, (float)y))
				{
					my_button->my_function(x, y);

				}



			}
		}


	};


	std::function<void(int x, int y)> MouseMoveAction = [this](int x, int y)
	{
		if (towerChoose != nullptr)
		{
			towerChoose->sprite->setPosition(x - towerChoose->sprite->getGlobalBounds().width / 2, y - towerChoose->sprite->getGlobalBounds().height / 2);
		}


	};
	m_inputScanner->AddMouseMoveAction(MouseMoveAction);


	std::function<void(sf::Mouse::Button button, int x, int y)> MouseMoveRelease = [this](sf::Mouse::Button, int x, int y)
	{
		if (towerChoose != nullptr)
		{
			if (player.money < towerChoose->Price)
			{
				renderer.RemoveSprite(*towerChoose->sprite);
				Map.removeTower(towerChoose);
				towerChoose = nullptr;
				delete towerChoose;
				return;
			}

			for (int i = 0; i < player.HUD.Windows.size(); i++)
			{
				for (int j = 0; j < player.HUD.Windows[i]->Buttons.size(); j++)
				{

					if (player.HUD.Windows[i]->Buttons[j]->my_Sprite->getGlobalBounds().intersects(towerChoose->GetSprite()->getGlobalBounds()))
					{


						renderer.RemoveSprite(*towerChoose->sprite);
						Map.removeTower(towerChoose);
						towerChoose = nullptr;

						delete towerChoose;
						return;

					}
				}



			}

			for (int i = 0; i < player.HUD.Windows.size(); i++)
			{


				if (player.HUD.Windows[i]->sprite->getGlobalBounds().intersects(towerChoose->GetSprite()->getGlobalBounds()))
				{


					renderer.RemoveSprite(*towerChoose->sprite);
					Map.removeTower(towerChoose);
					towerChoose = nullptr;
					delete towerChoose;
					return;

				}




			}

			for (int i = 0; i < Map.getTowers().size(); i++)
			{


				if (Map.getTowers()[i]->sprite->getGlobalBounds().intersects(towerChoose->GetSprite()->getGlobalBounds()) && Map.getTowers()[i]->sprite != towerChoose->sprite)
				{


					renderer.RemoveSprite(*towerChoose->sprite);
					Map.removeTower(towerChoose);
					towerChoose = nullptr;
					delete towerChoose;
					return;
				}




			}



			for (int i = 0; i < Map.Cells.size(); i++)
			{
				for (int j = 0; j < Map.Cells[i].size(); j++)
				{
					if (Map.Cells[i][j].sprite->getGlobalBounds().intersects(towerChoose->GetSprite()->getGlobalBounds()) &&
						(Map.Cells[i][j].terrain == TerrainType::Road || Map.Cells[i][j].terrain == TerrainType::Water))
					{


						renderer.RemoveSprite(*towerChoose->sprite);
						Map.removeTower(towerChoose);
						towerChoose = nullptr;
						delete towerChoose;
						return;

					}
					if (Map.Cells[i][j].sprite->getGlobalBounds().intersects(towerChoose->GetSprite()->getGlobalBounds()) &&
						(Map.Cells[i][j].terrain == TerrainType::Grass))
					{
						player.money -= towerChoose->Price;
						towerChoose->sprite->setOrigin(towerChoose->sprite->getLocalBounds().width / 2, towerChoose->sprite->getLocalBounds().height / 2);
						towerChoose->sprite->move(towerChoose->sprite->getLocalBounds().width / 2, towerChoose->sprite->getLocalBounds().height / 2);
						towerChoose = nullptr;
						return;
					}
				}



			}

		}
		if (towerChoose == nullptr)
		{
			return;
		}

		player.money -= towerChoose->Price;
		towerChoose = nullptr;

	};




	MouseClickEvent click_release(sf::Mouse::Button::Left, sf::Event::EventType::MouseButtonReleased);
	m_inputScanner->AddMouseAction(click_release, MouseMoveRelease);

	MouseClickEvent click_event(sf::Mouse::Button::Left, sf::Event::EventType::MouseButtonPressed);
	m_inputScanner->AddMouseAction(click_event, click_button);






	InputScanner::KeyboardAction actionKey = [this]() {CurrentState = GameState::MAIN_MENU; };

	m_inputScanner->AddKeyboardAction(esc_key, actionKey);
}

void TowerDefenceGameManager::Init_Pause()
{
	KeyboardEvent esc_key;
	esc_key.Keycode = sf::Keyboard::Escape;
	esc_key.Event = sf::Event::KeyPressed;


}

void TowerDefenceGameManager::Init_GameOver()
{
	KeyboardEvent esc_key;
	esc_key.Keycode = sf::Keyboard::Escape;
	esc_key.Event = sf::Event::KeyPressed;



	KeyboardEvent r_key;
	r_key.Keycode = sf::Keyboard::R;
	r_key.Event = sf::Event::KeyPressed;
}

GameState& TowerDefenceGameManager::get_GameState()
{
	return this->CurrentState;
}

Renderer& TowerDefenceGameManager::getRenderer()
{
	return renderer;
}