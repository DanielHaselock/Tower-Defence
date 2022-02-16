#include "pch.h"
#include "path_finding.h"


using namespace ai;

void ai::Graph::index2pos(int* row, int* col, int idx)
{
    *col = idx % 20;
    *row = idx / 20;
}

int ai::Graph::manhattanDistance(int origin, int dest)
{
    int pos1[2];
    int pos2[2];
    index2pos(&pos1[0], &pos1[1], origin);
    index2pos(&pos2[0], &pos2[1], dest);

    int dist = 0;
    dist += abs(pos1[0] - pos2[0]);
    dist += abs(pos1[1] - pos2[1]);

    return dist;
}

void ai::Graph::nodeInit(Node node[], Graph& graph, TD::GameMap gamemap)
{

    int distance[180];
    TD::TerrainType terrain = TD::TerrainType::Grass;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            int t = j + (i * 20);

            terrain = gamemap.Cells[i][j].terrain;

            if (terrain == TD::TerrainType::Grass)
                distance[t] = 8;

            if (terrain == TD::TerrainType::HQ)
                distance[t] = 0;

            if (terrain == TD::TerrainType::Spawn)
                distance[t] = 1;

            if (terrain == TD::TerrainType::Road)
                distance[t] = 2;

            if (terrain == TD::TerrainType::Sand)
                distance[t] = 16;

            if (terrain == TD::TerrainType::Water)
            {
                distance[t] = 99;
            }

        }

    }

    for (int i = 0; i < 180; i++)
    {
        node[i].dist = distance[i];
        node[i].visited = false;
        node[i].index = i;
        node[i].x = float(i % 20);
        node[i].y = float(floor(i / 20));


        if (node[i].dist == 1)
        {
            graph.startNode = i;
        }

        if (node[i].dist == 0)
        {
            graph.endNode = i;
        }
    }
}

bool ai::Graph::checkIfMovementPossible(Node node[], Graph graph, int i)
{
    if (i == graph.actualNode)
    {
        return false;
    }
    if (node[i].visited)
    {
        return false;
    }

    return true;
}

//check le node avec la distance la plus courte
void ai::Graph::dijkstra(Graph& graph, Node node[])
{
    graph.moves.clear();
    graph.visited = 0;
    TD::TowerDefenceGameManager::GetInstance().enmoves_.clear();
    bool finished = false;
    graph.actualNode = graph.startNode;
    graph.moves.push_back(graph.actualNode);//push le node de start
    TD::TowerDefenceGameManager::GetInstance().enmoves_.push_back(graph.actualNode);

    while (graph.visited < 180 && !finished)
    {
        int dir[4] = {int( graph.actualNode - 1 ), int(graph.actualNode - 20), int(graph.actualNode + 20),int(graph.actualNode + 1) }; //0= north 1=south 2=east 3=west

        for (int i = 0; i < 4; i++) //check 4 nodes dans 4 direction si elles sortent de la map
        {
            if (dir[i] < 0 || dir[i] > 180)
                dir[i] = graph.actualNode;
        }

        std::vector<int> shortestDistTab;
        unsigned int shortestDist = 1000;
        int index = 0;

        //checker si le mouvement est possible et trouver la distance la plus petite 
        for (int i = 0; i < 4; i++)
        {
            if (checkIfMovementPossible(node, graph, dir[i]))
            {
                int tempPos = node[dir[i]].index;
                unsigned int distance = node[dir[i]].dist;

                if (distance < shortestDist)
                {
                    shortestDist = distance;
                    index = dir[i];
                    tempPos = node[dir[i]].index;
                }

                if (node[dir[i]].dist == 16)
                {

                    if (i == 1)
                    {
                        if (node[dir[i] - int (20)].dist < shortestDist)
                        {
                            shortestDist = node[dir[i] - int (20)].dist;
                            index = dir[i];

                        }
                    }

                    else if (i == 2)
                    {
                        if (node[dir[i] + int(20)].dist < shortestDist)
                        {
                            shortestDist = node[dir[i] + int(20)].dist;
                            index = dir[i];
                        }
                    }
                    else if (i == 3)
                    {
                        if (node[dir[i] + int(1)].dist < shortestDist)
                        {
                            shortestDist = node[dir[i] + int(1)].dist;
                            index = dir[i];
                        }

                    }

                    else if (i == 0)
                    {
                        if (node[dir[i] - int(1)].dist < shortestDist)
                        {
                            shortestDist = node[dir[i] - int(1)].dist;
                            index = dir[i];
                        }

                    }
                }

            }

        }
        //printf lindex
        // 
        //verifier cette partie
        for (int i = 0; i < 4; i++)
        {
            if (node[dir[i]].dist == shortestDist)
                if (checkIfMovementPossible(node, graph, dir[i]))
                {

                    shortestDistTab.push_back(node[dir[i]].index);
                }


        }

        for (int i = 0; i < shortestDistTab.size(); i++)
        {
            if (shortestDistTab.size() > 1 && node[dir[i]].dist == 2) {

                index = dir[3];
             
            }
        }




        if (shortestDistTab.size() > 1) {
            shortestDist = 1000;


            for (int i = 0; i < shortestDistTab.size(); i++)
            {
                unsigned int temp = manhattanDistance(node[shortestDistTab.at(i)].index, node[graph.endNode].index);

                if (temp < shortestDist)
                {
                    shortestDist = temp;
                    index = shortestDistTab.at(i);
                }
            }
        }
        //printf lindex

        node[graph.actualNode].visited = true;
        graph.visited++;
        graph.actualNode = index;
        graph.moves.push_back(graph.actualNode);
        TD::TowerDefenceGameManager::GetInstance().enmoves_.push_back(graph.actualNode);

        if (node[graph.actualNode].dist == 0)
        {
            finished = true;
        }
    }

    for (int i = 0; i < graph.moves.size(); i++)
    {
       
    }


}
