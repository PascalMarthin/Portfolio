#pragma once

// Ό³Έν :
class MainStage
{
public:
	// constrcuter destructer
	MainStage();
	~MainStage();

	// delete Function
	MainStage(const MainStage& _Other) = delete;
	MainStage(MainStage&& _Other) noexcept = delete;
	MainStage& operator=(const MainStage& _Other) = delete;
	MainStage& operator=(MainStage&& _Other) noexcept = delete;

protected:

private:

};

