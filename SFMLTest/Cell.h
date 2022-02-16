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
#include "Renderer.h"
namespace TD
{
	enum class TerrainType
	{
		HQ = 0,
		Spawn = 1,
		Road = 2,
		Grass = 8,
		Sand = 16,
		Water = 99
	};


	class Cell
	{
	public:
		Cell(std::size_t type);
		
		TerrainType terrain;
		Sprite* sprite;
		Sprite* background_sprite;
		static void init_image(Renderer& my_renderer);
		char const* arrange_cells();
	};



}
