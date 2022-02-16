#pragma once
#include "Sprite.h"
#include <SFML/System/Vector2.hpp>
#include "Renderer.h"
#include "ConfigTower.h"
#include "EnemyArmy.h"
#include "Enemy.h"


namespace TD
{
	class ITower;
	class Player;
	class Bullet
	{
	public:
		float Speed{};
		sf::Vector2f Direction{};
		int enemy{};
		BulletType Type{};
		Sprite* Sprite{};

		void Update(Renderer& my_renderer, ITower* tow, TD::EnemyArmy& EnemyArmy, Player& player);
		static void init_image(Renderer& rend);
		char const* arrange_Bullets();
		Bullet(BulletType en_type);
	};

	static char const* IMAGE_PATH[3]
	{
		//Normal
		/*0*/"Assets/textures/PNG/Default size/towerDefense_tile297.png",

		//Explosive
		/*1*/"Assets/textures/PNG/Default size/towerDefense_tile296.png",

		//Stun
		/*2*/"Assets/textures/PNG/Default size/towerDefense_tile298.png",
	};

}