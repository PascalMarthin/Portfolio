#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRenderer.h>

// Ό³Έν :
class MainBackGround : public GameEngineActor
{
public:
	MainBackGround();
	~MainBackGround();

	MainBackGround(const MainBackGround& _Other) = delete;
	MainBackGround(MainBackGround&& _Other) noexcept = delete;
	MainBackGround& operator=(const MainBackGround& _Other) = delete;
	MainBackGround& operator=(MainBackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:

};

