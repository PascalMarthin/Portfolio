#pragma once
#include <GameEngine/GameEngineLevel.h>
#include "GamePlayEnum.h"
#include "Fade_InAndOut.h"
#include <GameEngineBase/GameEngineSound.h>
#include <vector>



// ���� : title ȭ�� Ŭ����
class TitleLevel : public GameEngineLevel
{
public:
	TitleLevel();
	~TitleLevel();

	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;


protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;
	void LevelChangeEnd() override;

private:
	Fade_InAndOut* Fade_;
	GameEngineSoundPlayer BackGroundMusicControl_;

};

