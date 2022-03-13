#include <Windows.h>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
//#include <GameEngineContents/StudyGame.h>

//StudyGame MyGame;

void GameInit()
{
    //MyGame.GameInit();

}

void GameLoop()
{
    // 게임이 실행된다.

    //MyGame.GameLoop();
}

int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine,
    _In_ int       nCmdShow)
{

    GameEngineDebug::LeakCheckOn();

    GameEngineWindow::GetInst().CreateGameWindow(hInstance, "GameWindow");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(GameInit, GameLoop);

    GameEngineWindow::Destroy();

    //MyGame.GameEnd();
}