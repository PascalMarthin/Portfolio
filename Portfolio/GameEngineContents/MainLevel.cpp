#include "MainLevel.h"
#include "MainBackGround.h"
#include "MainCursor.h"
#include "Coordinate.h"

MainLevel::MainLevel()
{
}

MainLevel::~MainLevel()
{
}


void MainLevel::Loading()
{

}

void MainLevel::Update()
{


}

void MainLevel::LevelChangeStart()
{
	CreateActor<MainBackGround>(1, "MainBackGround");
	//CreateActor<MainStage>("MainStage", 2);
	CreateActor<MainCursor>(2, "MainCursor");
}