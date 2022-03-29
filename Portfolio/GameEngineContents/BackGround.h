#pragma once
#include <GameEngine/GameEngineActor.h>

// ���� :
class BackGround : public GameEngineActor
{
public:
	BackGround();
	~BackGround();

	BackGround(const BackGround& _Other) = delete;
	BackGround(BackGround&& _Other) noexcept = delete;
	BackGround& operator=(const BackGround& _Other) = delete;
	BackGround& operator=(BackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:

};

