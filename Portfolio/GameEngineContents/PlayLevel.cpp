#include "PlayLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineInput.h>

#include "Coordinate.h"
#include "BackGround.h"
#include "MainLevel.h"
#include "GamePlayTextStat.h"
#include "PlayBackGround.h"



PlayLevel::PlayLevel() 
	:GameWindowStartPosX_(0),
	GameWindowStartPosY_(0),
	MapScale_({ 0, 0 }),
	CurrentStage_(Stage::MainStage)
{
}

PlayLevel::~PlayLevel() 
{

}


void PlayLevel::Loading()
{

}

void PlayLevel::Update()
{
	if (true == KeyCheck())
	{
		ScanFucntion();
		CheckMapAllStat();
	}

}

void PlayLevel::LevelChangeEnd()
{
	//EndStage();
}

void PlayLevel::LevelChangeStart()
{
	CurrentStage_ = MainLevel::GetCurrentStage();
	MapScale_ = StageData::Inst_->Scale_[CurrentStage_];
	CreateActor<BackGround>(0);
	CreateActor<PlayBackGround>(1)->CreateRendererToScale("Stage0.bmp", { MapScale_.x * DotSizeX, MapScale_.y * DotSizeY });
	GameWindowStartPosX_ = (GameEngineWindow::GetScale().x - MapScale_.x * DotSizeX) / 2;
	GameWindowStartPosY_ = (GameEngineWindow::GetScale().y - MapScale_.y * DotSizeY) / 2;

	CreatMap(StageData::Inst_->StageData_[CurrentStage_]);
	ScanFucntion();
	CheckMapAllStat();
}


void PlayLevel::CreatMap(std::map<int, std::map<int, ObjectName>>& _Stage)
{
	for (int y = 0; y < MapScale_.iy(); ++y)
	{
		for (int x = 0; x < MapScale_.ix(); ++x)
		{
			GamePlayObject* Value = (GamePlayGobal::GetInst()->Find(_Stage[y][x]));
			if (Value == nullptr)
			{
			continue;
			}
			Coordinate* Coordi = CreateActor<Coordinate>(1);
			Coordi->SetPos({ static_cast<float>(x), static_cast<float>(y) }, { GameWindowStartPosX_ + static_cast<float>(x * DotSizeX), GameWindowStartPosY_ + static_cast<float>(y * DotSizeY) });
			Coordi->SetValue(Value);
			CurrentMap_[y][x].push_back(Coordi);
		}
	}
}

void PlayLevel::ScanFucntion()
{
	GamePlayGobal::GetInst()->ReSetStat();
	std::map<int, std::map<int, std::list<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
	std::map<int, std::map<int, std::list<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();


	int X = 0;
	int Y = 0;

	for (; StartIterY != EndIterY; ++StartIterY)
	{
		Y = StartIterY->first;
		std::map<int, std::list<Coordinate*>>::iterator StartIterX = StartIterY->second.begin();
		std::map<int, std::list<Coordinate*>>::iterator EndIterX = StartIterY->second.end();
		for (; StartIterX != EndIterX; ++StartIterX)
		{
			X = StartIterX->first;
			std::list<Coordinate*>& Block = StartIterX->second;

			for (auto iter : Block)
			{
				if (iter->GetTextObjectInst()->GetTextType() == TextType::Verb_Text)
				{
					CheckFunction(X, Y, iter);
				}	
			}
		}
	}
}

bool PlayLevel::CheckFunction(int _X, int _Y, Coordinate* _Verb)
{
	bool CheckFucn = false;
	if (_X > 0 && _X < MapScale_.ix()-1)
	{
		for (auto iterMinus : CurrentMap_[_Y][_X - 1])
		{
			if (iterMinus->GetTextObjectInst()->GetTextType() == TextType::Unit_Text)
			{
				for (auto iterPlus : CurrentMap_[_Y][_X + 1])
				{
					if (iterPlus->GetTextObjectInst()->GetTextType() == TextType::Unit_Text || iterPlus->GetTextObjectInst()->GetTextType() == TextType::Stat_Text)
					{
						ApplyObjectFuction(iterMinus, _Verb, iterPlus);
						CheckFucn = true;
					}
				}
			}
		}
	}
	if (_Y > 0 && _Y < MapScale_.iy() - 1)
	{
		for (auto iterMinus : CurrentMap_[_Y - 1][_X])
		{
			if (iterMinus->GetTextObjectInst()->GetTextType() == TextType::Unit_Text)
			{
				for (auto iterPlus : CurrentMap_[_Y + 1][_X])
				{
					if (iterPlus->GetTextObjectInst()->GetTextType() == TextType::Unit_Text || iterPlus->GetTextObjectInst()->GetTextType() == TextType::Stat_Text)
					{
						ApplyObjectFuction(iterMinus, _Verb, iterPlus);
						CheckFucn = true;
					}
				}
			}
		}
	}
	return CheckFucn;
}


void PlayLevel::ApplyObjectFuction(Coordinate* _Unit, Coordinate* _Verb,  Coordinate* _Stat)
{
	_Unit->SetON();
	_Verb->SetON();
	_Stat->SetON();

	if (_Stat->GetTextObjectInst()->GetTextType() == TextType::Stat_Text)
	{
		(static_cast<GamePlayUnitText*>(_Unit->GetTextObjectInst()))->GetTextUnit()->ApplyStat(static_cast<GamePlayTextStat*>(_Stat->GetTextObjectInst()));
	}

	if (_Stat->GetTextObjectInst()->GetTextType() == TextType::Unit_Text)
	{
		ChangeUnit(static_cast<GamePlayUnitText*>(_Unit->GetTextObjectInst())->GetTextUnit(), static_cast<GamePlayUnitText*>(_Stat->GetTextObjectInst())->GetTextUnit());
	}
}

void PlayLevel::ChangeUnit(const GamePlayUnitObject* _Left, GamePlayUnitObject* _Right)
{
	std::map<int, std::map<int, std::list<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
	std::map<int, std::map<int, std::list<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();

	for (; StartIterY != EndIterY; ++StartIterY)
	{
		std::map<int, std::list<Coordinate*>>::iterator StartIterX = StartIterY->second.begin();
		std::map<int, std::list<Coordinate*>>::iterator EndIterX = StartIterY->second.end();
		for (; StartIterX != EndIterX; ++StartIterX)
		{
			std::list <Coordinate*>& Block = StartIterX->second;
			for (auto iter : Block)
			{
				if (iter->GetUnitObjectInst() == _Left)
				{
					iter->SetValue(_Right);
				}
			}
		}
	}
}

void PlayLevel::CheckMapAllStat()
{
	std::map<int, std::map<int, std::list<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
	std::map<int, std::map<int, std::list<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();

	for (; StartIterY != EndIterY; ++StartIterY)
	{
		std::map<int, std::list<Coordinate*>>::iterator StartIterX = StartIterY->second.begin();
		std::map<int, std::list<Coordinate*>>::iterator EndIterX = StartIterY->second.end();
		for (; StartIterX != EndIterX; ++StartIterX)
		{
			CheckBitStat(StartIterX->second);
		}
	}
}


void PlayLevel::CheckBitStat(std::list<Coordinate*>& _Value)
{
	// Defeat
	{
		if (FindUnitByStat(_Value, SDefeat) == true && FindUnitByStat(_Value, SYou) == true)
		{
			for (auto iter : _Value)
			{
				if (iter->GetUnitObjectInst()->FindStat(SYou) == true && iter->IsDeath() == false)
				{
					iter->Death();
				}
			}
		}
	}
	// Sink
	{
		if (FindUnitByStat(_Value, SSink) == true)
		{
			for (auto iter : _Value)
			{
				iter->Death();
			}
		}
	}

	// Hot, Melt
	{
		if (FindUnitByStat(_Value, SHot) == true && FindUnitByStat(_Value, SMelt))
		{
			for (auto iter : _Value)
			{
				if (iter->GetUnitObjectInst()->FindStat(SYou) == true && iter->IsDeath() == false)
				{
					iter->Death();
				}
			}
		}
	}
	// Win
	{
		if (FindUnitByStat(_Value, SWin) == true && 
			FindUnitByStat(_Value, SYou) == true)
		{
			for (auto iter : _Value)
			{
				if (iter->GetUnitObjectInst()->FindStat(SYou) == true && iter->IsDeath() == false)
				{
					ClearStage();
				}
			}
		}
	}
}

bool PlayLevel::FindUnitByStat(std::list<Coordinate*>& _Value, unsigned __int64 _Stat)
{
	for (auto iter : _Value)
	{
		if ((iter->GetUnitObjectInst()->GetAllStat() & _Stat) == _Stat)
		{
			return true;
		}
	}
	return false;
}


bool PlayLevel::IsMapOut(std::pair<int, int> _Pos)
{
	if (MapScale_.ix() <= _Pos.first || _Pos.first < 0)
	{
		return true;
	}
	if (MapScale_.iy() <= _Pos.second || _Pos.second < 0)
	{
		return true;
	}
	return false;
}


bool PlayLevel::KeyCheck()
{
	if (GameEngineInput::GetInst()->IsDown("Down"))
	{
		ScanFucntion();
		CheckMapAllStat(std::make_pair(0, 1));
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("Up"))
	{
		ScanFucntion();
		CheckMapAllStat(std::make_pair(0, -1));
		return true;
	}

	if (GameEngineInput::GetInst()->IsDown("Right"))
	{
		ScanFucntion();
		CheckMapAllStat(std::make_pair(1, 0));
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("Left"))
	{
		ScanFucntion();
		CheckMapAllStat(std::make_pair(-1, 0));
		return true;
	}


	if (GameEngineInput::GetInst()->IsDown("Space"))
	{

	}
	if (GameEngineInput::GetInst()->IsDown("R"))
	{

	}
	if (GameEngineInput::GetInst()->IsDown("Space"))
	{

	}

	return false;
}

void PlayLevel::CheckMapAllStat(std::pair<int, int> _MoveDir)
{
	std::map<int, std::map<int, std::list<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
	std::map<int, std::map<int, std::list<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();

	int X = 0;
	int Y = 0;

	for (; StartIterY != EndIterY; ++StartIterY)
	{
		Y = StartIterY->first;
		std::map<int, std::list<Coordinate*>>::iterator StartIterX = StartIterY->second.begin();
		std::map<int, std::list<Coordinate*>>::iterator EndIterX = StartIterY->second.end();
		for (; StartIterX != EndIterX; ++StartIterX)
		{
			X = StartIterX->first;
			std::list<Coordinate*>& Ref = StartIterX->second;
			CheckBitStat(Ref);
			std::list<Coordinate*>::iterator StartIterList = Ref.begin();
			std::list<Coordinate*>::iterator EndIterList = Ref.end();
			while (StartIterList != EndIterList)
			{
				if ((*StartIterList)->GetUnitObjectInst()->FindStat(SYou) == true && (*StartIterList)->IsDeath() == false)
				{
					if ((*StartIterList)->IsMove() == false && CheckBitMove(X, Y, _MoveDir) == true)
					{
						StartIterList = Ref.erase(Move(StartIterList, _MoveDir));
						continue;
					}
				}
				++StartIterList;
			}
		}
	}
}

bool PlayLevel::CheckBitMove(int _x, int _y, std::pair<int, int> _MoveDir)
{
	int X = _x + _MoveDir.first;
	int Y = _y + _MoveDir.second;
	if (IsMapOut(std::make_pair(X, Y)) == true)
	{
		return false;
	}

	// Stop
	{
		for (auto iter : CurrentMap_[Y][X])
		{
			if (iter->GetUnitObjectInst()->FindStat(SStop) == true)
			{
				if (iter->GetUnitObjectInst()->FindStat(SPush) == true)
				{
					continue;
				}
				return false;
			}
		}
	}

	// Push
	{
		std::list<Coordinate*>& Ref = CurrentMap_[Y][X];
		std::list<Coordinate*>::iterator StartIterList = Ref.begin();
		std::list<Coordinate*>::iterator EndIterList = Ref.end();
		while (StartIterList != EndIterList)
		{
			if ((*StartIterList)->GetUnitObjectInst()->FindStat(SPush) == true)
			{
				if (CheckBitMove(X, Y, _MoveDir) == false)
				{
					return false;
				}
				else
				{
					StartIterList = Ref.erase(Move(StartIterList, _MoveDir));
					continue;
				}
			}
			++StartIterList;
		}
	}
	return true;
}

std::list<Coordinate*>::iterator& PlayLevel::Move(std::list<Coordinate*>::iterator& _ListIter, std::pair<int, int> _MoveDir)
{
	int PastX = (*_ListIter)->GetPos().ix();
	int PastY = (*_ListIter)->GetPos().iy();
	int x = PastX + _MoveDir.first;
	int y = PastY + _MoveDir.second;
	if (_MoveDir.first == 1)
	{
		(*_ListIter)->ChangePos({ static_cast<float>(x), static_cast<float>(y) }, { GameWindowStartPosX_ + static_cast<float>(x * DotSizeX), GameWindowStartPosY_ + static_cast<float>(y * DotSizeY) }, Direction::Right);		
	}
	else if (_MoveDir.second == 1)
	{
		(*_ListIter)->ChangePos({ static_cast<float>(x), static_cast<float>(y) }, { GameWindowStartPosX_ + static_cast<float>(x * DotSizeX), GameWindowStartPosY_ + static_cast<float>(y * DotSizeY) }, Direction::Down);
	}
	else if (_MoveDir.first == -1)
	{
		(*_ListIter)->ChangePos({ static_cast<float>(x), static_cast<float>(y) }, { GameWindowStartPosX_ + static_cast<float>(x * DotSizeX), GameWindowStartPosY_ + static_cast<float>(y * DotSizeY) }, Direction::Left);
	}
	else if (_MoveDir.second == -1)
	{
		(*_ListIter)->ChangePos({ static_cast<float>(x), static_cast<float>(y) }, { GameWindowStartPosX_ + static_cast<float>(x * DotSizeX), GameWindowStartPosY_ + static_cast<float>(y * DotSizeY) }, Direction::Up);
	}
	CurrentMap_[y][x].push_back(*_ListIter);
	return _ListIter;
}

void PlayLevel::ClearStage()
{

}


void PlayLevel::EndStage()
{
	ReleaseActor();

}

void PlayLevel::ReleaseActor()
{
	std::map<int, std::map<int, std::list<Coordinate*>>>::iterator StartIter = CurrentMap_.begin();
	std::map<int, std::map<int, std::list<Coordinate*>>>::iterator EndIter = CurrentMap_.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		std::map<int, std::list<Coordinate*>>::iterator StartCoord = (StartIter->second).begin();
		std::map<int, std::list<Coordinate*>>::iterator EndCoord = (StartIter->second).end();
		for (; StartCoord != EndCoord; ++StartCoord)
		{
			std::list<Coordinate*>::iterator StartVector = (StartCoord->second).begin();
			std::list<Coordinate*>::iterator EndVector = (StartCoord->second).end();
			for (; StartVector != EndVector; ++StartVector)
			{
				if ((*StartVector) != nullptr)
				{
					(*StartVector)->Death();
				}
			}
		}
	}
}