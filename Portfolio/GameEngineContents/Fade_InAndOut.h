#pragma once

#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineFolderImage.h>
// 설명 : 레벨이 이동할때마다 호출
class Fade_InAndOut : public GameEngineActor
{
public:
	Fade_InAndOut();
	~Fade_InAndOut();

	Fade_InAndOut(const Fade_InAndOut& _Other) = delete;
	Fade_InAndOut(Fade_InAndOut&& _Other) noexcept = delete;
	Fade_InAndOut& operator=(const Fade_InAndOut& _Other) = delete;
	Fade_InAndOut& operator=(Fade_InAndOut&& _Other) noexcept = delete;

	void ShowFadeIn();
	void ShowFadeOut();
	void Reset();

	inline bool IsChangeScreen() const
	{
		return ChangeScreen_;
	}
	
	inline bool IsFadeOut() const
	{
		return FadeOut_;
	}

	inline bool IsFadeIn() const
	{
		return FadeIn_;
	}

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	GameEngineFolderImage* FadeImage_;
	int CurrentFrame_;
	int EndFrame_;
	float CurrentInterTime_;
	float WattingTime_;
	float4 ImageScale_;

	bool FadeIn_;
	bool FadeOut_;
	bool ChangeScreen_;

};

