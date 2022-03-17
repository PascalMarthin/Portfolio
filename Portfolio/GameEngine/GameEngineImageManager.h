#pragma once
#include "GameEngineImage.h" 
#include <GameEngineBase/GameEngineMath.h>
#include <map>

// �⺻������ ���ҽ��� �׳� ������ ������
// �����Ǵ� ���ҽ����� ���δ� �̸��� �ִٰ� ���� ���̴ϴ�.

// �̱������� ���� �Ǿ��ִ�.
class GameEngineImageManager
{
private:
	static GameEngineImageManager* Inst_;

public:
	static GameEngineImageManager* GetInst()
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
	// �̹��� ������ �⺻������ �� �Լ��� ����
	GameEngineImage* Create(const std::string& _Name, float4 _Scale);

protected:

private:
	GameEngineImageManager();
	~GameEngineImageManager();

	GameEngineImageManager(const GameEngineImageManager& _Other) = delete;
	GameEngineImageManager(GameEngineImageManager&& _Other) noexcept = delete;
	GameEngineImageManager& operator=(const GameEngineImageManager& _Other) = delete;
	GameEngineImageManager& operator=(GameEngineImageManager&& _Other) noexcept = delete;

	// �̹��� ���� map
	std::map<std::string, GameEngineImage*> AllRes;
};

