#pragma once
#include "GameEntity.h"
#include "EnemyConfig.h"

namespace TD
{
	class EnemyArmy;
	class Enemy : public GameEntity
	{
	protected:
		EnemyConfig Config;
		EnemyArmy* Army;
	public:

		float lerp(float a, float b, float f);

		void getPosition(int index, float* x, float* y);

		std::vector <unsigned int> moves;

		Enemy(EnemyType en_t, EnemyConfig en_c, EnemyArmy& en_a, unsigned int St);
		Enemy() {
			this->Army = nullptr;
			this->Spawntime = 1;
			this->is_spawned = false;
		};
		EnemyConfig& GetConfig();
		void virtual Update(float Dt) = 0;


		unsigned int Spawntime;

		bool is_spawned;
		bool is_dead = false;


	};

}