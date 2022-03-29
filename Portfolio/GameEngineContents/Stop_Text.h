#include "GamePlayTextObject.h"

// ���� :
class Stop_Text : public GamePlayTextObject
{
public:
	static Stop_Text* GetInst()
	{
		return Inst_;
	}

	static void Destroy()
	{
		if (nullptr == Inst_)
		{
			return;
		}

		delete Inst_;
		Inst_ = nullptr;
	}
	void SettingImg() override;

private:
	static Stop_Text* Inst_;
	Stop_Text();
	~Stop_Text();

	Stop_Text(const Stop_Text& _Other) = delete;
	Stop_Text(Stop_Text&& _Other) noexcept = delete;
	Stop_Text& operator=(const Stop_Text& _Other) = delete;
	Stop_Text& operator=(Stop_Text&& _Other) noexcept = delete;

};