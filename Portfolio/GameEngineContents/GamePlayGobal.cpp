#include "GamePlayGobal.h"
#include "GamePlayEnum.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "Baba.h"
#include "Flag.h"
#include "Glass.h"
#include "Lava.h"
#include "Rock.h"
#include "Skull.h"
#include "Wall.h"
#include "Water.h"
#include "Is_Text.h"
#include "Defeat_Text.h"
#include "Hot_Text.h"
#include "Melt_Text.h"
#include "Push_Text.h"
#include "Sink_Text.h"
#include "Stop_Text.h"
#include "Win_Text.h"
#include "You_Text.h"
#include "Tile.h"
#include "Default.h"
#include "Line.h"
#include "Text.h"
#include "Dummy_Text.h"
#include "Brick.h"
#include "Flower.h"

GamePlayGobal* GamePlayGobal::Inst_ = new GamePlayGobal();

bool GamePlayGobal::DisableScreenshake_ = false;
bool GamePlayGobal::EnableGrid_ = false;
bool GamePlayGobal::DisableParticleEffects_ = false;

GamePlayGobal::GamePlayGobal() 
{
}

GamePlayGobal::~GamePlayGobal() 
{
	std::map<ObjectName, GamePlayObject*>::iterator Startiter = ObjectName_.begin();
	std::map<ObjectName, GamePlayObject*>::iterator Enditer = ObjectName_.end();
	for (; Startiter != Enditer; ++Startiter)
	{
		if ((Startiter->second) != nullptr)
		{
			delete (Startiter->second);
			(Startiter->second) = nullptr;
		}
		
	}
}


GamePlayObject* GamePlayGobal::Find(const ObjectName _Name)
{
	return ObjectName_[_Name];
}


void  GamePlayGobal::SetName()
{
	if (ObjectName_[ObjectName::Baba_Unit] != nullptr)
	{
		MsgBoxAssert("GamePlayGobal : 이미 만들어진 Name입니다")
	}
		ObjectName_[ObjectName::Baba_Unit] =  Baba_Unit::GetInst();
		ObjectName_[ObjectName::Baba_Text] =	Baba_Text::GetInst();
		ObjectName_[ObjectName::Brick_Unit] = Brick_Unit::GetInst();
		ObjectName_[ObjectName::Brick_Text] = Brick_Text::GetInst();
		ObjectName_[ObjectName::Flag_Unit] =  Flag_Unit::GetInst();
		ObjectName_[ObjectName::Flag_Text] =	Flag_Text::GetInst();
		ObjectName_[ObjectName::Flower_Unit] = Flower_Unit::GetInst();
		ObjectName_[ObjectName::Grass_Unit] = Grass_Unit::GetInst();
		ObjectName_[ObjectName::Grass_Text] = Grass_Text::GetInst();
		ObjectName_[ObjectName::Lava_Unit] =  Lava_Unit::GetInst();
		ObjectName_[ObjectName::Lava_Text] =	Lava_Text::GetInst();
		ObjectName_[ObjectName::Rock_Unit] =  Rock_Unit::GetInst();
		ObjectName_[ObjectName::Rock_Text] =	Rock_Text::GetInst();
		ObjectName_[ObjectName::Skull_Unit] = Skull_Unit::GetInst();
		ObjectName_[ObjectName::Skull_Text] =	Skull_Text::GetInst();
		ObjectName_[ObjectName::Tile_Unit] =	Tile_Unit::GetInst();
		ObjectName_[ObjectName::Wall_Unit] =  Wall_Unit::GetInst();
		ObjectName_[ObjectName::Wall_Text] =	Wall_Text::GetInst();
		ObjectName_[ObjectName::Water_Unit] = Water_Unit::GetInst();
		ObjectName_[ObjectName::Water_Text] =	Water_Text::GetInst();
		ObjectName_[ObjectName::Is_Text] =		Is_Text::GetInst();
		ObjectName_[ObjectName::Defeat_Text] =	Defeat_Text::GetInst();
		ObjectName_[ObjectName::Hot_Text] =		Hot_Text::GetInst();
		ObjectName_[ObjectName::Melt_Text] =	Melt_Text::GetInst();
		ObjectName_[ObjectName::Push_Text] =	Push_Text::GetInst();
		ObjectName_[ObjectName::Sink_Text] =	Sink_Text::GetInst();
		ObjectName_[ObjectName::Stop_Text] =	Stop_Text::GetInst();
		ObjectName_[ObjectName::Win_Text] =		Win_Text::GetInst();
		ObjectName_[ObjectName::You_Text] =		You_Text::GetInst();
		ObjectName_[ObjectName::Default]  =		Default::GetInst();
		ObjectName_[ObjectName::Line] =			Line::GetInst();
		ObjectName_[ObjectName::Text_Unit] = Text_Unit::GetInst();
		ObjectName_[ObjectName::Dummy_Text] = Dummy_Text::GetInst();
		SettingAbility();
}

void GamePlayGobal::ReSetStat()
{
	std::map<ObjectName, GamePlayObject*>::iterator StartIter = ObjectName_.begin();
	std::map<ObjectName, GamePlayObject*>::iterator EndIter = ObjectName_.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		GamePlayObject* SecondInst = StartIter->second;
		if (SecondInst != nullptr && 
			StartIter->first != ObjectName::Line &&
			StartIter->first != ObjectName::Default &&
			SecondInst->GetType() != ObjectType::Text)
		{
			static_cast<GamePlayUnitObject*>(SecondInst)->Reset();
			continue;
		}

		//if (SecondInst != nullptr && SecondInst->GetName() == ObjectName::Text_Unit)
		//{
		//	static_cast<GamePlayUnitObject*>(SecondInst)->Reset();
		//}
	}
	static_cast<GamePlayUnitObject*>(ObjectName_[ObjectName::Text_Unit])->Reset();
}

void GamePlayGobal::SettingAbility()
{
	std::map<ObjectName, GamePlayObject*>::iterator StartIter = ObjectName_.begin();
	std::map<ObjectName, GamePlayObject*>::iterator EndIter = ObjectName_.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		if (StartIter->second != nullptr)
		{
			(StartIter->second)->SettingAbility();
		}
	}
}

void  GamePlayGobal::DestroyName()
{
	std::map<ObjectName, GamePlayObject*>::iterator StartIter = ObjectName_.begin();
	std::map<ObjectName, GamePlayObject*>::iterator EndIter = ObjectName_.end();

	for (; StartIter != EndIter ; ++StartIter)
	{
		if (StartIter->second != nullptr)
		{
			(StartIter->second)->Destroy();
			(StartIter->second) = nullptr;
		}

	}
}


