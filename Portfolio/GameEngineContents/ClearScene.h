#pragma once
#include <GameEngine/GameEngineActor.h>

// 설명 :

// 설명 :
class ClearScene : public GameEngineActor
{
public:
	ClearScene();
	~ClearScene();

	ClearScene(const ClearScene& _Other) = delete;
	ClearScene(ClearScene&& _Other) noexcept = delete;
	ClearScene& operator=(const ClearScene& _Other) = delete;
	ClearScene& operator=(ClearScene&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:

};

