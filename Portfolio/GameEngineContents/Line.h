#pragma once
#include "GamePlayObject.h"

// Ό³Έν :
class Line : public GamePlayObject
{
public:
	static Line* GetInst()
	{
		return Inst_;
	}

	void Destroy() override
	{
		if (nullptr == Inst_)
		{
			return;
		}

		delete Inst_;
		Inst_ = nullptr;
	}
	void SettingAbility() override;

private:
	static Line* Inst_;
	Line();
	~Line();

	// delete Function
	Line(const Line& _Other) = delete;
	Line(Line&& _Other) noexcept = delete;
	Line& operator=(const Line& _Other) = delete;
	Line& operator=(Line&& _Other) noexcept = delete;

};



