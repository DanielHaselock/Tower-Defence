#pragma once
#include "ITower.h"
namespace TD
{


	class ExplosiveTower : public ITower
	{
	public:
		void ShootAt(int index, Renderer& my_renderer, float b, float Deltatime) override;
		//void LevelUp() override;
		void Update(TD::EnemyArmy& EnemyArmy, Renderer& my_renderer, float Deltatime, Player& player) override;
		ExplosiveTower(sf::Vector2i cellPosition);

	};
}