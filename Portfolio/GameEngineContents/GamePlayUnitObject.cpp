#include "GamePlayUnitObject.h"
#include "GamePlayTextStat.h"

GamePlayUnitObject::GamePlayUnitObject() 
	: AllStat_(0)
{
}

GamePlayUnitObject::~GamePlayUnitObject() 
{
}

void GamePlayUnitObject::UnitObjectFucntion()
{

}


void GamePlayUnitObject::ApplyStat(const GamePlayTextStat* _Stat)
{
	switch (_Stat->GetStat())
	{
	case StatName::Defeat:
		AllStat_ += SDefeat;
		break;
	case StatName::Hot:
		AllStat_ += SHot;
		break;
	case StatName::Melt:
		AllStat_ += SMelt;
		break;
	case StatName::Push:
		AllStat_ += SPush;
		break;
	case StatName::Sink:
		AllStat_ += SSink;
		break;
	case StatName::Stop:
		AllStat_ += SStop;
		break;
	case StatName::Win:
		AllStat_ += SWin;
		break;
	case StatName::You:
		AllStat_ += SYou;
		break;
	default:
		MsgBoxAssert("CheckStat is Error");
		break;
	}
}

void GamePlayUnitObject::ApplyStat(int _idx)
{
	switch (_idx)
	{
	case SDefeat:
		AllStat_ += SDefeat;
		break;
	case SHot:
		AllStat_ += SHot;
		break;
	case SMelt:
		AllStat_ += SMelt;
		break;
	case SPush:
		AllStat_ += SPush;
		break;
	case SSink:
		AllStat_ += SSink;
		break;
	case SStop:
		AllStat_ += SStop;
		break;
	case SWin:
		AllStat_ += SWin;
		break;
	case SYou:
		AllStat_ += SYou;
		break;
	default:
		MsgBoxAssert("CheckStat is Error");
		break;
	}


}
bool GamePlayUnitObject::FindStat(unsigned __int64 _Idx)
{
	return (AllStat_ & _Idx) == _Idx;
}
