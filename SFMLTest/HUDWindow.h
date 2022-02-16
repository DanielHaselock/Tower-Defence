#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "HUDButton.h"
#include "IGameManager.h"


namespace TD
{


	class HUDWindow
	{

	public:
		std::vector<HUDButton*> Buttons;
		sf::Vector2i Position;
		Sprite* sprite;

		template <typename T> T* AddButton()
		{
			T* button = new T;
			this->Buttons.push_back(button);
			return button;


		};
		void Clear();
		//virtual void Create() = 0;



	};
}

