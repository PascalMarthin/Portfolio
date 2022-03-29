#pragma once
#include "GamePlayEnum.h"
#include "GamePlayObject.h"
#include <map>


// ���� : ã�� �����Ƽ� ���� Ŭ����
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

	void  DestroyName();
public:
	GamePlayGobal();
	~GamePlayGobal();

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

