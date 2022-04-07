#include "GamePlayTextStat.h"

// Ό³Έν :
class You_Text : public GamePlayTextStat
{
public:
	static You_Text* GetInst()
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
	const std::vector<std::pair<int, int>>* GetAnimationTake(Direction _Dir) override;

protected:

private:
	static You_Text* Inst_;
	You_Text();
	~You_Text();

	You_Text(const You_Text& _Other) = delete;
	You_Text(You_Text&& _Other) noexcept = delete;
	You_Text& operator=(const You_Text& _Other) = delete;
	You_Text& operator=(You_Text&& _Other) noexcept = delete;

};