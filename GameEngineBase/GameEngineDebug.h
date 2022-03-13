#pragma once
#include <crtdbg.h>
#include <string>
#include <assert.h>
#include <Windows.h>

class GameEngineDebug
{
public:
	static void LeakCheckOn();


protected:

private:

	GameEngineDebug();
	~GameEngineDebug();


	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;

};

#define MsgBoxAssert(Text) MessageBeep(0); \
MessageBoxA(nullptr, Text, "Error", MB_OK); \
assert(false);
