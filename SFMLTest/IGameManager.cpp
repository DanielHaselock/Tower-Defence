#include "pch.h"
#include "IGameManager.h"
using namespace TD;
void IGameManager::UpdateDeltaTime()
{
	DeltaTime = Clock.restart().asSeconds();


}

float IGameManager::GetDeltaTime() const
{
	return DeltaTime;


}

