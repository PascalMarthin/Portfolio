#pragma once
//#include "GamePalyEnum.h"
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
	Start_the_Game,
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
	Empty_Object,
	Baba_Object,
	Baba_Text,
	Flag_Object,
	Flag_Text,
	Glass_Object,
	Glass_Text,
	Lava_Object,
	Lava_Text,
	Rock_Object,
	Rock_Text,
	Skull_Object,
	Skull_Text,
	Wall_Object,
	Wall_Text,
	Water_Object,
	Water_Text,
	Tile_Object,
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