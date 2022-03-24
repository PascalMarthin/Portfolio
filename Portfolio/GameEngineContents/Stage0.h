#pragma once
#include "StageData.h"

// Ό³Έν :
class Stage0 : public StageData
{
	Stage0();
	~Stage0();

	Stage0(const Stage0& _Other) = delete;
	Stage0(Stage0&& _Other) noexcept = delete;
	Stage0& operator=(const Stage0& _Other) = delete;
	Stage0& operator=(Stage0&& _Other) noexcept = delete;

protected:

private:
	std::map<int, std::map<int, Coordinate*>>::iterator Startiter = Data_.begin();
	std::map<int, std::map<int, Coordinate*>>::iterator Enditer = Data_.end();
	std::map<int, Coordinate*>::iterator Startiter2;
	std::map<int, Coordinate*>::iterator Enditer2;


};

