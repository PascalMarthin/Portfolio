#pragma once
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineMath.h>
#include <string>
#include <queue>
#include <map>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "GamePlayEnum.h"
#include <iostream>

// 설명 :
enum class TextQueueState;
enum class AlphabetColor;
class TextQueue;
class AlphabetManager : public GameEngineActor
{
public:
	// constrcuter destructer
	AlphabetManager();
	~AlphabetManager();

	// delete Function
	AlphabetManager(const AlphabetManager& _Other) = delete;
	AlphabetManager(AlphabetManager&& _Other) noexcept = delete;
	AlphabetManager& operator=(const AlphabetManager& _Other) = delete;
	AlphabetManager& operator=(AlphabetManager&& _Other) noexcept = delete;
	void SetText(const float4& _Pos /*LU*/, const std::string& _Text, const float4& _CharSize /*const AlphabetColor _Color*/);

protected:
	void Start() override;
	void Update() override;
	void Render() override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) {}
	void LevelChangeEnd(GameEngineLevel* _NextLevel) {}

private:


	void ViewText(TextQueue* _TextQueue);
	std::map<char, float4> Alphabet_;
	GameEngineImage* AlphabetSheet_;
	std::list<TextQueue*> TextQueue_;
	GameEngineRandom* Random_;
	float Speed_;
	float AddSpeed_;

};

class TextQueue
{
public:

	TextQueue();
	~TextQueue();
	//생성될 (변환완료된) 위치
	float4 Pos_;
	//텍스트 크기
	float4 CharSize_;
	// 시트 내의 알파벳 위치
	std::string UpperText_;
	AlphabetColor Color_;
	TextQueueState State_;
	void DancingAlphabet(float _Speed);
	bool End_;

	float4 CurrentCharSize_;
	float CurrentInterTime_;
	bool SizeUp();
	bool SizeDown();

	std::vector<float4> MinMaxPos_;
	std::vector<float4> MovePos_;
private:
	//bool IsPush()
};
enum class TextQueueState
{
	BigbySmall,
	Nomal,
	SmallbyBig
};


enum class AlphabetColor
{

};