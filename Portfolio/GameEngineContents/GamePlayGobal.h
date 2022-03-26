#pragma once
#include "GamePalyEnum.h"
#include "GamePlayObject.h"
#include <map>


// 설명 : 찾기 귀찮아서 만든 클래스
class GamePlayGobal
{
private:
	static GamePlayGobal* Inst_;

public:
	static GamePlayGobal* GetInst()
	{
		return Inst_;
	}

	static void Destroy()
	{
		if (nullptr == Inst_)
		{
			return;
		}

		delete Inst_;
		Inst_ = nullptr;
	}
public:
	// constrcuter destructer
	GamePlayGobal();
	~GamePlayGobal();

	// delete Function
	GamePlayGobal(const GamePlayGobal& _Other) = delete;
	GamePlayGobal(GamePlayGobal&& _Other) noexcept = delete;
	GamePlayGobal& operator=(const GamePlayGobal& _Other) = delete;
	GamePlayGobal& operator=(GamePlayGobal&& _Other) noexcept = delete;

	GamePlayObject* Find(ObjectName _Name);
protected:

private:
	void SetName();
	std::map<ObjectName, GamePlayObject*> ObjectName_;

};

