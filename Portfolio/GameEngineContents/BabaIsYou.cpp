#include "BabaIsYou.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

BabaIsYou::BabaIsYou() 
{
}

BabaIsYou::~BabaIsYou() 
{
}

void BabaIsYou::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1280, 720 });

	GameEngineImageManager::GetInst()->Load("C:\\Users\\82103\\Desktop\\프로젝트\\Portfolio\\Portfolio\\Resources\\Sprites\\Ui\\TitleLogo\\main_1.bmp", "main_1.bmp");

	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	//CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Title");
}
void BabaIsYou::GameLoop()
{
	
}
void BabaIsYou::GameEnd()
{

}