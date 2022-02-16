#include "pch.h"
#include "window.h"
using namespace TD;
void Window::Init()
{
	m_window.create(sf::VideoMode(1280, 676), "Tower Defense");
	quit_window = std::bind(&Window::Quit, this);
	this->m_window.setVerticalSyncEnabled(true);
}

void Window::Quit()
{
	m_window.close();
}

sf::RenderWindow& Window::get_window()
{
	return this->m_window;
}

void Window::Render(const sf::Drawable& drawable)
{
	m_window.draw(drawable);
}


