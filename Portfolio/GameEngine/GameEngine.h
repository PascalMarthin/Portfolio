#pragma once
#include <map>
#include <string>
#include <GameEngineBase/GameEngineDebug.h>

// GameEngine은 단순 인터페이스
// 설명 : 게임엔진이란 게임 그자체의 시작점과 끝점 실행중을 담당하는 녀석이다.
// 게임의 시작점과 루프와 끝을 담당하게 될 것이다. 

class GameEngineImage;
class GameEngineLevel;
class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	GameEngine(const GameEngine& _Other) = delete;
	GameEngine(GameEngine&& _Other) noexcept = delete;
	GameEngine& operator=(const GameEngine& _Other) = delete;
	GameEngine& operator=(GameEngine&& _Other) noexcept = delete;

	static inline GameEngineImage* BackBufferImage()
	{
		return BackBufferImage_;
	}

	// 더블 버퍼를 위한 HDC
	static HDC BackBufferDC();

	virtual void GameInit() = 0;
	virtual void GameLoop() = 0;
	virtual void GameEnd() = 0;

	// GameType = Level 2 Baba_is_you
	template<typename GameType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();

		GameType UserGame;
		UserContents_ = &UserGame;

		// 윈도우 생성, 윈도우 출력, 메시지 루프
		WindowCreate();


		//
		// 종료
		EngineEnd();
	}

	static GameEngine& GlobalEngine()
	{
		if (nullptr == UserContents_)
		{
			MsgBoxAssert("GEngine ERROR Engine Is Not Start ");
		}

		return *UserContents_;
	}

	void ChangeLevel(const std::string& _Name);

protected:
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		NewLevel->SetName(_Name);
		GameEngineLevel* Level = NewLevel;
		Level->Loading();
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}


private:
	// map이 가지고있는 string KEY로 GameEngineLevel* (VALUE) 관리
	static std::map<std::string, GameEngineLevel*> AllLevel_;
	static GameEngineLevel* CurrentLevel_;
	static GameEngineLevel* NextLevel_;
	static GameEngine* UserContents_;
	static GameEngineImage* BackBufferImage_;

	static void WindowCreate();
	static void EngineInit();
	static void EngineLoop();
	static void EngineEnd();


};

