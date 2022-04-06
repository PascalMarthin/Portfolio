#include "GamePlayTextStat.h"

// Ό³Έν :
class Stop_Text : public GamePlayTextStat
{
public:
	static Stop_Text* GetInst()
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
	std::vector<std::pair<int, int>>* GetAnimationTake(Direction _Dir) override;

protected:

private:
	static Stop_Text* Inst_;
	Stop_Text();
	~Stop_Text();

	Stop_Text(const Stop_Text& _Other) = delete;
	Stop_Text(Stop_Text&& _Other) noexcept = delete;
	Stop_Text& operator=(const Stop_Text& _Other) = delete;
	Stop_Text& operator=(Stop_Text&& _Other) noexcept = delete;

};