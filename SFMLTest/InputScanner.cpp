#include "pch.h"
#include "InputScanner.h"
#include <iostream>

using namespace TD;
bool InputScanner::Init(sf::RenderWindow* my_RenderWindow)
{
	if (my_RenderWindow == nullptr)
	{
		return false;
	}
	this->m_inputSource = my_RenderWindow;
	return true;
}

bool InputScanner::Update()
{
	sf::Event event;
	while (m_inputSource->pollEvent(event))
	{
		if (IsKeyboardEvent(event))
		{
			KeyboardEvent tmp;
			tmp.Keycode = event.key.code;
			tmp.Event = event.type;

			std::map<KeyboardEvent, KeyboardAction>::iterator it = m_keyboardActions.find(tmp);
			if (it != m_keyboardActions.end())
			{
				it->second();
			}
		}
		if (IsQuitEvent(event))
		{
			m_inputSource->close();
		}
		if (IsMouseEvent(event))
		{
			MouseClickEvent tmp(event.mouseButton.button, event.type);
			

			std::map<MouseClickEvent, MouseClickAction>::iterator it = m_clickActions.find(tmp);
			if (it != m_clickActions.end())
			{
				it->second(tmp.Button, event.mouseButton.x, event.mouseButton.y);
			}


		}
		if (IsMouseMoveEvent(event))
		{
			if (this->m_moveActions.size() > 0)
			{
				this->m_moveActions[0](event.mouseMove.x, event.mouseMove.y);
			}


		}



	}
	return false;
}

void InputScanner::AddKeyboardAction(KeyboardEvent my_KeyboardEvent, KeyboardAction my_KeyboardAction)
{
	m_keyboardActions.insert({ my_KeyboardEvent, my_KeyboardAction });
}

void InputScanner::AddMouseAction(MouseClickEvent my_KeyboardEvent, MouseClickAction my_MouseClickAction)
{
	m_clickActions.insert({ my_KeyboardEvent, my_MouseClickAction });
}


void InputScanner::AddMouseMoveAction(MouseMoveAction my_MouseMoveAction)
{
	m_moveActions.push_back(my_MouseMoveAction);

}

void InputScanner::ClearInputActions()
{
	m_keyboardActions.clear();
	m_clickActions.clear();
	m_moveActions.clear();
}

bool InputScanner::IsKeyboardEvent(sf::Event my_Event)
{
	if (my_Event.type == sf::Event::KeyPressed)
		return true;
	return false;
}

bool InputScanner::IsMouseEvent(sf::Event my_Event)
{
	if (my_Event.type == sf::Event::MouseButtonPressed || my_Event.type == sf::Event::MouseButtonReleased)
		return true;
	return false;
}

bool InputScanner::IsQuitEvent(sf::Event my_Event)
{
	if (my_Event.type == sf::Event::Closed)
		return true;
	return false;
}

bool InputScanner::IsMouseMoveEvent(sf::Event my_Event)
{
	if (my_Event.type == sf::Event::EventType::MouseMoved)
		return true;
	return false;
}
