#include "GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GameEngineLevel.h"

std::map<std::string, GameEngineLevel*> GameEngine::AllLevel_;
GameEngineLevel* GameEngine::CurrentLevel_ = nullptr;
GameEngineLevel* GameEngine::NextLevel_ = nullptr;
GameEngine* GameEngine::UserContents_ = nullptr;


GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{

}

// 게임 전 세팅
void GameEngine::GameInit()
{

}

// 게임 실행 (루프)
void GameEngine::GameLoop()
{

}

// 게임 종료
void GameEngine::GameEnd()
{

}




void GameEngine::WindowCreate()
{
    GameEngineWindow::GetInst().CreateGameWindow(nullptr, "GameWindow");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(EngineInit, EngineLoop);
}

void GameEngine::EngineInit()
{
    UserContents_->GameInit();
}

void GameEngine::EngineLoop()
{
    // 엔진수준에서 매 프레임마다 체크하고 싶은거
    UserContents_->GameLoop();

    // 시점함수

    // 업데이트 전 레벨전환 검사
    if (nullptr != NextLevel_)
    {
        if (nullptr != CurrentLevel_)
        {
            CurrentLevel_->SceneChangeEnd();
        }

        // NextLevel이 CurrentLevel로 전환
        CurrentLevel_ = NextLevel_;

        if (nullptr != CurrentLevel_)
        {
            CurrentLevel_->SceneChangeStart();
        }

        NextLevel_ = nullptr;
    }

    // 오류 : 현재 레벨이 존재하지 않음(Nullptr)
    if (nullptr == CurrentLevel_)
    {
        MsgBoxAssert("Level is nullptr => GameEngine Loop Error");
    } 


    // 레벨수준 시간제한이 있는 게임이라면
    // 매 프레임마다 시간을 체크해야하는데 그런일을 
    CurrentLevel_->Update();
    CurrentLevel_->ActorUpdate();
    CurrentLevel_->ActorRender();

}

// 엔진 종료
void GameEngine::EngineEnd()
{
    // 게임 종료
    UserContents_->GameEnd();

    std::map<std::string, GameEngineLevel*>::iterator StartIter = AllLevel_.begin();
    std::map<std::string, GameEngineLevel*>::iterator EndIter = AllLevel_.end();

    for (; StartIter != EndIter; ++StartIter)
    {
        if (nullptr == StartIter->second)
        {
            continue;
        }
        delete StartIter->second;
    }

    GameEngineWindow::Destroy();
}

void GameEngine::ChangeLevel(const std::string& _Name)
{
    std::map<std::string, GameEngineLevel*>::iterator FindIter = AllLevel_.find(_Name);

    if (AllLevel_.end() == FindIter)
    {
        MsgBoxAssert("Level Find Error");
        return;
    }
    NextLevel_ = FindIter->second;
}