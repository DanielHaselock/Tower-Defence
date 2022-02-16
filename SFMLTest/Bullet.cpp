#include "pch.h"
#include "Bullet.h"
#include "ITower.h"
#include "EnemyConfig.h"
#include "EnemyArmy.h"
#include "Enemy.h"
#include <iostream>
#include "Player.h"




void TD::Bullet::Update(Renderer& my_renderer, ITower* tow, TD::EnemyArmy& EnemyArmy, Player& player)
{


	int e_x = int(EnemyArmy.GetArmy()[enemy]->sprite->getPosition().x + EnemyArmy.GetArmy()[enemy]->sprite->getLocalBounds().width / 2);
	int e_y = int(EnemyArmy.GetArmy()[enemy]->sprite->getPosition().y + EnemyArmy.GetArmy()[enemy]->sprite->getLocalBounds().height / 2);
	float a = atan2((e_y - this->Sprite->getPosition().y), (e_x - this->Sprite->getPosition().x));

	this->Sprite->setRotation(float(((double)a * 180 / 3.1415) - (double)270));

	this->Direction = sf::Vector2f(cos(a), sin(a));
	this->Sprite->move(Direction.x * this->Speed, Direction.y * this->Speed);

	if (EnemyArmy.GetArmy()[enemy]->sprite != nullptr)
	{


		if ((this->Sprite->getGlobalBounds().contains(EnemyArmy.GetArmy()[enemy]->sprite->getPosition().x, EnemyArmy.GetArmy()[enemy]->sprite->getPosition().y))
			|| (EnemyArmy.GetArmy()[enemy]->GetConfig().life < 1))
		{
			EnemyArmy.GetArmy()[enemy]->GetConfig().life -= tow->Config.Damage;
			
			my_renderer.RemoveSprite(*this->Sprite);
			std::vector<Bullet*>::iterator it = std::find(tow->bullets.begin(), tow->bullets.end(), this);
			if (EnemyArmy.GetArmy()[enemy]->GetConfig().life <= 0)
			{
				player.money += EnemyArmy.GetArmy()[enemy]->GetConfig().Gold;
				
				my_renderer.RemoveSprite(*EnemyArmy.GetArmy()[enemy]->sprite);
				EnemyArmy.GetArmy()[enemy]->is_dead = true;
			}
			tow->bullets.erase(it);

			delete this;
		}
		if (this->Type == BulletType::EXPLOSIVE)
		{
			for (int i = 0; i < EnemyArmy.GetArmy().size(); i++)
			{

				
				if (EnemyArmy.GetArmy()[i]->is_dead == false)
				{
					if (EnemyArmy.GetArmy()[i] != EnemyArmy.GetArmy()[enemy])
					{
						int e_x = int(EnemyArmy.GetArmy()[i]->sprite->getPosition().x);
						int e_y = int(EnemyArmy.GetArmy()[i]->sprite->getPosition().y);

						float my_distance = sqrt((e_x - EnemyArmy.GetArmy()[enemy]->sprite->getPosition().x) * (e_x - EnemyArmy.GetArmy()[enemy]->sprite->getPosition().x) + (e_y - EnemyArmy.GetArmy()[enemy]->sprite->getPosition().y) * (e_y - EnemyArmy.GetArmy()[enemy]->sprite->getPosition().y));
						if (my_distance < 75)
						{
							EnemyArmy.GetArmy()[i]->GetConfig().life -= (tow->Config.Damage / 2);
							
							if (EnemyArmy.GetArmy()[i]->GetConfig().life <= 0)
							{
								player.money += EnemyArmy.GetArmy()[i]->GetConfig().Gold;
							
								my_renderer.RemoveSprite(*EnemyArmy.GetArmy()[i]->sprite);
								EnemyArmy.GetArmy()[i] = nullptr;


							}
						}
					}
				}
				
			}
		}

	}



}

void TD::Bullet::init_image(Renderer& rend)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		rend.LoadTextureFile(IMAGE_PATH[i]);
	}
}

char const* TD::Bullet::arrange_Bullets()
{
	if (BulletType::NORMAL == this->Type)
		return IMAGE_PATH[0];
	if (BulletType::EXPLOSIVE == this->Type)
		return IMAGE_PATH[1];
	if (BulletType::STUN == this->Type)
		return IMAGE_PATH[2];

	return "NULL";
}

TD::Bullet::Bullet(BulletType en_type)
{
	BulletType tmp = en_type;
	this->Type = tmp;

	if (Type == BulletType::NORMAL)
	{
		Speed = 10;
	}

	if (Type == BulletType::EXPLOSIVE)
	{
		Speed = 10;
	}

	if (Type == BulletType::STUN)
	{
		Speed = 10;
	}
}
