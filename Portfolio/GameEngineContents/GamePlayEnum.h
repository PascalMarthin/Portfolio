#pragma once
//#include "GamePlayEnum.h"
#define DotSizeX 48
#define DotSizeY 48
#define ImageSpeed 0.15f
#define SDefeat 1
#define SHot 2
#define SMelt 4
#define SPush 8
#define SSink 16
#define SStop 32
#define SWin 64
#define SYou 128
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
	MainStage,
	Stage0,
	Stage1,
	Stage2,
	Stage3,
	Stage4,
	Stage5,
	Stage6,
	Stage7
};

enum class StatName
{
	Error,
	Defeat,
	Hot,
	Melt,
	Push,
	Sink,
	Stop,
	Win,
	You,
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
	You_Text,
	Default,
	Line,
	Text_Unit,
	Dummy_Text,
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
enum class Direction
{
	Error,
	Right,
	Up,
	Left,
	Down
};