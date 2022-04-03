#include "GamePlayStatManager.h"
#include <GameEngineBase/GameEngineDebug.h>

GamePlayStatManager::GamePlayStatManager() 
	: Defeat_(false)
    , Hot_(false)
    , Melt_(false)
    , Push_(false)
    , Sink_(false)
    , Stop_(false)
    , Win_(false)
    , You_(false)
{

}

GamePlayStatManager::~GamePlayStatManager() 
{
}

bool GamePlayStatManager::CheckStat(GamePlayUnitObject* _Unit)
{
	std::vector<StatName>::iterator StartIter = _Unit->GetApplyStat().begin();
	std::vector<StatName>::iterator EndIter = _Unit->GetApplyStat().end();
	if (StartIter == EndIter)
	{
		return false;
	}
	for (; StartIter != EndIter; ++StartIter)
	{
		switch (*StartIter)
		{
		case StatName::Error:
			MsgBoxAssert("CheckStat is Error");
			break;
		case StatName::Stop:
			SetStop(_Unit);
			break;
		case StatName::Defeat:
			SetDefeat(_Unit);
			break;
		case StatName::Hot:
			SetHot(_Unit);
			break;
		case StatName::Melt:
			SetMelt(_Unit);
			break;
		case StatName::Push:
			SetPush(_Unit);
			break;
		case StatName::Sink:
			SetSink(_Unit);
			break;
		case StatName::Win:
			SetWin(_Unit);
			break;
		case StatName::You:
			SetYou(_Unit);
			break;
		default:
			break;
		}
	}
	return true;
}

void GamePlayStatManager::SetDefeat(GamePlayUnitObject* _Unit)
{
	if (_Unit->You_ == true)
	{
		_Unit->Kill();
	}
	Defeat_ = true;
}

void GamePlayStatManager::SetHot(GamePlayUnitObject* _Unit)
{
	if (_Unit->Melt_ == true)
	{
		_Unit->Kill();
	}
	Hot_ = true;
}

void GamePlayStatManager::SetMelt(GamePlayUnitObject* _Unit)
{
	if (_Unit->Hot_ == true)
	{
		_Unit->Kill();
	}
	Melt_ = true;
}

void GamePlayStatManager::SetPush(GamePlayUnitObject* _Unit)
{
	Push_ = true;
}

void GamePlayStatManager::SetSink(GamePlayUnitObject* _Unit)
{

}

void GamePlayStatManager::SetStop(GamePlayUnitObject* _Unit)
{

}

void GamePlayStatManager::SetWin(GamePlayUnitObject* _Unit)
{

}

void GamePlayStatManager::SetYou(GamePlayUnitObject* _Unit)
{

}