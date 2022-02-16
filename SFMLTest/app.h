#pragma once
#include "window.h"
#include "TowerDefenceGameManager.h"
#include "InputScanner.h"
namespace TD
{


	class App
	{
	private:
		Window m_window;
		TowerDefenceGameManager& m_gameManager = TowerDefenceGameManager::GetInstance();
		InputScanner m_inputScanner;
		sf::Font my_font;

	public:
		void Init();
		void Run();
		void setWindow();



		bool mainMenu = false;
		bool mainGame = false;
		bool pause = false;
		bool gameOver = false;
	};
}