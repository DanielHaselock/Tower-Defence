#pragma once
#include "Renderer.h"
#include "InputScanner.h"
namespace TD
{


	enum class GameState
	{
		MAIN_MENU,
		RUNNING,
		GAME_OVER,
		QUIT,
	};

	class IGameManager
	{
	protected:

		sf::Clock Clock;
		float DeltaTime;
		Renderer renderer;
		GameState CurrentState;
		void UpdateDeltaTime();
	public:

		float GetDeltaTime() const;
		void virtual Init(InputScanner* m_inputScanner) = 0;
		void virtual Update() = 0;

	};
}