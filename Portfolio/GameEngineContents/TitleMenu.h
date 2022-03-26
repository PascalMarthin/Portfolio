#pragma once
#include <GameEngine/GameEngineActor.h>
#include <vector>
#include <map>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngineImage.h>
#include "GamePlayEnum.h"


// Ό³Έν :
class TitleLevel;
class TitleMenu : public GameEngineActor
{
	friend TitleLevel;
public:
	// constrcuter destructer
	TitleMenu();
	~TitleMenu();

	// delete Function
	TitleMenu(const TitleMenu& _Other) = delete;
	TitleMenu(TitleMenu&& _Other) noexcept = delete;
	TitleMenu& operator=(const TitleMenu& _Other) = delete;
	TitleMenu& operator=(TitleMenu&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	static BabaLocation BabaTitleLocate;
	std::map<BabaLocation, std::vector<GameEngineImage*>> TilteMenuImage;
	float4 StartPos_;
	float4 SettingPos_;
	float4 ExitPos_;
	float4 BabaPos_;
	float4 BabaPosFF_;
	
};
