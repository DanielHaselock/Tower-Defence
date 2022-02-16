#pragma once
#include <vector>
#include "Renderer.h"

namespace TD
{
	enum class EnemyType
	{
		SCOUT = 0,
		TANK = 1,
		HEALER = 8
	};

	class EnemyConfig
	{
	public:
		EnemyType Enemy_Type;
		float Speed = 0;
		unsigned int Damage = 0;
		unsigned int Gold = 0;
		int life = 0;
		unsigned int Max_Life = 0;

		char const* arrange_enemy();
		EnemyConfig(unsigned int en_type);
		EnemyConfig() {};
		static void init_image(Renderer& rend);
	};

	static char const* IMAGE_PATH2[3]
	{
		//Healer
		/*0*/"Assets/textures/PNG/Default size/towerDefense_tile247.png",

		//scout
		/*1*/"Assets/textures/PNG/Default size/towerDefense_tile245.png",

		//tank
		/*2*/"Assets/textures/PNG/Default size/towerDefense_tile246.png",
	};
}