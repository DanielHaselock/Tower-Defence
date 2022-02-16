#include "pch.h"
#include "TankEnemy.h"
#include "GameMap.h"
#include "Player.h"
#include "TowerDefenceGameManager.h"

using namespace TD;
void TankEnemy::Update(float Dt)
{
	if (TowerDefenceGameManager::GetInstance().enmoves_.size() == 0) {
		alpha = 1.0f;
		index = 0;
		xorigin = 0.0f;
		yorigin = 0.0f;


	}

	if (alpha < 1) {
		float x = 0.0f;
		float y = 0.0f;

		if (TowerDefenceGameManager::GetInstance().enmoves_.size() > 0)
			getPosition(TowerDefenceGameManager::GetInstance().enmoves_[index], &x, &y);

		sprite->setPosition(lerp(xorigin, x, alpha), lerp(yorigin, y, alpha));
		alpha += Dt * speed_;

	}
	else {
		xorigin = sprite->getPosition().x;
		yorigin = sprite->getPosition().y;
		alpha = 0.0f;
		if (index < TowerDefenceGameManager::GetInstance().enmoves_.size() - 1 && this->is_dead == false)
		{
			index++;
		}
		else if(this->is_dead == false)
		{
			TowerDefenceGameManager::GetInstance().player.lives -= 1;

		}
			
	}
	
}


TankEnemy::TankEnemy(TD::EnemyType en_t, TD::EnemyConfig en_c, TD::EnemyArmy& en_a, unsigned int St)
{

	index = 0;
	alpha = 1.0f;
	xorigin = 0.0f;
	yorigin = 0.0f;
	this->Config = en_c;
	this->Army = &en_a;
	Spawntime = St;
	speed_ = this->Config.Speed;

}

