#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Touch.hpp>
#include <SFML/Window/Touch.hpp>
#include <functional>
namespace TD
{


	class Window
	{
	private:
		sf::RenderWindow m_window;

	public:
		void Init();
		void Quit();
		void Render(const sf::Drawable& drawable);
		sf::RenderWindow& get_window();
		std::function<void()> quit_window;
	};
}