#pragma once

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
class Locate
{
public:
	Locate()
	{

	}
	~Locate();

	Locate(const Locate& _Other) = delete;
	Locate(Locate&& _Other) noexcept = delete;
	Locate& operator=(const Locate& _Other) = delete;
	Locate& operator=(Locate&& _Other) noexcept = delete;
};
