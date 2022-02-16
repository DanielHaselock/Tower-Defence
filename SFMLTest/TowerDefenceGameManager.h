#pragma once
#include "IGameManager.h"
#include "GameMap.h"
#include "Player.h"
namespace TD
{


	class TowerDefenceGameManager : public IGameManager
	{
	private:
		TowerDefenceGameManager() {
			towerChoose = nullptr;
			m_inputScanner = nullptr;
			start = 0;
		};


	public:
		Player player;
		EnemyArmy EnemyArmy;
		GameMap Map;
		InputScanner* m_inputScanner;



		void Init(InputScanner* m_inputScanner) override;
		void Init_GameMenu();
		void Init_Game();
		void Init_Pause();
		void Init_GameOver();
		void Update() override;
		void setWindow(Window* my_window);
		static TowerDefenceGameManager my_Static_TowerDefenceGameManager;
		static TowerDefenceGameManager& GetInstance();
		GameState& get_GameState();
		std::string map_choose;
		ITower* towerChoose;
		Renderer& getRenderer();
		std::vector<unsigned int> enmoves_;
		int start;
		//GameState my_GameState_variables;

	};
}