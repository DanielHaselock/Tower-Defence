#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include <SFML/Window/Mouse.hpp>
#include <map>
#include <SFML/Window/Keyboard.hpp>
#include "Cell.h"
#include "EnemyArmy.h"
#include "Renderer.h"
#include "HealerEnemy.h"
#include "TankEnemy.h"
#include "ScoutEnemy.h"
#include "ITower.h"


namespace TD
{
	class GameMap
	{
	private:
		unsigned int CellSize = 0;

		std::vector<ITower*> Towers;

	public:
		std::vector<std::vector<Cell>> Cells;
		unsigned int T_minus_start;
		
		bool BuildFromFile(std::string const&  filename, Renderer& my_renderer, EnemyArmy& army);
		template  <typename T> T* AddTower(sf::Vector2i cellPosition)
		{
			T* t = new T(cellPosition);
			this->Towers.push_back(t);
			return t;
		};

		void Clear();
		std::vector<ITower*>& getTowers();
		void removeTower(ITower* my_tower);

		TD::Cell* my_hq_position;
		void createEnemies(EnemyArmy& army, Renderer& my_renderer, sf::Vector2i spawnpoint);

		unsigned int budget;
		unsigned int warmup;
		unsigned int HQ_life;
		sf::Time Total_Time;
		

	};


}