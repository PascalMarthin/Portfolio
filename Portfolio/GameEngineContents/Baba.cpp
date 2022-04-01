#include "Baba.h"


Baba_Unit* Baba_Unit::Inst_ = new Baba_Unit();
Baba_Text* Baba_Text::Inst_ = new Baba_Text();


Baba_Unit::Baba_Unit()
{
}

Baba_Unit::~Baba_Unit()
{
}

void Baba_Unit::SettingImg()
{
	Name_ = ObjectName::Baba_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_baba_Sheet.bmp");
}

Baba_Text::Baba_Text() 
{
}

Baba_Text::~Baba_Text() 
{
}

void Baba_Text::SettingImg()
{
	Name_ = ObjectName::Baba_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_baba_Sheet.bmp");

}
