#pragma once
#include "Enemy.h"
namespace TD
{


	class ScoutEnemy : public TD::Enemy
	{
	public:

		int index;
		float alpha;
		float speed_;

		void Update(float Dt) override;
		ScoutEnemy(TD::EnemyType en_t, TD::EnemyConfig en_c, TD::EnemyArmy& en_a, unsigned int St);

		unsigned int Spawntime;

		float xorigin;
		float yorigin;
	};
}