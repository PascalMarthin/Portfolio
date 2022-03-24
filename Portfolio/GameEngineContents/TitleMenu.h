#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :

enum class BabaLocation;
class TitleMenu : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleMenu();
	~TitleMenu();

	// delete Function
	TitleMenu(const TitleMenu& _Other) = delete;
	TitleMenu(TitleMenu&& _Other) noexcept = delete;
	TitleMenu& operator=(const TitleMenu& _Other) = delete;
	TitleMenu& operator=(TitleMenu&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	BabaLocation BabaTitleLocate;
};
enum class BabaLocation
{
	Null,
	Start_the_Game,
	Settings,
	Exit_The_Game
};