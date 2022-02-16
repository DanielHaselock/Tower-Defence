#include "pch.h"
#include "app.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "path_finding.h"
using namespace TD;
void App::Init()
{
    if (!this->my_font.loadFromFile("Assets/fonts/kenvector_future_thin.ttf"))
    {
       
    }


    m_window.Init();
    this->setWindow();
    m_inputScanner.Init(&m_window.get_window());
    m_gameManager.Init(&m_inputScanner);
    m_gameManager.Init_GameMenu();
    Cell::init_image(m_gameManager.getRenderer());
    EnemyConfig::init_image(m_gameManager.getRenderer());
}

void App::Run()
{
    ai::Graph graph;
    ai::Node node[180];

    while (m_window.get_window().isOpen())
    {
        if (m_gameManager.get_GameState() == GameState::RUNNING && mainMenu == false)
        {
            m_gameManager.player.HUD.ClearWindows();
            m_gameManager.getRenderer().RemoveAll();
            m_gameManager.Init_Game();
            graph.nodeInit(node, graph, m_gameManager.Map);
            graph.dijkstra(graph, node);

            mainMenu = true;
            mainGame = false;
            pause = false;
            gameOver = false;
        }

        if (m_gameManager.get_GameState() == GameState::MAIN_MENU && mainGame == false)
        {
            m_gameManager.EnemyArmy.ClearAllEnemies();
            m_gameManager.Map.Clear();
            m_gameManager.enmoves_.clear();
            m_gameManager.player.HUD.ClearWindows();
            m_gameManager.getRenderer().RemoveAll();
            m_gameManager.Init_GameMenu();
            mainMenu = false;
            mainGame = true;
            pause = false;
            gameOver = false;
        }



        m_window.get_window().clear();

        m_inputScanner.Update();
        m_gameManager.Update();
        if (m_gameManager.get_GameState() == GameState::RUNNING)
        {
            m_gameManager.player.UpdateMoney(m_window.get_window(), m_gameManager.player.money, my_font);

            m_gameManager.player.UpdateLives(m_window.get_window(), m_gameManager.player.lives, my_font);
        }

        m_window.get_window().display();


    }


}

void App::setWindow()
{

    m_gameManager.setWindow(&m_window);

}