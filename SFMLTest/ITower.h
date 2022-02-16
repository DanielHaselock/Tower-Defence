#pragma once
#include <cstdint>
#include "ConfigTower.h"
#include "GameEntity.h"
#include "Bullet.h"
#include "EnemyArmy.h"
namespace TD
{

	class Player;
	class ITower : public TD::GameEntity
	{
	public:
		sf::Time T;
		unsigned int Price;
		std::uint8_t Level;
		unsigned int UpgradeCost;
		ConfigTower Config;
		std::vector<Bullet*> bullets;

	protected:
		int CheckRange(TD::EnemyArmy& EnemyArmy);

	public:
		virtual void ShootAt(int index, Renderer& my_renderer, float b, float Deltatime) = 0;
		//virtual void LevelUp() = 0;
		virtual void Update(TD::EnemyArmy& EnemyArmy, Renderer& my_renderer, float Deltatime, Player& player) = 0;
		ITower() {
			this->Level = 0;
			this->Price = 0;
			this->UpgradeCost = 0;
		};

	};
}