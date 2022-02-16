#pragma once
#include "Enemy.h"
#include <vector>


namespace TD
{
	class EnemyArmy
	{
	private:
		std::vector<Enemy*> Enemies;
	public:
		template <typename T> T* SpawnEnemy(EnemyType en_t, EnemyConfig en_c, EnemyArmy& en_a, unsigned int St)
		{
			T* t = new T(en_t, en_c, en_a, St);
			this->Enemies.push_back(t);
			return t;
		};
		
		void RemoveEnemy(Enemy& enemy);
		void ClearAllEnemies();
		std::vector<Enemy*>& GetArmy();
		void UpAllEnemies(float Dt);

		sf::Time time;

	};
}