#include "pch.h"
#include "GameMap.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace TD;


bool TD::GameMap::BuildFromFile(std::string const& filename, Renderer& my_renderer, EnemyArmy& army)
{
    std::ifstream ifi(filename);
    std::string line;

    if (!ifi.is_open())
    {
       
    }

    sf::Vector2i spawnpoint;

    while (std::getline(ifi, line))
    {
        std::string name;

        size_t comment = line.find('#');
        if (comment != std::string::npos)
        {
            line.erase(comment);
        }
        size_t multiSpace = line.find("   ");
        if (multiSpace != std::string::npos)
        {
            line.erase(multiSpace);
        }
        size_t commentSpace = line.find(" #");
        if (commentSpace != std::string::npos)
        {
            line.erase(commentSpace);
        }
        if (line.empty())
            continue;

        std::istringstream is(line);

        is >> name;

        if (name == "wave")
        {
            
            is >> T_minus_start;

            unsigned int nb_en;
            is >> nb_en;

            for (unsigned int i = 0; i < nb_en; i++)
            {
                std::getline(ifi, line);
                std::istringstream is(line);
                std::string en;
                is >> en;
                if (en == "enemy")
                {
                    unsigned int en_type;
                    is >> en_type;

                    unsigned int spawn_time;
                    is >> spawn_time;

                    EnemyConfig config = EnemyConfig(en_type);
                    if (config.Enemy_Type == TD::EnemyType::HEALER)
                        army.SpawnEnemy<TD::HealerEnemy>(config.Enemy_Type, config, army, spawn_time);


                    if (config.Enemy_Type == TD::EnemyType::TANK)
                        army.SpawnEnemy<TankEnemy>(config.Enemy_Type, config, army, spawn_time);

                    if (config.Enemy_Type == TD::EnemyType::SCOUT)
                        army.SpawnEnemy<ScoutEnemy>(config.Enemy_Type, config, army, spawn_time);
                }
            }
        }

        if (name == "budget")
        {
            is >> budget;



        }
        if (name == "warmup")
        {
            is >> warmup;



        }



        if (name == "hq_init_life")
        {
            is >> HQ_life;



        }

        if (name == "map")
        {
            int column;
            is >> column;

            int row;
            is >> row;
            for (int x = 0; x < row; x++)
            {
                std::getline(ifi, line);
                std::istringstream is(line);
                std::vector<Cell> cells;
                for (int y = 0; y < column; y++)
                {
                    std::size_t type;
                    is >> type;

                    cells.emplace_back(type);
                    Cell& cell = cells.back();



                    sf::Vector2i my_vector(y * 64, x * 64);

                    if (type == 0 || type == 1)
                    {
                        if (type == 1)
                        {
                            spawnpoint.x = my_vector.x;
                            spawnpoint.y = my_vector.y;
                        }

                        Sprite& my_background_sprite = my_renderer.CreateSprite(*my_renderer.GetTexture("Assets/textures/PNG/Default size/towerDefense_tile093.png"), my_vector, 0);
                        Sprite& my_sprite = my_renderer.CreateSprite(*my_renderer.GetTexture(cell.arrange_cells()), my_vector, 1);
                        cell.sprite = &my_sprite;
                        cell.background_sprite = &my_background_sprite;
                        my_hq_position = &cell;
                    }
                    else
                    {
                        Sprite& my_sprite = my_renderer.CreateSprite(*my_renderer.GetTexture(cell.arrange_cells()), my_vector, 0);
                        cell.sprite = &my_sprite;
                        cell.background_sprite = nullptr;
                    }
                }
                Cells.push_back(cells);
            }
            break;
        }
    }

    Total_Time = sf::seconds(float(warmup)) + sf::seconds(float(T_minus_start));

    for (unsigned int i = 0; i < army.GetArmy().size(); i++)
    {
        switch (army.GetArmy()[i]->GetConfig().Enemy_Type)
        {
        case TD::EnemyType::HEALER: army.GetArmy()[i]->sprite = &my_renderer.CreateSprite(*my_renderer.GetTexture(IMAGE_PATH2[0]), spawnpoint, 1);
            break;
        case TD::EnemyType::SCOUT: army.GetArmy()[i]->sprite = &my_renderer.CreateSprite(*my_renderer.GetTexture(IMAGE_PATH2[1]), spawnpoint, 1);
            break;
        case TD::EnemyType::TANK: army.GetArmy()[i]->sprite = &my_renderer.CreateSprite(*my_renderer.GetTexture(IMAGE_PATH2[2]), spawnpoint, 1);
            break;
        }
    }

    return 0;
}

void GameMap::Clear()
{

    Towers.clear();
    Cells.clear();
}

std::vector<ITower*>& GameMap::getTowers()
{
    return Towers;
}

void TD::GameMap::removeTower(ITower* my_tower)
{
    for (std::vector<ITower*>::iterator it = Towers.begin(); it != Towers.end(); it++)
    {
        if (*it == my_tower)
        {
            Towers.erase(it);
            return;
        }
    }


}
