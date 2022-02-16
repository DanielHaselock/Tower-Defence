#include "pch.h"
#include "ITower.h"
//using namespace TD;

int TD::ITower::CheckRange(TD::EnemyArmy& EnemyArmy)
{
    TD::Enemy* my_enemy = nullptr;
    float distance = float(INT_MAX);
    int index = -1;
    sf::Vector2f tow_posittion = this->sprite->getPosition();
    int i = 0;
    for (i; i < EnemyArmy.GetArmy().size(); i++)
    {
        if (EnemyArmy.GetArmy()[i]->sprite != nullptr)

        {
            int e_x = int(EnemyArmy.GetArmy()[i]->sprite->getPosition().x + EnemyArmy.GetArmy()[i]->sprite->getLocalBounds().width / 2);
            int e_y = int(EnemyArmy.GetArmy()[i]->sprite->getPosition().y + EnemyArmy.GetArmy()[i]->sprite->getLocalBounds().height / 2);
            std::string a = std::to_string(sqrt((e_x - tow_posittion.x) * (e_x - tow_posittion.x) + (e_y - tow_posittion.y) * (e_y - tow_posittion.y)));


            float my_distance = sqrt((e_x - tow_posittion.x) * (e_x - tow_posittion.x) + (e_y - tow_posittion.y) * (e_y - tow_posittion.y));
            if (my_distance < this->Config.Range)
            {
                if (abs(my_distance) < abs(distance))
                {


                    distance = my_distance;
                    my_enemy = EnemyArmy.GetArmy()[i];
                    index = i;

                }
            }
        }
       
    }
    return index;


   
}










