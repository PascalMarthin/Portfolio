#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <vector>
#include <map>

// Ό³Έν :
class Coordinate;
class MainLevel : public GameEngineLevel
{
public:

	MainLevel();
	~MainLevel();


	MainLevel(const MainLevel& _Other) = delete;
	MainLevel(MainLevel&& _Other) noexcept = delete;
	MainLevel& operator=(const MainLevel& _Other) = delete;
	MainLevel& operator=(MainLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;

private:
	std::map<int, std::map<int, std::vector<Coordinate*>>> MainMap_;

	float4 MapScale_;
	float GameWindowPosX_;
	float GameWindowPosY_;

	void CreatMap(std::map<int, std::map<int, ObjectName>>& _Stage);
};

