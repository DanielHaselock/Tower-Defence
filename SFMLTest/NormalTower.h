#pragma once
#include "ITower.h"
namespace TD
{


	class NormalTower : public ITower
	{
	public:

		void ShootAt(int index, Renderer& my_renderer, float b, float Deltatime) override;
		//virtual void LevelUp() override;
		void Update(TD::EnemyArmy& EnemyArmy, Renderer& my_renderer, float Deltatime, Player& player) override;
		NormalTower(sf::Vector2i cellPosition);

	};
}