#include "Coordinate.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>

Coordinate::Coordinate() 
{
}

Coordinate::~Coordinate() 
{
}

void Coordinate::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());

}
void Coordinate::Update()
{

}
void Coordinate::Render()
{
	//GameEngine::BackBufferImage()->TransCopy((*StopImage_)[0][0], CPos_, RGB(255, 0, 255));
}
