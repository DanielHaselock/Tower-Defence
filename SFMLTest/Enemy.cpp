#include "pch.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

using namespace TD;

float TD::Enemy::lerp(float a, float b, float f)
{
	return a + f * (b - a);
}

void TD::Enemy::getPosition(int index, float* x, float* y)
{
	*x = float(index % 20);
	*y = float(index / 20);

	*x *= 64;
	*y *= 64;
}

Enemy::Enemy(EnemyType en_t, EnemyConfig en_c, EnemyArmy& en_a, unsigned int St)
{
	this->Config = en_c;
	this->Army = &en_a;
	Spawntime = St;
	is_spawned = false;
}



EnemyConfig& TD::Enemy::GetConfig()
{
	return Config;
}