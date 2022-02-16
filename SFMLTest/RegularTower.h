#pragma once
#include "ITower.h"
class RegularTower : public ITower
{
public:
	//void ShootAt(Enemy const& my_Enemy) override;



	void LevelUp() override;
	void Update() override;
};