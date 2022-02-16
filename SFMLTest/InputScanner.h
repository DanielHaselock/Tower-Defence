#pragma once
#include <map>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include <SFML/Window/Mouse.hpp>
#include "KeyboardEvent.h"
#include "MouseClickEvent.h"
namespace TD
{


	class InputScanner
	{
	public:
		typedef std::function<void()> KeyboardAction;
		typedef std::function<void(sf::Mouse::Button button, int x, int y)> MouseClickAction;
		typedef std::function<void(int x, int y)> MouseMoveAction;
		bool Init(sf::RenderWindow* my_RenderWindow);
		bool Update();
		void AddKeyboardAction(KeyboardEvent my_KeyboardEvent, KeyboardAction my_KeyboardAction);
		void AddMouseAction(MouseClickEvent my_KeyboardEvent, MouseClickAction my_MouseClickAction);
		void AddMouseMoveAction(MouseMoveAction my_MouseMoveAction);
		void ClearInputActions();
		bool IsKeyboardEvent(sf::Event my_Event);
		bool IsMouseEvent(sf::Event my_Event);
		bool IsQuitEvent(sf::Event my_Event);
		bool IsMouseMoveEvent(sf::Event my_Event);

	private:
		sf::RenderWindow* m_inputSource;
		std::map<KeyboardEvent, KeyboardAction> m_keyboardActions;
		std::map<MouseClickEvent, MouseClickAction> m_clickActions;
		std::vector<MouseMoveAction> m_moveActions;

	};
}