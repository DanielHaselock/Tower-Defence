#include "pch.h"
#include "NormalTower.h"
#include <iostream>
using namespace TD;
void NormalTower::ShootAt(int index, Renderer& my_renderer, float b, float Deltatime)
{

        Bullet* my_bullet = new Bullet(Config.Bullet);
        my_bullet->enemy = index;
        sf::Vector2i my_vector(int(this->GetSprite()->getPosition().x - this->GetSprite()->getGlobalBounds().width / 2), int(this->GetSprite()->getPosition().y - this->GetSprite()->getGlobalBounds().height / 2));
        Sprite& sprite = my_renderer.CreateSprite(*my_renderer.GetTexture(IMAGE_PATH[0]), my_vector, 1);

        my_bullet->Sprite = &sprite;

        my_bullet->Direction = sf::Vector2f(cos(b), sin(b));
        my_bullet->Sprite->setOrigin(my_bullet->Sprite->getGlobalBounds().width / 2, my_bullet->Sprite->getGlobalBounds().height / 2);
        my_bullet->Sprite->move(my_bullet->Sprite->getGlobalBounds().width / 2, my_bullet->Sprite->getGlobalBounds().height / 2);
        my_bullet->Sprite->setRotation(b - 90);

        bullets.push_back(my_bullet);
    
}

void NormalTower::Update(TD::EnemyArmy& EnemyArmy, Renderer& my_renderer, float Deltatime, Player& player)
{
    T += sf::seconds(Deltatime);

        
        this->sprite->setRotation(this->sprite->getRotation() + 2);

        int index = CheckRange(EnemyArmy);
        if (index == -1)
        {
            return;
        }
        if (EnemyArmy.GetArmy()[index]->is_dead != true)
        {


            if (EnemyArmy.GetArmy()[index] != nullptr)
            {
                int e_x = (int)EnemyArmy.GetArmy()[index]->sprite->getPosition().x + (int)EnemyArmy.GetArmy()[index]->sprite->getLocalBounds().width / 2;
                int e_y = (int)EnemyArmy.GetArmy()[index]->sprite->getPosition().y + (int)EnemyArmy.GetArmy()[index]->sprite->getLocalBounds().height / 2;
                float a = atan2((e_y - this->sprite->getPosition().y), (e_x - this->sprite->getPosition().x));

                this->sprite->setRotation(float(((double)a * 180 / 3.1415) - 270));
                double b = ((double)a * 180 / 3.1415);
                if (T > sf::seconds(2))
                {
                    ShootAt(index, my_renderer, a, Deltatime);
                    T = sf::seconds(0);
                }





                for (int i = 0; i < bullets.size(); i++)
                {
                    bullets[i]->Update(my_renderer, this, EnemyArmy, player);

                }
                if (EnemyArmy.GetArmy()[index]->GetConfig().life < 0)
                {
                    return;
                }
            }
        }
}

NormalTower::NormalTower(sf::Vector2i cellPosition)
{
	this->Config = ConfigTower(0);
	this->Price = 75;
	this->Level = 1;

}