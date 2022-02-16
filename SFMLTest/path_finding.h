#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>   
#include "GameMap.h"
#include "TowerDefenceGameManager.h"

namespace ai
{
    class Node
    {
    public:

        unsigned int dist;
        unsigned int index;
        float x;
        float y;
        bool visited;


    };

    class Graph
    {
    public:
        int visited;
        int startNode;
        int endNode;

        Graph()
        {
            visited = 0;
        }

        //permet de stocker la route a empreinter
        std::vector <unsigned int> moves;

        //reference de ou je suis
        unsigned int actualNode;

        void dijkstra(Graph& graph, Node node[]);
        void nodeInit(Node node[], Graph& graph, TD::GameMap gamemap);
        void index2pos(int* row, int* col, int idx);
        int manhattanDistance(int origin, int dest);
        bool checkIfMovementPossible(Node node[], Graph graph, int i);

    };
}
