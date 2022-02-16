#include "pch.h"
#include "EnemyArmy.h"
#include "EnemyConfig.h"
#include <iostream>
#include "GameMap.h"

using namespace TD;

void EnemyArmy::RemoveEnemy(Enemy& enemy)
{
	std::vector<Enemy*>::iterator it = std::find(Enemies.begin(), Enemies.end(), &enemy);
	Enemies.erase(it);
}

void EnemyArmy::ClearAllEnemies()
{
	for (int x = 0; x < Enemies.size(); x++)
	{
		delete Enemies[x];
	}
	Enemies.clear();
}

std::vector<Enemy*>& EnemyArmy::GetArmy()
{
	return Enemies;
}

void TD::EnemyArmy::UpAllEnemies(float Dt)
{
	GameMap* my_map = new GameMap;
	time += sf::seconds(Dt);
	for (int i = 0; i < Enemies.size(); i++)
	{
		if (Enemies[i]->is_spawned == false)
		{
			if (time >= my_map->Total_Time + sf::seconds((float)Enemies[i]->Spawntime))
			{
		
				Enemies[i]->is_spawned = true;
			}

		}
		

		
		

	}
	for (int i = 0; i < Enemies.size(); i++)
	{
		Enemies[i]->Update(Dt);
		
	}




}
