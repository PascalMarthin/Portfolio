#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Tile_Unit : public GamePlayUnitObject
{
public:
	// constrcuter destructer
	Tile_Unit();
	~Tile_Unit();

	// delete Function
	Tile_Unit(const Tile_Unit& _Other) = delete;
	Tile_Unit(Tile_Unit&& _Other) noexcept = delete;
	Tile_Unit& operator=(const Tile_Unit& _Other) = delete;
	Tile_Unit& operator=(Tile_Unit&& _Other) noexcept = delete;

protected:


private:

};

