#include "pch.h"
#include "App.h"
#include "GameMap.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace TD;
int main()
{
    App app;
    app.Init();
    app.Run();

    return 0;
}