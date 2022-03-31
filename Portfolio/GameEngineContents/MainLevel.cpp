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
	// 코디네이터 제거
}


void MainLevel::Loading()
{
	std::map<int, std::map<int, Coordinate*>> Makemap;
	{

	}
}

void MainLevel::Update()
{


}

void MainLevel::LevelChangeStart()
{
	CreateActor<BackGround>(0);
	CreateActor<MainBackGround>(1, "MainBackGround");
	//CreateActor<MainStage>("MainStage", 2);
	//CreateActor<MainCursor>(2, "MainCursor");
}