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

GamePlayGobal* GamePlayGobal::Inst_ = new GamePlayGobal();

GamePlayGobal::GamePlayGobal() 
{
	SetName();
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


GamePlayObject* GamePlayGobal::Find(ObjectName _Name)
{
	return ObjectName_[_Name];
}


void  GamePlayGobal::SetName()
{
	if (ObjectName_[ObjectName::Baba_Object] != nullptr)
	{
		MsgBoxAssert("GamePlayGobal : 이미 만들어진 Name입니다")
	}
		ObjectName_[ObjectName::Baba_Object] =  new Baba_Unit();
		ObjectName_[ObjectName::Baba_Text] =	new Baba_Text();
		ObjectName_[ObjectName::Flag_Object] =  new Flag_Unit();
		ObjectName_[ObjectName::Flag_Text] =    new	Flag_Text();
		ObjectName_[ObjectName::Glass_Object] = new	Glass_Unit();
		ObjectName_[ObjectName::Glass_Text] =   new Glass_Text();
		ObjectName_[ObjectName::Lava_Object] =  new	Lava_Unit();
		ObjectName_[ObjectName::Lava_Text] =    new	Lava_Text();
		ObjectName_[ObjectName::Rock_Object] =  new	Rock_Unit();
		ObjectName_[ObjectName::Rock_Text] =    new	Rock_Text();
		ObjectName_[ObjectName::Skull_Object] = new	Skull_Unit();
		ObjectName_[ObjectName::Skull_Text] =   new	Skull_Text();
		ObjectName_[ObjectName::Wall_Object] =  new	Wall_Unit();
		ObjectName_[ObjectName::Wall_Text] =    new Wall_Text();
		ObjectName_[ObjectName::Water_Object] = new	Water_Unit();
		ObjectName_[ObjectName::Water_Text] =   new	Water_Text();
		ObjectName_[ObjectName::Tile_Object] =  new	Tile_Unit();
		ObjectName_[ObjectName::Is_Text] =      new	Is_Text();
		ObjectName_[ObjectName::Stop_Text] =    new	Stop_Text();
		ObjectName_[ObjectName::Defeat_Text] =  new	Defeat_Text();
		ObjectName_[ObjectName::Hot_Text] =     new	Hot_Text();
		ObjectName_[ObjectName::Melt_Text] =    new	Melt_Text();
		ObjectName_[ObjectName::Push_Text] =    new	Push_Text();
		ObjectName_[ObjectName::Sink_Text] =    new	Sink_Text();
		ObjectName_[ObjectName::Win_Text] =     new	Win_Text();
		ObjectName_[ObjectName::You_Text] =     new	You_Text();
}



