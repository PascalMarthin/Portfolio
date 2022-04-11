#include "PlayLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>

#include "Coordinate.h"
#include "BackGround.h"
#include "MainLevel.h"
#include "GamePlayTextStat.h"
#include "PlayBackGround.h"
#include "ClearScene.h"



PlayLevel::PlayLevel() 
	:GameWindowStartPosX_(0),
	GameWindowStartPosY_(0),
	MapScale_({ 0, 0 }),
	CurrentStage_(Stage::MainStage),
	ClearScene_(nullptr),
	IsClear_(false),
	ClearWait(0.0f),
	BackGround_(nullptr)
{
}

PlayLevel::~PlayLevel() 
{
	EndStage();
}


void PlayLevel::Loading()
{
	CreateActor<BackGround>(0);
	ClearScene_ = CreateActor<ClearScene>(5);
	AllMoveHistory_.reserve(10000);

}

void PlayLevel::Update()
{

	if (true == KeyCheck())
	{
		StageFucntionReset();
		ScanFucntionAndBridgeUnit();
		CheckMapAllStat();
	}

	if (IsClear_ == true)
	{
		ClearWait -= GameEngineTime::GetDeltaTime();
		if (ClearWait < 0)
		{
			GameEngine::GetInst().ChangeLevel("MainLevel");

		}
	}

}

void PlayLevel::LevelChangeEnd()
{
	EndStage();
	ReSetLevel();
	ClearScene_->SetStayOFF();


}

void PlayLevel::LevelChangeStart()
{

	CurrentStage_ = MainLevel::GetCurrentStage();
	MapScale_ = StageData::Inst_->Scale_[CurrentStage_];
	BackGround_ = CreateActor<PlayBackGround>(1);
	BackGround_->CreateRendererToScale("Stage0.bmp", { MapScale_.x * DotSizeX, MapScale_.y * DotSizeY });
	GameWindowStartPosX_ = (GameEngineWindow::GetScale().x - MapScale_.x * DotSizeX) / 2;
	GameWindowStartPosY_ = (GameEngineWindow::GetScale().y - MapScale_.y * DotSizeY) / 2;

	CreatMap(StageData::Inst_->StageData_[CurrentStage_]);
	StageFucntionReset();
	ScanFucntionAndBridgeUnit();
	CheckMapAllStat();

}
void PlayLevel::ReSetLevel()
{
	GameWindowStartPosX_ = 0;
	GameWindowStartPosY_ = 0;
	CurrentStage_ =Stage::MainStage;
	IsClear_ = (false);
	ClearWait = (0.0f);
	IsClear_ = false;
	AllCoordinate_.clear();
	AllMoveHistory_.clear();
	CurrentMap_.clear();
	ClearScene_->Off();
	BackGround_->Death();
	BackGround_ = nullptr;
}

unsigned int PlayLevel::CheckUnitBridge(const Coordinate* _Unit)
{
	if (!(_Unit->GetUnitObjectInst()->GetName() == ObjectName::Grass_Unit ||
		_Unit->GetUnitObjectInst()->GetName() == ObjectName::Lava_Unit ||
		_Unit->GetUnitObjectInst()->GetName() == ObjectName::Water_Unit ||
		_Unit->GetUnitObjectInst()->GetName() == ObjectName::Wall_Unit))
	{
		return -1;
	}

	int X = _Unit->GetPos().ix();
	int Y = _Unit->GetPos().iy();
	unsigned int Idx = 0;

	if (IsMapOut(std::make_pair(X, Y + 1)) == false)
	{
		if (FindUnitObject(CurrentMap_[Y + 1][X], _Unit->GetUnitObjectInst()->GetName()) != nullptr)
		{
			Idx += 1;
		}
	}

	if (IsMapOut(std::make_pair(X - 1, Y)) == false)
	{
		if (FindUnitObject(CurrentMap_[Y][X  - 1], _Unit->GetUnitObjectInst()->GetName()) != nullptr)
		{
			Idx += 2;
		}
	}


	if (IsMapOut(std::make_pair(X + 1, Y)) == false)
	{
		if (FindUnitObject(CurrentMap_[Y][X + 1], _Unit->GetUnitObjectInst()->GetName()) != nullptr)
		{
			Idx += 4;
		}
	}

	if (IsMapOut(std::make_pair(X, Y - 1)) == false)
	{
		if (FindUnitObject(CurrentMap_[Y - 1][X], _Unit->GetUnitObjectInst()->GetName()) != nullptr)
		{
			Idx += 8;
		}
	}
	return Idx;
}

Coordinate* PlayLevel::FindUnitObject(std::list<Coordinate*>& _UnitList, const ObjectName _Unit)
{
	std::list<Coordinate*>::iterator StartIter = _UnitList.begin();
	std::list<Coordinate*>::iterator EndIter = _UnitList.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		if ((*StartIter)->IsUpdate() == true)
		{
			if ((*StartIter)->GetUnitObjectInst()->GetName() == _Unit)
			{
				return (*StartIter);
			}
			else if ((*StartIter)->GetTextObjectInst()->GetName() == _Unit)
			{
				return (*StartIter);
			}

		}
	}
	return nullptr;
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
			AllCoordinate_.push_back(Coordi);
		}
	}
}

void PlayLevel::StageFucntionReset()
{
	GamePlayGobal::GetInst()->ReSetStat();
	for (auto Iter : AllCoordinate_)
	{
		Iter->SetOFF();
	}
}

void PlayLevel::StageSave()
{
	//AllCoordinate를 사용안하는 이유는 실수로 놓친 메모리까지 Coordinate를 해제할수있게 모아두기 때문
	// 나중에 테스트에 걸쳐서 변경 예정

	std::map<Coordinate*, const CooridnateHistoryData*>* History = new std::map<Coordinate*, const CooridnateHistoryData*>;
	{
		std::map<int, std::map<int, std::list<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
		std::map<int, std::map<int, std::list<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();
		for (; StartIterY != EndIterY; ++StartIterY)
		{
			std::map<int, std::list<Coordinate*>>::iterator StartIterX = StartIterY->second.begin();
			std::map<int, std::list<Coordinate*>>::iterator EndIterX = StartIterY->second.end();
			for (; StartIterX != EndIterX; ++StartIterX)
			{
				std::list<Coordinate*>& Block = StartIterX->second;
				for (auto iter : Block)
				{
					CooridnateHistoryData* Data = new CooridnateHistoryData(iter);
					(*History)[iter] = Data;
				}
			}
		}
	}
	AllMoveHistory_.push_back(History);

}

void PlayLevel::BackTothePast()
{
	if (AllMoveHistory_.size() <= 0 )
	{
		return;
	}
	std::map< Coordinate*, const CooridnateHistoryData*>::iterator StartIterMap = AllMoveHistory_.back()->begin();
	std::map< Coordinate*, const CooridnateHistoryData*>::iterator EndIterMap = AllMoveHistory_.back()->end();
	while (StartIterMap != EndIterMap)
	{
		// 업데이트가 실행될때
		(*StartIterMap).first->KeyIsPushOn();
		if ((*StartIterMap).second->IsUpdate_ == true)
		{
			if ((*StartIterMap).first->GetObjectType() == ObjectType::Text)
			{
				if ((*StartIterMap).first->GetTextObjectInst()->GetName() != (*StartIterMap).second->ObjectName_)
				{
					// 아직 사용하지 않는 함수
				}
					
			}
			else if ((*StartIterMap).first->GetObjectType() == ObjectType::Unit)
			{
				if ((*StartIterMap).first->GetUnitObjectInst()->GetName() != (*StartIterMap).second->ObjectName_)
				{
					(*StartIterMap).first->SetValue(GamePlayGobal::GetInst()->Find((*StartIterMap).second->ObjectName_), (*StartIterMap).second->Direction_);
					//ChangeUnit(static_cast<GamePlayUnitObject*>((*StartIterMap).first->GetUnitObjectInst()), 
					//	static_cast<GamePlayUnitObject*>(GamePlayGobal::GetInst()->Find((*StartIterMap).second->ObjectName_)));
				}
			}
			
			// 같은 위치가 아닐때
			if (!(const_cast<float4&>((*StartIterMap).first->GetPos()).CompareInt2D((*StartIterMap).second->Pos_)))
			{
				std::list<Coordinate*>::iterator StartIter = CurrentMap_[(*StartIterMap).first->GetPos().iy()][(*StartIterMap).first->GetPos().ix()].begin();
				std::list<Coordinate*>::iterator EndIter = CurrentMap_[(*StartIterMap).first->GetPos().iy()][(*StartIterMap).first->GetPos().ix()].end();
				while (StartIter != EndIter)
				{
					if ((*StartIter) == (*StartIterMap).first)
					{
						CurrentMap_[(*StartIterMap).first->GetPos().iy()][(*StartIterMap).first->GetPos().ix()].erase(MoveBack(StartIter, (*StartIterMap).second->Pos_, (*StartIterMap).second->Direction_));
						break;
					}
					++StartIter;
				}	
			}
			if ((*StartIterMap).first->IsUpdate() != (*StartIterMap).second->IsUpdate_)
			{
				(*StartIterMap).first->On();
			}
		}
		delete StartIterMap->second;
		++StartIterMap;
	}

	delete AllMoveHistory_.back();
	AllMoveHistory_.pop_back();
}

void PlayLevel::ScanFucntionAndBridgeUnit()
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
			std::list<Coordinate*>& Block = StartIterX->second;
			
			for (auto iter : Block)
			{
				if (iter->IsUpdate() == true)
				{

					if (iter->GetTextObjectInst()->GetTextType() == TextType::Verb_Text)
					{
						CheckFunction(X, Y, iter);
						continue;
					}	
					else if (iter->GetUnitObjectInst()->GetName() == ObjectName::Wall_Unit ||
							 iter->GetUnitObjectInst()->GetName() == ObjectName::Water_Unit ||
							 iter->GetUnitObjectInst()->GetName() == ObjectName::Lava_Unit  ||
							 iter->GetUnitObjectInst()->GetName() == ObjectName::Grass_Unit)
					{
						iter->SetBridgeUnit(CheckUnitBridge(iter));
					}
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
				if (iter->GetUnitObjectInst()->FindStat(SYou) == true && iter->IsUpdate() == true)
				{
					iter->Off();
				}
			}
		}
	}
	// Sink
	{
		if (_Value.size() > 1)
		{
			if (FindUnitByStat(_Value, SSink) == true)
			{
				for (auto iter : _Value)
				{
					if (iter->IsUpdate() == true)
					{
						iter->Off();
					}
				}
			}
		}
	}

	// Hot, Melt
	{
		if (FindUnitByStat(_Value, SHot) == true && FindUnitByStat(_Value, SMelt))
		{
			for (auto iter : _Value)
			{
				if (iter->GetUnitObjectInst()->FindStat(SYou) == true && iter->IsUpdate() == true)
				{
					iter->Off();
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
				if (iter->GetUnitObjectInst()->FindStat(SYou) == true && iter->IsUpdate() == true)
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
			if (iter->IsUpdate() == false)
			{
				continue;
			}
			return true;
		}
	}
	return false;
}

bool PlayLevel::IsMapOut(const std::pair<int, int>& _Pos)
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
	if (IsClear_ == true)
	{
		return false;
	}

	if (GameEngineInput::GetInst()->IsDown("Down"))
	{
		return PushKey(Direction::Down);
	}
	if (GameEngineInput::GetInst()->IsDown("Up"))
	{
		return PushKey(Direction::Up);
	}
	if (GameEngineInput::GetInst()->IsDown("Right"))
	{
		return PushKey(Direction::Right);
	}
	if (GameEngineInput::GetInst()->IsDown("Left"))
	{
		return PushKey(Direction::Left);
	}


	if (GameEngineInput::GetInst()->IsDown("Space"))
	{
		if (IsClear_ == true)
		{
			if (ClearWait < 4.0f)
			{
				GameEngine::GetInst().ChangeLevel("MainLevel");
			}
		}
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("R"))
	{
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("Z"))
	{
		BackTothePast();
		return true;
	}
	return false;
}


bool PlayLevel::PushKey(Direction _Dir)
{

	StageSave();
	StageFucntionReset();
	ScanFucntionAndBridgeUnit();
	switch (_Dir)
	{
	case Direction::Right:
		if (!(CheckMapAllStat(std::make_pair(1, 0))))
		{
			StageSavePopBack();
		}
		break;
	case Direction::Up:
		if (!(CheckMapAllStat(std::make_pair(0, -1))))
		{
			StageSavePopBack();
		}
		break;
	case Direction::Left:
		if (!(CheckMapAllStat(std::make_pair(-1, 0))))
		{
			StageSavePopBack();
		}
		break;
	case Direction::Down:
		if (!(CheckMapAllStat(std::make_pair(0, 1))))
		{
			StageSavePopBack();
		}
		break;
	default:
		break;
	}
	return true;
}

void PlayLevel::StageSavePopBack()
{
	if (AllMoveHistory_.size() <= 0)
	{
		return;
	}
	std::map< Coordinate*, const CooridnateHistoryData*>::iterator StartIterMap = AllMoveHistory_.back()->begin();
	std::map< Coordinate*, const CooridnateHistoryData*>::iterator EndIterMap = AllMoveHistory_.back()->end();
	while (StartIterMap != EndIterMap)
	{
		delete StartIterMap->second;
		++StartIterMap;
	}
	delete AllMoveHistory_.back();
	AllMoveHistory_.pop_back();
}
bool PlayLevel::CheckMapAllStat(const std::pair<int, int>& _MoveDir)
{
	bool IsMove = false;
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
				(*StartIterList)->KeyIsPushOn();
				if ((*StartIterList)->GetUnitObjectInst()->FindStat(SYou) == true && (*StartIterList)->IsUpdate() == true)
				{
					if ((*StartIterList)->IsMove() == false && CheckBitMove(X, Y, _MoveDir) == true)
					{
						IsMove = true;
						StartIterList = Ref.erase(Move(StartIterList, _MoveDir));
						continue;
					}
				}
				++StartIterList;
			}
		}
	}

	return IsMove;
}

bool PlayLevel::CheckBitMove(const int _x, const int _y, const std::pair<int, int>& _MoveDir)
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
			if (iter->GetUnitObjectInst()->FindStat(SStop) == true && iter->IsUpdate() == true)
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
			if ((*StartIterList)->GetUnitObjectInst()->FindStat(SPush) == true && (*StartIterList)->IsUpdate() == true)
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

// 일반적인 Move
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

std::list<Coordinate*>::iterator& PlayLevel::MoveBack(std::list<Coordinate*>::iterator& _ListIter, const float4& _MovePos, Direction _Dir)
{
	int X = _MovePos.ix();
	int Y = _MovePos.iy();

	(*_ListIter)->ChangeBackPos({ static_cast<float>(X), static_cast<float>(Y) },
	{ GameWindowStartPosX_ + static_cast<float>(X * DotSizeX), GameWindowStartPosY_ + static_cast<float>(Y * DotSizeY) },
	_Dir);

	CurrentMap_[Y][X].push_back(*_ListIter);

	return _ListIter;
}

void PlayLevel::ClearStage()
{
	IsClear_ = true;
	ClearWait = 5.0f;
	ClearScene_->On();
}


void PlayLevel::EndStage()
{
	AllReleaseInStage();

}

void PlayLevel::AllReleaseInStage()
{
	std::list<Coordinate*>::iterator StartIter = AllCoordinate_.begin();
	std::list<Coordinate*>::iterator EndIter = AllCoordinate_.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		if ((*StartIter) != nullptr)
		{
			(*StartIter)->Death();
			(*StartIter) = nullptr;
		}
	}
	AllCoordinate_.clear();

	std::vector<std::map< Coordinate*, const CooridnateHistoryData*>*>::iterator StartIterVector = AllMoveHistory_.begin();
	std::vector<std::map< Coordinate*, const CooridnateHistoryData*>*>::iterator EndIterVector = AllMoveHistory_.end();
	for (; StartIterVector != EndIterVector; ++StartIterVector)
	{
		std::map< Coordinate*, const CooridnateHistoryData*>::iterator StartIterMap = (*StartIterVector)->begin();
		std::map< Coordinate*, const CooridnateHistoryData*>::iterator EndIterMap = (*StartIterVector)->end();
		for (; StartIterMap != EndIterMap; ++StartIterMap)
		{
			if (StartIterMap->second != nullptr)
			{
				delete StartIterMap->second;
				StartIterMap->second = nullptr;
			}
		}
		(*StartIterVector)->clear();
		delete (*StartIterVector);
		(*StartIterVector) = nullptr;
	}
	AllMoveHistory_.clear();
	CurrentMap_.clear();
	// 재선언으로 비우기
	QueueMove_ = std::queue<Direction>();
}