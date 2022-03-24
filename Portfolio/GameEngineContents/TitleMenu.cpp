#include "TitleMenu.h"
#include <Windows.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

TitleMenu::TitleMenu()
	: BabaTitleLocate(BabaLocation::Null)
{
}

TitleMenu::~TitleMenu()
{
}



void TitleMenu::Start()
{
	// GameEngineWindow::GetScale().Half() ȭ�� �߾�
	SetPosition(GameEngineWindow::GetScale().Half());
	//SetScale({ 10, 100 });

	CreateRenderer("Start_the_Game2.bmp", RenderPivot::CENTER, { 0, 100 });
	CreateRenderer("Settings2.bmp", RenderPivot::CENTER, { 0, 190 });
	CreateRenderer("Exit_The_Game2.bmp", RenderPivot::CENTER, { 0, 280 });

	CreateRenderer("Start_the_Game1.bmp",  RenderPivot::CENTER, { 0, 100 });
	CreateRenderer("Settings1.bmp", RenderPivot::CENTER, { 0, 190 });
	CreateRenderer("Exit_The_Game1.bmp", RenderPivot::CENTER, { 0, 280 });
	CreateRenderer("baba_0_1.bmp", RenderPivot::CENTER, { -320 , 100});
	BabaTitleLocate = BabaLocation::Start_the_Game;
}

void TitleMenu::Update()
{
	/*switch (BabaTitleLocate)
	{
	case BabaLocation::Null:
		MsgBoxAssert("Tilteȭ�鿡�� BabaLocation�� Null�Դϴ�")
		break;
	case BabaLocation::Start_the_Game:
		break;
	case BabaLocation::Settings:
		break;
	case BabaLocation::Exit_The_Game:
		break;
	default:
		break;
	}*/
}

void TitleMenu::Render()
{

}