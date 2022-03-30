#include <Windows.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/BabaIsYou.h>


int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char*     lpCmdLine,
    _In_ int       nCmdShow)
{

    //_CrtSetBreakAlloc(163);
    //new int();
    GameEngine::Start<BabaIsYou>();

}