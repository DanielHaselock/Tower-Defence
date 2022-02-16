#pragma once
#include "Enemy.h"
#include <SFML/System/Time.hpp>

namespace TD
{
	class HealerEnemy : public Enemy
	{
	private:
		float HealRange;
		unsigned int HealAmount;
		sf::Time HealCooldown;
	public:
		int index;
		float alpha;
		float speed_;

		float xorigin;
		float yorigin;

		void HealAround();
		HealerEnemy(EnemyType en_t, EnemyConfig en_c, EnemyArmy& en_a, unsigned int St);
		void Update(float Dt) override;

		unsigned int Spawntime;
	};
}