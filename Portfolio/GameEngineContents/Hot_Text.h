#include "GamePlayTextObject.h"

// Ό³Έν :
class Hot_Text : public GamePlayTextObject
{
public:
	static Hot_Text* GetInst()
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
	void StatEffect() override;

private:
	static Hot_Text* Inst_;
	void StatHot();
	Hot_Text();
	~Hot_Text();

	Hot_Text(const Hot_Text& _Other) = delete;
	Hot_Text(Hot_Text&& _Other) noexcept = delete;
	Hot_Text& operator=(const Hot_Text& _Other) = delete;
	Hot_Text& operator=(Hot_Text&& _Other) noexcept = delete;

};

