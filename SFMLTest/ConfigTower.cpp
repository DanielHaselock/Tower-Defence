#include "pch.h"
#include "ConfigTower.h"
using namespace TD;
ConfigTower::ConfigTower(unsigned int en_type)
{
	BulletType tmp = static_cast<BulletType>(en_type);
	this->Bullet = tmp;
	this->Damage = 0;
	this->FiringRate = 0;
	this->MaxLevel = 0;
	this->Range = 0;

	if (Bullet == BulletType::NORMAL)
	{
		FiringRate = 3;
		Damage = 20;
		Range = 200;
		MaxLevel = 2;
	}

	if (Bullet == BulletType::EXPLOSIVE)
	{
		FiringRate = 1;
		Damage = 40;
		Range = 150;
		MaxLevel = 2;
	}

	if (Bullet == BulletType::STUN)
	{
		FiringRate = 2;
		Damage = 10;
		Range = 150;
		MaxLevel = 2;
	}
}