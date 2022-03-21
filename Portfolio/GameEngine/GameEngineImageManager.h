#pragma once
#include "GameEngineImage.h" 
#include <GameEngineBase/GameEngineMath.h>
#include <map>

// �⺻������ ���ҽ��� �׳� ������ ������
// �����Ǵ� ���ҽ����� ���δ� �̸��� �ִٰ� ���� ���̴ϴ�.

// �̱������� ���� �Ǿ��ִ�.
// �̹����� �����ϴ� �Լ��� ȣ�������� �ᱹ �̹��� ����°� �ƴ� ���� �̹�����
// �����ϱ� ���� Ŭ����
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



	GameEngineImage* Find(const std::string& _Name);

	// �̹��� ������ �⺻������ �� �Լ��� ����
	// ���� ����ִ� �̹����� ����� ����̴�.
	GameEngineImage* Create(const std::string& _Name, const float4& _Scale);
	// DC�� �̹� �ִ� �̹������?
	GameEngineImage* Create(const std::string& _Name, HDC _DC);

	GameEngineImage* Load(const std::string& _Path);
	GameEngineImage* Load(const std::string& _Path, const std::string& _Name);
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

