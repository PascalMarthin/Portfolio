#include "GamePlayTextStat.h"

// Ό³Έν :
class Sink_Text : public GamePlayTextStat
{
public:
	static Sink_Text* GetInst()
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
	static Sink_Text* Inst_;
	Sink_Text();
	~Sink_Text();

	Sink_Text(const Sink_Text& _Other) = delete;
	Sink_Text(Sink_Text&& _Other) noexcept = delete;
	Sink_Text& operator=(const Sink_Text& _Other) = delete;
	Sink_Text& operator=(Sink_Text&& _Other) noexcept = delete;

};
