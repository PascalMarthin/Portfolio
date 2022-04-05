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
			CurrentMap_[y][x].reserve(MapScale_.x + MapScale_.y);
			GamePlayObject* Value = (GamePlayGobal::GetInst()->Find(_Stage[y][x]));
			if (Value == nullptr)
			{
			continue;
			}
			Coordinate* Coordi = CreateActor<Coordinate>(1);
			Coordi->SetPos({ static_cast<float>(x), static_cast<float>(y) }, { GameWindowStartPosX_ + static_cast<float>(x * DotSizeX), GameWindowStartPosY_ + static_cast<float>(y * DotSizeY) });
			Coordi->SetBaseValue(Value, (Value->GetType()));
			CurrentMap_[y][x].push_back(Coordi);
		}
	}
}

void PlayLevel::ScanFucntion()
{
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();


	int X = 0;
	int Y = 0;

	for (; StartIterY != EndIterY; ++StartIterY)
	{
		Y = StartIterY->first;
		std::map<int, std::vector<Coordinate*>>::iterator StartIterX = StartIterY->second.begin();
		std::map<int, std::vector<Coordinate*>>::iterator EndIterX = StartIterY->second.end();
		for (; StartIterX != EndIterX; ++StartIterX)
		{
			X = StartIterX->first;
			std::vector <Coordinate*>& Block = StartIterX->second;

			for (size_t i = 0; i < Block.size(); i++)
			{
				if (Block[i] == nullptr)
				{
					MsgBoxAssert("Block이 nullptr, 근데 왜 null이지?");
				}

				if ((Block[i]->GetUnitObjectInst())->GetTextType() == TextType::Verb_Text)
				{
					if (Y > 0 && Y < MapScale_.iy() - 1)
					{
						for (int j = 0; j < CurrentMap_[Y - 1][X].size(); j++)
						{

							if ((CurrentMap_[Y - 1][X][j]->GetUnitObjectInst())->GetTextType() == TextType::Unit_Text)
							{
								for (int k = 0; k < CurrentMap_[Y + 1][X].size(); k++)
								{
									if ((CurrentMap_[Y + 1][X][k]->GetUnitObjectInst())->GetTextType() == TextType::Stat_Text || (CurrentMap_[Y + 1][X][k]->GetUnitObjectInst())->GetTextType() == TextType::Unit_Text)
									{
										// y 완성
										ApplyObjectFuction(CurrentMap_[Y - 1][X][j], Block[i], CurrentMap_[Y + 1][X][k]);
										break;
									}

								}
								break;
							}
						}

					}

					if (X > 0 && X < MapScale_.ix() - 1)
					{
						for (int j = 0; j < CurrentMap_[Y][X - 1].size(); j++)
						{
							if ((CurrentMap_[Y][X - 1][j]->GetUnitObjectInst())->GetTextType() == TextType::Unit_Text)
							{
								for (int k = 0; k < CurrentMap_[Y][X + 1].size(); k++)
								{
									if ((CurrentMap_[Y][X + 1][k]->GetUnitObjectInst())->GetTextType() == TextType::Stat_Text || (CurrentMap_[Y][X + 1][k]->GetUnitObjectInst())->GetTextType() == TextType::Unit_Text)
									{
										// x 완성
										ApplyObjectFuction(CurrentMap_[Y][X - 1][j], Block[i], CurrentMap_[Y][X + 1][k]);
										break;
									}

								}
								break;
							}
						}
					}
				}
			}
		}
	}
}



void PlayLevel::ApplyObjectFuction(Coordinate* _Unit, Coordinate* _Verb, Coordinate* _Stat)
{
	_Unit->SetON();
	_Verb->SetON();
	_Stat->SetON();

	if (_Stat->GetType() == ObjectType::Text)
	{
		//다운캐스팅
		(_Unit->GetUnitObjectInst())->ApplyStat(static_cast<GamePlayTextStat*>(_Stat->GetTextObjectInst()));
	}

	if (_Stat->GetType() == ObjectType::Unit)
	{
		ChangeUnit((_Unit->GetUnitObjectInst()), (_Stat->GetUnitObjectInst()));
	}
}

void PlayLevel::ChangeUnit(const GamePlayObject* _Left, GamePlayObject* _Right)
{
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();

	for (; StartIterY != EndIterY; ++StartIterY)
	{
		std::map<int, std::vector<Coordinate*>>::iterator StartIterX = StartIterY->second.begin();
		std::map<int, std::vector<Coordinate*>>::iterator EndIterX = StartIterY->second.end();
		for (; StartIterX != EndIterX; ++StartIterX)
		{
			std::vector <Coordinate*>& Block = StartIterX->second;
			for (size_t i = 0; i < Block.size(); i++)
			{
				if (Block[i]->GetUnitObjectInst() == _Left)
				{
					Block[i]->SetBaseValue(_Right);
				}
			}
		}
	}
}

void PlayLevel::CheckMapAllStat()
{
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();

	for (; StartIterY != EndIterY; ++StartIterY)
	{
		std::map<int, std::vector<Coordinate*>>::iterator StartIterX = StartIterY->second.begin();
		std::map<int, std::vector<Coordinate*>>::iterator EndIterX = StartIterY->second.end();
		for (; StartIterX != EndIterX; ++StartIterX)
		{
			CheckBitStat(StartIterX->second);
		}
	}
}

void PlayLevel::CheckBitStat(std::vector<Coordinate*>& _Value)
{
	std::vector<Coordinate*>* KillUnitList = nullptr;
	// Defeat
	{
		Coordinate* UnitStatDefeat = FindUnitByStat(_Value, SDefeat);
		if (UnitStatDefeat != nullptr)
		{
			KillUnitList = FindUnitByStatVector(_Value, SYou);
			for (auto iter : *KillUnitList)
			{
				iter->Death();
			}
			delete KillUnitList;
			KillUnitList = nullptr;
		}
	}
	// Sink
	{
		Coordinate* UnitYou = FindUnitByStat(_Value, SSink);
		if (UnitYou != nullptr)
		{
			for (auto iter : _Value)
			{
				iter->Death();
			}
		}
	}

	// Hot, Melt
	{
		Coordinate* UnitYou = FindUnitByStat(_Value, SHot);
		if (UnitYou != nullptr)
		{
			KillUnitList = FindUnitByStatVector(_Value, SMelt);
			for (auto iter : *KillUnitList)
			{
				iter->Death();
			}
			delete KillUnitList;
			KillUnitList = nullptr;
		}
	}
}

void PlayLevel::Move(int _X, int _Y)
{

	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();

	int X = 0;
	int Y = 0;

	for (; StartIterY != EndIterY; ++StartIterY)
	{
		Y = StartIterY->first;
		std::map<int, std::vector<Coordinate*>>::iterator StartIterX = StartIterY->second.begin();
		std::map<int, std::vector<Coordinate*>>::iterator EndIterX = StartIterY->second.end();
		for (; StartIterX != EndIterX; ++StartIterX)
		{
			X = StartIterX->first;
				//들어왔으면 방향전환이라도 되어야한다
			if (FindUnitByStat(StartIterX->second, SYou) != nullptr)
			{

					if (CheckBitMove(CurrentMap_[Y+_Y][X+_X], _X , _Y) == true && IsMapOut(Y + _Y, X + _X) == false)
					{
						std::vector<Coordinate*>* YouList = FindUnitByStatVector(StartIterX->second, SYou);
						while (YouList != nullptr)
						{
							YouList.

						}
							

					}
			}
		}
	}
}
bool PlayLevel::IsMapOut(int _X, int _Y)
{
	if (MapScale_.ix() <= _X || _X <= 0)
	{
		return true;
	}
	if (MapScale_.iy() <= _Y || _Y <= 0)
	{
		return true;
	}
	return false;
}

bool PlayLevel::CheckBitMove(std::vector<Coordinate*>& _Value, int _X, int _Y)
{
	if (_Value.size() <= 0)
	{
		return true;
	}
	else
	{
		FindUnitByStat(_Value, SStop);
	}
}

Coordinate* PlayLevel::FindUnitByStat(std::vector<Coordinate*>& _Value, unsigned __int64 _Stat)
{
	for (auto iter : _Value)
	{
		if ((static_cast<GamePlayUnitObject*>((*iter).GetUnitObjectInst())->GetAllStat() & _Stat) == _Stat)
		{
			if ((*iter).IsDeath() == false)
			{
				return iter;
			}
			else
			{
				continue;
			}
		}
	}
	
	return nullptr;

}


std::vector<Coordinate*>* PlayLevel::FindUnitByStatVector(std::vector<Coordinate*>& _Value, unsigned __int64 _Stat)
{
	std::vector<Coordinate*>* Data = new std::vector<Coordinate*>;
	for (auto iter : _Value)
	{
		if ((static_cast<GamePlayUnitObject*>((*iter).GetUnitObjectInst())->GetAllStat() & _Stat) == _Stat)
		{
			if ((*iter).IsDeath() == false)
			{
				Data->push_back(iter);
			}
			else
			{
				continue;
			}
		}
	}
	if (Data->size() == 0)
	{
		delete Data;
		return nullptr;
	}
	else
	{
		return Data;
	}
	
}

bool PlayLevel::KeyCheck()
{
	if (GameEngineInput::GetInst()->IsDown("Down"))
	{
		Move(Direction::Down);
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("Up"))
	{
		Move(Direction::Up);
		return true;
	}

	if (GameEngineInput::GetInst()->IsDown("Right"))
	{
		Move(Direction::Right);
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("Left"))
	{
		Move(Direction::Left);
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


void PlayLevel::EndStage()
{
	ReleaseActor();

}

void PlayLevel::ReleaseActor()
{
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator StartIter = CurrentMap_.begin();
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator EndIter = CurrentMap_.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		std::map<int, std::vector<Coordinate*>>::iterator StartCoord = (StartIter->second).begin();
		std::map<int, std::vector<Coordinate*>>::iterator EndCoord = (StartIter->second).end();
		for (; StartCoord != EndCoord; ++StartCoord)
		{
			std::vector<Coordinate*>::iterator StartVector = (StartCoord->second).begin();
			std::vector<Coordinate*>::iterator EndVector = (StartCoord->second).end();
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