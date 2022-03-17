#pragma once

// Ό³Έν :
class Is_Text
{
public:
	// constrcuter destructer
	Is_Text();
	~Is_Text();

	// delete Function
	Is_Text(const Is_Text& _Other) = delete;
	Is_Text(Is_Text&& _Other) noexcept = delete;
	Is_Text& operator=(const Is_Text& _Other) = delete;
	Is_Text& operator=(Is_Text&& _Other) noexcept = delete;

protected:

private:

};

