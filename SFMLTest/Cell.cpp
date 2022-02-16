#include "pch.h"
#include "Cell.h"
#include <iostream>

using namespace TD;


char const* IMAGE_PATH[10]
{
	//HQ tile textures
	/*0*/"Assets/HQ.png",

	//Spawn tile textures
	/*1*/"Assets/textures/PNG/Default size/towerDefense_tile022.png",

	//Road tile textures
	/*2*/"Assets/textures/PNG/Default size/towerDefense_tile050.png",
	/*3*/"Assets/textures/PNG/Default size/towerDefense_tile093.png",
	/*4*/"Assets/textures/PNG/Default size/towerDefense_tile158.png",

	//Grass tile textures
	/*5*/"Assets/textures/PNG/Default size/towerDefense_tile024.png",
	/*6*/"Assets/textures/PNG/Default size/towerDefense_tile119.png",

	//Sand tile textures
	/*7*/"Assets/textures/PNG/Default size/towerDefense_tile029.png",
	/*8*/"Assets/textures/PNG/Default size/towerDefense_tile188.png",

	//Water tile textures
	/*9*/"Assets/textures/PNG/Default size/towerDefense_tile267.png",
};

TD::Cell::Cell(std::size_t type)
{

	TerrainType terrainType = static_cast<TerrainType>(type);
	this->terrain = terrainType;
	this->background_sprite = nullptr;
	this->sprite = nullptr;
}

void TD::Cell::init_image(Renderer& my_renderer)
{

	for (int i = 0; i < 10; i++)
	{

		my_renderer.LoadTextureFile(IMAGE_PATH[i]);
	}


}
char const* Cell::arrange_cells()
{
	if (TerrainType::HQ == this->terrain)
	{
		return IMAGE_PATH[0];
	}
	if (TerrainType::Spawn == this->terrain)
	{
		return IMAGE_PATH[1];
	}
	if (TerrainType::Road == this->terrain)
	{
		unsigned int x = rand() % 3;
		if (x == 0)
			return IMAGE_PATH[2];
		else if (x == 1)
			return IMAGE_PATH[3];
		else if (x == 2)
			return IMAGE_PATH[4];
		return IMAGE_PATH[2];
	}
	if (TerrainType::Grass == this->terrain)
	{
		unsigned int x = rand() % 2;
		if (x == 0)
			return IMAGE_PATH[5];
		else if (x == 1)
			return IMAGE_PATH[6];
		return IMAGE_PATH[5];
	}
	if (TerrainType::Sand == this->terrain)
	{
		unsigned int x = rand() % 2;
		if (x == 0)
			return IMAGE_PATH[7];
		else if (x == 1)
			return IMAGE_PATH[8];
		return IMAGE_PATH[7];
	}
	if (TerrainType::Water == this->terrain)
	{
		return IMAGE_PATH[9];
	}
	return IMAGE_PATH[0];
}

