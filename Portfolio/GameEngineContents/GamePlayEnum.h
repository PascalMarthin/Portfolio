#pragma once
//#include "GamePlayEnum.h"
enum class ChangeLevel
{
	Error,
	Null,
	TitleLevel,
	MainLevel,
	PlayLevel,
};
enum class BabaLocation
{
	Baba,
	Start_The_Game,
	Settings,
	Exit_The_Game
};

enum class Stage
{
	Error,
	Stage0,
	Stage1,
	Stage2,
	Stage3,
	Stage4,
	Stage5,
	Stage6,
	Stage7
};

enum class ObjectName
{
	Error,
	Empty_Unit,
	Baba_Unit,
	Baba_Text,
	Flag_Unit,
	Flag_Text,
	Grass_Unit,
	Lava_Unit,
	Lava_Text,
	Rock_Unit,
	Rock_Text,
	Skull_Unit,
	Skull_Text,
	Wall_Unit,
	Wall_Text,
	Water_Unit,
	Water_Text,
	Tile_Unit,
	Is_Text,
	Stop_Text,
	Defeat_Text,
	Hot_Text,
	Melt_Text,
	Push_Text,
	Sink_Text,
	Win_Text,
	You_Text
};
enum class ObjectType
{
	Error,
	Unit,
	Text
};
enum class TextType
{
	Error,
	Unit_Text,
	Verb_Text,
	Stat_Text
};