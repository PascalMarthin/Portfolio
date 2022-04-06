#include "GamePlayTextStat.h"

// ���� :
class Push_Text : public GamePlayTextStat
{
public:
	static Push_Text* GetInst()
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
	static Push_Text* Inst_;
	Push_Text();
	~Push_Text();

	Push_Text(const Push_Text& _Other) = delete;
	Push_Text(Push_Text&& _Other) noexcept = delete;
	Push_Text& operator=(const Push_Text& _Other) = delete;
	Push_Text& operator=(Push_Text&& _Other) noexcept = delete;

};

