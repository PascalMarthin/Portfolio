#pragma once

// ���� :
class Stage2
{
public:
	// constrcuter destructer
	Stage2();
	~Stage2();

	// delete Function
	Stage2(const Stage2& _Other) = delete;
	Stage2(Stage2&& _Other) noexcept = delete;
	Stage2& operator=(const Stage2& _Other) = delete;
	Stage2& operator=(Stage2&& _Other) noexcept = delete;

protected:

private:

};

