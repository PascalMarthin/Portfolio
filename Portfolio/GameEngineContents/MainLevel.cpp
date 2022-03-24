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
	CreateActor<MainBackGround>("BackGround", 0);
	CreateActor<MainBackGround>("MainBackGround", 1);
	//CreateActor<MainStage>("MainStage", 2);
	CreateActor<MainCursor>("MainCursor", 3);
}