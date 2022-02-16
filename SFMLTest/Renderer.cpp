#include "pch.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace TD;

const sf::Texture* Renderer::LoadTextureFile(const std::string& name)
{
	
	
	sf::Texture* str_texture = new sf::Texture;
	if (!str_texture->loadFromFile(name))
	{
	
	}

	this->textures.insert(std::pair<std::string, sf::Texture*>(name, str_texture));
	return str_texture;

}
const sf::Texture* Renderer::GetTexture(const std::string& name)
{
	return this->textures[name];
}
void Renderer::DrawSprites()
{
	
	for (unsigned int i = 0; i < this->sprites.size(); i++)
		for (std::list<Sprite*>::iterator it = this->sprites[i].begin(); it != this->sprites[i].end(); ++it)
			this->window->Render(**it);


}
Sprite& Renderer::CreateSprite(const sf::Texture& my_Texture, sf::Vector2i position, Layer zLayer)
{
	Sprite* sprite = new Sprite(zLayer);
	sprite->setTexture(my_Texture);
	sprite->setPosition(float(position.x), float(position.y));

	if (this->sprites.size() <= zLayer) {
		std::list<Sprite*> list;
		this->sprites.push_back(list);
	}

	this->sprites[zLayer].push_back(sprite);

	return *sprite;
}

void Renderer::setWindow(Window* my_window)
{
	this->window = my_window;

}

Window* Renderer::get_window()
{
	return window;
}

void Renderer::RemoveSprite(Sprite& my_Sprite)
{
	for (int x = 0; x < sprites.size(); x++)
	{
		sprites[x].remove(&my_Sprite);
	}
}

void Renderer::RemoveAll()
{
	for (int x = 0; x < sprites.size(); x++)
	{
		for (std::list<Sprite*>::iterator it = sprites[x].begin(); it != sprites[x].end(); it++)
		{
			delete *it;
		}
	}

	this->sprites.clear();
}