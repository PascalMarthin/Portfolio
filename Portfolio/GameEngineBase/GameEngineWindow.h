#pragma once
#include <Windows.h>
#include <string>
#include "GameEngineMath.h"

// 설명 : 기본적인 윈도우(창)을 표시해주도록 '도와주는' 클래스
class GameEngineWindow
{
private:
	static GameEngineWindow* Inst_;

public :
	inline static GameEngineWindow& GetInst()
	{
		return *Inst_;
	}
	inline static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}


public:
	void RegClass(HINSTANCE _hInst);
	void CreateGameWindow(HINSTANCE _hInst, const std::string& _Title);
	void ShowGameWindow();
	void MessageLoop(void(*_InitFunction)(), void(*_LoopFunction)());

	void SetWindowScaleAndPosition(float4 _Pos, float4 _Size);

	void Off();

	// GetDC와 다르게 맴버 변수에 있는 DC를 반환
	static inline HDC GetHDC()
	{
		return Inst_->HDC_;
	} 

	static inline float4 GetScale()
	{
		return Inst_->Scale_;
	}

protected:

private:
	std::string Title_;
	bool WindowOn_;
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC HDC_;
	float4 Scale_;

	GameEngineWindow();
	~GameEngineWindow();

	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;

};

