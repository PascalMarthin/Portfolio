#pragma once
#include "GameEngineImage.h" 
#include <GameEngineBase/GameEngineMath.h>
#include <map>

// 기본적으로 리소스는 그냥 쓸수도 있지만
// 관리되는 리소스들은 전부다 이름이 있다고 보고 쓸겁니다.

// 싱글톤으로 생성 되어있다.
// 이미지를 생성하는 함수를 호출하지만 결국 이미지 만드는게 아닌 만든 이미지를
// 관리하기 위한 클래스
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

	// 이미지 생성은 기본적으로 이 함수로 진행
	// 내가 비어있는 이미지를 만드는 기능이다.
	GameEngineImage* Create(const std::string& _Name, const float4& _Scale);
	// DC가 이미 있는 이미지라면?
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

	// 이미지 관리 map
	std::map<std::string, GameEngineImage*> AllRes;
};

