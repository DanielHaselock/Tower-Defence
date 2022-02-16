#include "pch.h"
#include "EnemyConfig.h"

using namespace TD;

void EnemyConfig::init_image(Renderer& rend)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		rend.LoadTextureFile(IMAGE_PATH2[i]);
	}
}

char const* EnemyConfig::arrange_enemy()
{
	if (EnemyType::HEALER == this->Enemy_Type)
		return IMAGE_PATH2[0];
	if (EnemyType::TANK == this->Enemy_Type)
		return IMAGE_PATH2[2];
	if (EnemyType::SCOUT == this->Enemy_Type)
		return IMAGE_PATH2[1];

	return "NULL";
}

EnemyConfig::EnemyConfig(unsigned int en_type)
{
	EnemyType tmp = static_cast<EnemyType>(en_type);
	this->Enemy_Type = tmp;

	if (Enemy_Type == EnemyType::TANK)
	{
		Speed = 0.5;
		Damage = 5;
		Gold = 100;
		life = 100;
		Max_Life = 100;
	}

	if (Enemy_Type == EnemyType::SCOUT)
	{
		Speed = 1;
		Damage = 2;
		Gold = 25;
		life = 40;
		Max_Life = 50;
	}

	if (Enemy_Type == EnemyType::HEALER)
	{
		Speed = 0.7f;
		Damage = 3;
		Gold = 50;
		life = 60;
		Max_Life = 60;
	}
}