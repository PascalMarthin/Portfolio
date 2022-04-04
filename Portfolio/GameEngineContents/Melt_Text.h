#include "GamePlayTextStat.h"

// Ό³Έν :
class Melt_Text : public GamePlayTextStat
{
public:
	static Melt_Text* GetInst()
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

protected:

private:
	static Melt_Text* Inst_;
	Melt_Text();
	~Melt_Text();

	Melt_Text(const Melt_Text& _Other) = delete;
	Melt_Text(Melt_Text&& _Other) noexcept = delete;
	Melt_Text& operator=(const Melt_Text& _Other) = delete;
	Melt_Text& operator=(Melt_Text&& _Other) noexcept = delete;

};

