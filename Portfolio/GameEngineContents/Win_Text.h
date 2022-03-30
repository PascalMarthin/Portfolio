#include "GamePlayTextObject.h"

// Ό³Έν :
class Win_Text : public GamePlayTextObject
{
public:
	static Win_Text* GetInst()
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
	void SettingImg() override;

private:
	static Win_Text* Inst_;
	Win_Text();
	~Win_Text();

	Win_Text(const Win_Text& _Other) = delete;
	Win_Text(Win_Text&& _Other) noexcept = delete;
	Win_Text& operator=(const Win_Text& _Other) = delete;
	Win_Text& operator=(Win_Text&& _Other) noexcept = delete;

};