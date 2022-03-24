#include "MainLevel.h"
#include "MainStage.h"
#include "MainBackGround.h"
#include "MainCursor.h"

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
	CreateActor<MainBackGround>("MainBackGround", 0);
	//CreateActor<MainStage>("MainStage", 1);
	CreateActor<MainCursor>("MainCursor", 2);
}