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
		if ((AllStat_ & SDefeat) != SDefeat)
		{
			AllStat_ += SDefeat;
		}
		break;
	case StatName::Hot:
		if ((AllStat_ & SHot) != SHot)
		{
			AllStat_ += SHot;
		}
		break;
	case StatName::Melt:
		if ((AllStat_ & SMelt) != SMelt)
		{
			AllStat_ += SMelt;
		}
		break;
	case StatName::Push:
		if ((AllStat_ & SPush) != SPush)
		{
			AllStat_ += SPush;
		}
		break;
	case StatName::Sink:
		if ((AllStat_ & SSink) != SSink)
		{
			AllStat_ += SSink;
		}
		break;
	case StatName::Stop:
		if ((AllStat_ & SStop) != SStop)
		{
			AllStat_ += SStop;
		}
		break;
	case StatName::Win:
		if ((AllStat_ & SWin) != SWin)
		{
			AllStat_ += SWin;
		}
		break;
	case StatName::You:
		if ((AllStat_ & SYou) != SYou)
		{
			AllStat_ += SYou;
		}
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
