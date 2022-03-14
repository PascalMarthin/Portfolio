#include <Windows.h>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
//#include <GameEngineContents/StudyGame.h>
#include <GameEngineCon/>
// 임시로 헤더 추가


int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine,
    _In_ int       nCmdShow)
{

    //GameEngineDebug::LeakCheckOn();

    //GameEngineWindow::GetInst().CreateGameWindow(hInstance, "GameWindow");
    //GameEngineWindow::GetInst().ShowGameWindow();
    //GameEngineWindow::GetInst().MessageLoop(GameInit, GameLoop);
    //GameEngineWindow::Destroy();

    //MyGame.GameEnd();
    GameEngine::Start<BabaIsYou>();

}