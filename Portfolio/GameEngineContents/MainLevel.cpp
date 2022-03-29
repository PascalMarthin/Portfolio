#include "MainLevel.h"
#include "MainBackGround.h"
#include "MainCursor.h"
#include "Coordinate.h"
#include "BackGround.h"

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
	CreateActor<BackGround>(0);
	CreateActor<MainBackGround>(1, "MainBackGround");
	//CreateActor<MainStage>("MainStage", 2);
	CreateActor<MainCursor>(2, "MainCursor");
}