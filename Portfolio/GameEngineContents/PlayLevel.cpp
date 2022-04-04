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

}


void PlayLevel::CreatMap(std::map<int, std::map<int, ObjectName>>& _Stage)
{
	for (int y = 0; y < MapScale_.iy(); ++y)
	{
		for (int x = 0; x < MapScale_.ix(); ++x)
		{
			GamePlayObject* Idx = (GamePlayGobal::GetInst()->Find(_Stage[y][x]));
			if (Idx == nullptr)
			{
			continue;
			}
			Coordinate* Coordi = CreateActor<Coordinate>(1);
			Coordi->SetPos({ static_cast<float>(x), static_cast<float>(y) }, { GameWindowStartPosX_ + static_cast<float>(x * DotSizeX), GameWindowStartPosY_ + static_cast<float>(y * DotSizeY) });
			Coordi->SetBaseValue(Idx);
			CurrentMap_[y][x].push_back(Coordi);
		}
	}
}

void PlayLevel::ScanFucntion()
{
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();

	//std::pair<int, int> IsXTextReady = std::make_pair(0, false);
	//std::vector<std::pair<int, int>*> TextUnitLocation;

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

				if ((Block[i]->GetObjectInst())->GetTextType() == TextType::Verb_Text)
				{
					if (Y > 0 && Y < MapScale_.iy() - 1)
					{
						for (int j = 0; j < CurrentMap_[Y - 1][X].size(); j++)
						{

							if ((CurrentMap_[Y - 1][X][j]->GetObjectInst())->GetTextType() == TextType::Unit_Text)
							{
								for (int k = 0; k < CurrentMap_[Y + 1][X].size(); k++)
								{
									if ((CurrentMap_[Y + 1][X][k]->GetObjectInst())->GetTextType() == TextType::Stat_Text || (CurrentMap_[Y + 1][X][k]->GetObjectInst())->GetTextType() == TextType::Unit_Text)
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
							if ((CurrentMap_[Y][X - 1][j]->GetObjectInst())->GetTextType() == TextType::Unit_Text)
							{
								for (int k = 0; k < CurrentMap_[Y][X + 1].size(); k++)
								{
									if ((CurrentMap_[Y][X + 1][k]->GetObjectInst())->GetTextType() == TextType::Stat_Text || (CurrentMap_[Y][X + 1][k]->GetObjectInst())->GetTextType() == TextType::Unit_Text)
									{
										// x 완성 SetON()
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

	if (_Stat->GetObjectInst()->GetType() == ObjectType::Text)
	{
		//다운캐스팅 및 업캐스팅
		
		((GamePlayUnitObject*)(_Unit->GetObjectInst()))->ApplyStat((GamePlayTextStat*)(_Stat->GetObjectInst()));
	}

	if (_Stat->GetObjectInst()->GetType() == ObjectType::Unit)
	{
		ChangeUnit((_Unit->GetObjectInst()), (_Stat->GetObjectInst()));
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
				if (Block[i]->GetObjectInst() == _Left)
				{
					Block[i]->SetBaseValue(_Right);
				}
			}
		}
	}
}

//you, stop push는 검사 X
void PlayLevel::CheckStat()
{
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator StartIterY = CurrentMap_.begin();
	std::map<int, std::map<int, std::vector<Coordinate*>>>::iterator EndIterY = CurrentMap_.end();

	for (; StartIterY != EndIterY; ++StartIterY)
	{
		std::map<int, std::vector<Coordinate*>>::iterator StartIterX = StartIterY->second.begin();
		std::map<int, std::vector<Coordinate*>>::iterator EndIterX = StartIterY->second.end();
		for (; StartIterX != EndIterX; ++StartIterX)
		{

			CheckBit(StartIterX->second);


		}
	}
}
Coordinate* PlayLevel::FindUnitByStat(std::vector<Coordinate*>& _Value, unsigned __int64 _Stat)
{
	for (auto iter : _Value)
	{
		if ((static_cast<GamePlayUnitObject*>((*iter).GetObjectInst())->GetAllStat() & _Stat) == _Stat)
		{
			if (/*iter death() */ )
			{

			}
		}

		
		
	}
}

void PlayLevel::CheckBit(std::vector<Coordinate*>& _Value)
{
	unsigned __int64 PastIdx = 0;
	unsigned __int64 CurrentIdx = 0;
	DWORD dwFlag = 0;
	for (size_t i = 0; i < _Value.size(); i++)
	{
		dwFlag |= ((GamePlayUnitObject*)(_Value[i]->GetObjectInst()))->GetAllStat();
		((GamePlayUnitObject*)(_Value[i]->GetObjectInst()))->Find(SHot);
		//if (_Value[i]->GetObjectInst()->GetType() == ObjectType::Text)
		//{
		//	// 차후 제작
		//	continue;
		//}

		//CurrentIdx += ((GamePlayUnitObject*)(_Value[i]->GetObjectInst()))->GetAllStat();
		//{
		//	// 우선 순위에 따른 배열
		//	if ((CurrentIdx & (SDefeat+SYou)) == (SDefeat + SYou))
		//	{
		//		for (int j = 0; j < i; j++)
		//		{
		//			if (((GamePlayUnitObject*)(_Value[j]->GetObjectInst()))->Find(SYou) == true)
		//			{

		//			}
		//			
		//		}

		//	}
		//}



		//PastIdx = CurrentIdx;
	}
	/*if (BaseValue->GetAllStat() != Idx)
	{

	}*/

	if ((dwFlag & SHot) && (dwFlag & SMelt))
	{

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

void PlayLevel::Move(Direction _Dir)
{

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