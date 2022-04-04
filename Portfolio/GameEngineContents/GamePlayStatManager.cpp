#include "GamePlayStatManager.h"
#include <GameEngineBase/GameEngineDebug.h>


GamePlayStatManager::GamePlayStatManager() 
	: AllStat_(0)
{

}

GamePlayStatManager::~GamePlayStatManager() 
{
}

void GamePlayStatManager::Reset()
{
	AllStat_ = 0;
}

void GamePlayStatManager::ApplyStat(const GamePlayTextStat* _Stat)
{
	switch (_Stat->GetStat())
	{
	case StatName::Stop:
		SetStop();
		break;
	case StatName::Defeat:
		SetDefeat();
		break;
	case StatName::Hot:
		SetHot();
		break;
	case StatName::Melt:
		SetMelt();
		break;
	case StatName::Push:
		SetPush();
		break;
	case StatName::Sink:
		SetSink();
		break;
	case StatName::Win:
		SetWin();
		break;
	case StatName::You:
		SetYou();
		break;
	default:
		MsgBoxAssert("CheckStat is Error");
		break;
	}
}

void GamePlayStatManager::SetDefeat()
{
	AllStat_ += 1;
}

void GamePlayStatManager::SetHot()
{
	AllStat_ += 2;
}


void GamePlayStatManager::SetMelt()
{
	AllStat_ += 4;
}

void GamePlayStatManager::SetPush()
{
	AllStat_ += 8;
}

void GamePlayStatManager::SetSink()
{
	AllStat_ += 16;
}

void GamePlayStatManager::SetStop()
{
	AllStat_ += 32;
}

void GamePlayStatManager::SetWin()
{
	AllStat_ += 64;
}

void GamePlayStatManager::SetYou()
{
	AllStat_ += 128;
}