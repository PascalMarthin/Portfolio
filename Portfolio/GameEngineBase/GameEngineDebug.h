#pragma once
#include <crtdbg.h>
#include <string>
#include <assert.h>
#include <Windows.h>

// 설명 : 메모리 누수 등 외적인 내용을 관리하는 디버깅 클래스
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
