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
	BackGround_(nullptr),
	Random_(nullptr),
	Fade_(nullptr),
	IsReset_(false),
	PlayLevelEffectManager_(nullptr),
	VolumeManager_(nullptr),
	IsOver_(false)
{
}

PlayLevel::~PlayLevel() 
{
	EndStage();
}


void PlayLevel::Loading()
{
	{
		Fade_ = CreateActor<Fade_InAndOut>(10);
		Fade_->Reset();
	}
	{
		VolumeManager_ = CreateActor<SoundVolumeManager>(0);
	}
	PlayLevelEffectManager_ = CreateActor<EffectManager>(7);
	CreateActor<BackGround>(0);
	ClearScene_ = CreateActor<ClearScene>(5);
	AllMoveHistory_.reserve(10000);

}

void PlayLevel::Update()
{
	if (IsReset_ == true && Fade_->IsChangeScreen() == false)
	{
		if (Fade_->IsFadeOut() == true)
		{
			{
				AllReleaseInStage();
				ReSetStage();
				SetStage();
				AfterMove();
			}
			Fade_->ShowFadeIn();
			return;
		}
	}
	if (Fade_->IsFadeOut() == true && Fade_->IsChangeScreen() == false && IsClear_ == true)
	{
		GameEngine::GetInst().ChangeLevel("MainLevel");
		return;
	}
	if (Fade_->IsChangeScreen() == true)
	{
		return;
	}
	if (true == KeyCheck())
	{
		AfterMove();
	}

	if (IsClear_ == true)
	{
		ClearWait -= GameEngineTime::GetDeltaTime();
		if (ClearWait < 0)
		{
			Fade_->ShowFadeOut();
		}
	}

}

void PlayLevel::LevelChangeEnd()
{
	Fade_->Reset();
	EndStage();
	ReSetStage();
	CurrentStage_ = Stage::MainStage;
	ClearScene_->SetStayOFF();
}
void PlayLevel::LevelChangeStart()
{
	GameEngineSound::Update();
	BackGroundMusicControl_ = GameEngineSound::SoundPlayControl("baba.ogg");
	Fade_->ShowFadeIn();
	SetStage();
	StageFucntionReset();

	ScanFucntion();
	CheckMapAllStat();
	ScanBridgeUnit();

}

void PlayLevel::AfterMove()
{
	StageFucntionReset();
	ScanFucntion();
	CheckMapAllStat();
	ScanBridgeUnit();
	if (IsReset_ == false && CanMove() == false)
	{
		GameOver();
	}
	
}


bool PlayLevel::CanMove()
{
	for (auto Iter : AllCoordinate_)
	{
		if (Iter->GetUnitObjectInst()->FindStat(SYou) == true && Iter->IsUnitUpdate() == true)
		{
			return true;
		}
	}
	return false;
}

void PlayLevel::GameOver()
{
	IsOver_ = true;
	BackGroundMusicControl_.SetVolume(0.0f);
	BackGroundNoiseControl_ = GameEngineSound::SoundPlayControl("noise.ogg");
}

void PlayLevel::ScanBridgeUnit()
{
	// 비트 체크할때 하나의 비트 변수를 만들어서 삽입해야하는데 좀 부족했음
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
				if (iter->IsUnitUpdate() == true)
				{
					if (iter->GetUnitObjectInst()->GetName() == ObjectName::Wall_Unit ||
						iter->GetUnitObjectInst()->GetName() == ObjectName::Water_Unit ||
						iter->GetUnitObjectInst()->GetName() == ObjectName::Lava_Unit ||
						iter->GetUnitObjectInst()->GetName() == ObjectName::Grass_Unit ||
						iter->GetUnitObjectInst()->GetName() == ObjectName::Brick_Unit)
					{
						iter->SetBridgeUnit(CheckUnitBridge(iter));
					}
				}

			}
		}
	}
}


void PlayLevel::SetStage()
{
	Random_ = new GameEngineRandom();
	CurrentStage_ = MainLevel::GetCurrentStage();
	MapScale_ = StageData::Inst_->Scale_[CurrentStage_];
	BackGround_ = CreateActor<PlayBackGround>(1);
	BackGround_->CreateRendererToScale("Stage0.bmp", { MapScale_.x * DotSizeX, MapScale_.y * DotSizeY });
	GameWindowStartPosX_ = (GameEngineWindow::GetScale().x - MapScale_.x * DotSizeX) / 2;
	GameWindowStartPosY_ = (GameEngineWindow::GetScale().y - MapScale_.y * DotSizeY) / 2;
	CreatMap(StageData::Inst_->StageData_[CurrentStage_]);
}

void PlayLevel::ReSetStage()
{
	GameEngineSound::Update();
	GameWindowStartPosX_ = 0;
	GameWindowStartPosY_ = 0;
	CurrentStage_ = Stage::MainStage;
	IsClear_ = (false);
	ClearWait = (0.0f);
	IsClear_ = false;
	IsReset_ = false;
	IsOver_ = false;
	AllCoordinate_.clear();
	AllMoveHistory_.clear();
	CurrentMap_.clear();
	// 재선언으로 비우기
	QueueMove_ = std::queue<Direction>();

	ClearScene_->Off();
	BackGround_->Death();
	BackGround_ = nullptr;
}

unsigned int PlayLevel::CheckUnitBridge(const Coordinate* _Unit)
{
	int X = _Unit->GetPos().ix();
	int Y = _Unit->GetPos().iy();
	unsigned int Idx = 0;

	{
		if (FindUnitObject(CurrentMap_[Y + 1][X], _Unit->GetUnitObjectInst()->GetName()) != nullptr || IsMapOut(std::make_pair(X, Y + 1)) == true)
		{
			Idx += 1;
		}
	}

	{
		if (FindUnitObject(CurrentMap_[Y][X  - 1], _Unit->GetUnitObjectInst()->GetName()) != nullptr || IsMapOut(std::make_pair(X - 1, Y)) == true)
		{
			Idx += 2;
		}
	}
	
	{
		if (FindUnitObject(CurrentMap_[Y][X + 1], _Unit->GetUnitObjectInst()->GetName()) != nullptr || IsMapOut(std::make_pair(X + 1, Y)) == true)
		{
			Idx += 4;
		}
	}

	{
		if (FindUnitObject(CurrentMap_[Y - 1][X], _Unit->GetUnitObjectInst()->GetName()) != nullptr || IsMapOut(std::make_pair(X, Y - 1)) == true)
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
		if ((*StartIter)->IsUnitUpdate() == true)
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
					if (iter->GetUnitObjectInst()->GetName() == ObjectName::Rock_Unit)
					{
						int a = 0;
					}
					
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
			else if ((*StartIterMap).first->GetDir() != (*StartIterMap).second->Direction_)
			{
				(*StartIterMap).first->ChangeBackDir((*StartIterMap).second->Direction_);
			}
			if ((*StartIterMap).first->IsUnitUpdate() != (*StartIterMap).second->IsUpdate_)
			{
				(*StartIterMap).first->UpdateON();
			}
		}
		delete StartIterMap->second;
		++StartIterMap;
	}

	delete AllMoveHistory_.back();
	AllMoveHistory_.pop_back();
	PlaySoundBack();
}


void PlayLevel::ScanFucntion()
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
				if (iter->IsUnitUpdate() == true)
				{

					if (iter->GetTextObjectInst()->GetTextType() == TextType::Verb_Text)
					{
						CheckFunction(X, Y, iter);
						continue;
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
		if (ChangeUnit(static_cast<GamePlayUnitText*>(_Unit->GetTextObjectInst())->GetTextUnit(), static_cast<GamePlayUnitText*>(_Stat->GetTextObjectInst())->GetTextUnit()) == true)
		{
			PlaySoundChange();
		}
	
	}
}

bool PlayLevel::ChangeUnit(const GamePlayUnitObject* _Left, GamePlayUnitObject* _Right)
{
	bool IsChange = false;
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
					IsChange = true;
				}
			}
		}
	}
	return IsChange;
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
	bool IsDefeat = false;
	bool IsSink = false;
	bool IsMelt = false;
	// Defeat
	{

		if (FindUnitByStat(_Value, SDefeat) != nullptr && FindUnitByStat(_Value, SDefeat) != nullptr)
		{
			for (auto iter : _Value)
			{
				if (iter->GetUnitObjectInst()->FindStat(SYou) == true && iter->IsUnitUpdate() == true)
				{
					iter->UpdateOFF();
					IsDefeat = true;
					PlayLevelEffectManager_->ShowEffect(iter->GetLUPos(), GameEngineImageManager::GetInst()->Find("Defeat_Effect_sheet.bmp"), Random_, 4, 7);
				}
			}
		}
	}
	// Sink
	{
		if (_Value.size() > 1)
		{
			if (FindUnitByStat(_Value, SSink) != nullptr)
			{
				for (auto iter : _Value)
				{
					if (iter->IsUnitUpdate() == true)
					{
						iter->UpdateOFF();
						IsSink = true;
						PlayLevelEffectManager_->ShowEffect(iter->GetLUPos(), GameEngineImageManager::GetInst()->Find("Sink_Effect_sheet.bmp"), Random_, 4, 7);
					}
				}
			}
		}
	}

	// Hot, Melt
	{
		if (FindUnitByStat(_Value, SHot) != nullptr && FindUnitByStat(_Value, SMelt) != nullptr)
		{
			for (auto iter : _Value)
			{
				if (iter->GetUnitObjectInst()->FindStat(SYou) == true && iter->IsUnitUpdate() == true)
				{
					iter->UpdateOFF();
					IsMelt = true;
					PlayLevelEffectManager_->ShowEffect(iter->GetLUPos(), GameEngineImageManager::GetInst()->Find("Hot_Effect_sheet.bmp"), Random_, 3, 5);
				}
			}
		}
	}
	// Win
	{
		Coordinate* WinObject = FindUnitByStat(_Value, SWin);
		if (WinObject != nullptr)
		{
			if (FindUnitByStat(_Value, SYou) != nullptr)
			{
				for (auto iter : _Value)
				{
					if (iter->GetUnitObjectInst()->FindStat(SYou) == true && iter->IsUnitUpdate() == true)
					{
						ClearStage();
					}
				}
			}
		}
	}

	if (IsDefeat == true)
	{
		PlaySoundDefeat();
	}
	if (IsSink == true)
	{
		PlaySoundSink();
	}
	if (IsMelt == true)
	{
		PlaySoundMelt();
	}
}

void PlayLevel::ShowCrashEffect(const float4 _LUPos, const unsigned __int64& _Stat)
{


}

Coordinate* PlayLevel::FindUnitByStat(std::list<Coordinate*>& _Value, unsigned __int64 _Stat)
{
	for (auto iter : _Value)
	{
		if ((iter->GetUnitObjectInst()->GetAllStat() & _Stat) == _Stat)
		{
			if (iter->IsUnitUpdate() == false)
			{
				continue;
			}
			return iter;
		}
	}
	return nullptr;
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
		//if (IsClear_ == true)
		//{
		//	if (ClearWait < 1.0f)
		//	{
		//		GameEngine::GetInst().ChangeLevel("MainLevel");
		//	}
		//}
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("R"))
	{
		if (IsOver_ == true)
		{
			GameEngineSound::Update();
			BackGroundNoiseControl_.Stop();
			BackGroundMusicControl_.SetVolume(1.0f);
			IsOver_ = false;
		}
		IsReset_ = true;
		GameEngineSound::SoundPlayOneShot("Retrun.ogg");
		Fade_->ShowFadeOut();
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("Z"))
	{
		if (IsOver_ == true)
		{
			GameEngineSound::Update();
			BackGroundNoiseControl_.Stop();
			BackGroundMusicControl_.SetVolume(1.0f);
			IsOver_ = false;
		}
		BackTothePast();
		return true;
	}
	return false;
}

bool PlayLevel::PushKey(Direction _Dir)
{
	StageSave();
	StageFucntionReset();
	ScanFucntion();
	ScanBridgeUnit();

	if (CheckMapAllStat(_Dir) == false)
	{
		StageSavePopBack();
		return false;
	}
	else
	{
		PlaySoundMove();
		return true;
	}
}
void PlayLevel::PlaySoundBack()
{
	switch (Random_->RandomInt(0, 4))
	{
	case 0:
		GameEngineSound::SoundPlayOneShot("Back1.ogg");
		break;
	case 1:
		GameEngineSound::SoundPlayOneShot("Back2.ogg");
		break;
	case 2:
		GameEngineSound::SoundPlayOneShot("Back3.ogg");
		break;
	case 3:
		GameEngineSound::SoundPlayOneShot("Back4.ogg");
		break;
	case 4:
		GameEngineSound::SoundPlayOneShot("Back5.ogg");
		break;
	default:
		break;
	}
}
void PlayLevel::PlaySoundMove()
{
	switch (Random_->RandomInt(0, 11))
	{
	case 0:
		GameEngineSound::SoundPlayOneShot("move1.ogg");
		break;
	case 1:
		GameEngineSound::SoundPlayOneShot("move2.ogg");
		break;
	case 2:
		GameEngineSound::SoundPlayOneShot("move3.ogg");
		break;
	case 3:
		GameEngineSound::SoundPlayOneShot("move4.ogg");
		break;
	case 4:
		GameEngineSound::SoundPlayOneShot("move5.ogg");
		break;
	case 5:
		GameEngineSound::SoundPlayOneShot("move6.ogg");
		break;
	case 6:
		GameEngineSound::SoundPlayOneShot("move7.ogg");
		break;
	case 7:
		GameEngineSound::SoundPlayOneShot("move8.ogg");
		break;
	case 8:
		GameEngineSound::SoundPlayOneShot("move9.ogg");
		break;
	case 9:
		GameEngineSound::SoundPlayOneShot("move10.ogg");
		break;
	case 10:
		GameEngineSound::SoundPlayOneShot("move11.ogg");
		break;
	case 11:
		GameEngineSound::SoundPlayOneShot("move12.ogg");
		break;
	default:
		break;
	}

}
void PlayLevel::PlaySoundSink()
{
	switch (Random_->RandomInt(0, 3))
	{
	case 0:
		GameEngineSound::SoundPlayOneShot("Sink.ogg");
		break;
	case 1:
		GameEngineSound::SoundPlayOneShot("Sink2.ogg");
		break;
	case 2:
		GameEngineSound::SoundPlayOneShot("Sink3.ogg");
		break;
	case 3:
		GameEngineSound::SoundPlayOneShot("Sink4.ogg");
		break;
	default:
		break;
	}
}
void PlayLevel::PlaySoundDefeat()
{
	switch (Random_->RandomInt(0, 3))
	{
	case 0:
		GameEngineSound::SoundPlayOneShot("defeat.ogg");
		break;
	case 1:
		GameEngineSound::SoundPlayOneShot("defeat2.ogg");
		break;
	case 2:
		GameEngineSound::SoundPlayOneShot("defeat3.ogg");
		break;
	case 3:
		GameEngineSound::SoundPlayOneShot("defeat4.ogg");
		break;
	default:
		break;
	}
}
void PlayLevel::PlaySoundMelt()
{
	switch (Random_->RandomInt(0, 1))
	{
	case 0:
		GameEngineSound::SoundPlayOneShot("melt1.ogg");
		break;
	case 1:
		GameEngineSound::SoundPlayOneShot("melt2.ogg");
		break;
	default:
		break;
	}
}
void PlayLevel::PlaySoundChange()
{
	switch (Random_->RandomInt(0, 5))
	{
	case 0:
		GameEngineSound::SoundPlayOneShot("change1.ogg");
		break;
	case 1:
		GameEngineSound::SoundPlayOneShot("change2.ogg");
		break;
	case 2:
		GameEngineSound::SoundPlayOneShot("change3.ogg");
		break;
	case 3:
		GameEngineSound::SoundPlayOneShot("change4.ogg");
		break;
	case 4:
		GameEngineSound::SoundPlayOneShot("change5.ogg");
		break;
	default:
		break;
	}
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
bool PlayLevel::CheckMapAllStat(Direction _MoveDir)
{
	std::pair<int, int> DirInt;
	switch (_MoveDir)
	{
	case Direction::Right:
		DirInt = std::make_pair(1, 0);
		break;
	case Direction::Up:
		DirInt = std::make_pair(0, -1);
		break;
	case Direction::Left:
		DirInt = std::make_pair(-1, 0);
		break;
	case Direction::Down:
		DirInt = std::make_pair(0, 1);
		break;
	}
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
				if ((*StartIterList)->GetUnitObjectInst()->FindStat(SYou) == true && (*StartIterList)->IsUnitUpdate() == true)
				{
					if ((*StartIterList)->IsMove() == false)
					{
						if ((*StartIterList)->GetDir() != _MoveDir)
						{
							(*StartIterList)->ChangeDir(_MoveDir);
							IsMove = true;
						}
						if ( CheckBitMove(X, Y, DirInt) == true)
						{
							IsMove = true;
							StartIterList = Ref.erase(Move(StartIterList, DirInt));
							continue;
						}

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
			if (iter->GetUnitObjectInst()->FindStat(SStop) == true && iter->IsUnitUpdate() == true)
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
			if ((*StartIterList)->GetUnitObjectInst()->FindStat(SPush) == true && (*StartIterList)->IsUnitUpdate() == true)
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
	GameEngineSound::SoundPlayOneShot("Clear.ogg");
	BackGroundMusicControl_.Stop();
	IsClear_ = true;
	ClearWait = 3.0f;
	ClearScene_->On();
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

void PlayLevel::EndStage()
{
	AllReleaseInStage();

}

void PlayLevel::AllReleaseInStage()
{
	if (nullptr != Random_)
	{
		delete Random_;
		Random_ = nullptr;
	}

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