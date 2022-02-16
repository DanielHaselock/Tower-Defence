#pragma once
#include "Enemy.h"
namespace TD
{


	class TankEnemy : public TD::Enemy
	{
	public:

		int index;
		float alpha;
		float speed_;

		void Update(float Dt) override;

		TankEnemy(TD::EnemyType en_t, TD::EnemyConfig en_c, TD::EnemyArmy& en_a, unsigned int St);

		unsigned int Spawntime;

		float xorigin;
		float yorigin;
	};
}