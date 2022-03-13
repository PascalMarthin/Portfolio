#pragma once
#include <Windows.h>

// ���� :
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
	void CreateGameWindow(HINSTANCE _hInst);
	void ShowGameWindow();

protected:

private:

	HWND hWnd_;
	// constrcuter destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;

protected:

private:

};

