#include "Baba.h"


Baba_Unit* Baba_Unit::Inst_ = new Baba_Unit();
Baba_Text* Baba_Text::Inst_ = new Baba_Text();


Baba_Unit::Baba_Unit()
{
}

Baba_Unit::~Baba_Unit()
{
}

void Baba_Unit::SettingAbility()
{
	Name_ = ObjectName::Baba_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_baba_Sheet.bmp");
	AnimationTake_["Baba_Unit_Right"].push_back(std::make_pair(0, 2));
	AnimationTake_["Baba_Unit_Right"].push_back(std::make_pair(3, 5));
	AnimationTake_["Baba_Unit_Right"].push_back(std::make_pair(6, 8));
	//AnimationTake_["Baba_Unit_Right"].push_back(std::make_pair(9, 11));
	AnimationTake_["Baba_Unit_Up"].push_back(std::make_pair(12, 14));
	AnimationTake_["Baba_Unit_Up"].push_back(std::make_pair(15, 17));
	AnimationTake_["Baba_Unit_Up"].push_back(std::make_pair(18, 20));
	//AnimationTake_["Baba_Unit_Up"].push_back(std::make_pair(21, 23));
	AnimationTake_["Baba_Unit_Left"].push_back(std::make_pair(24, 26));
	AnimationTake_["Baba_Unit_Left"].push_back(std::make_pair(27, 29));
	AnimationTake_["Baba_Unit_Left"].push_back(std::make_pair(30, 32));
	//AnimationTake_["Baba_Unit_Left"].push_back(std::make_pair(33, 35));
	AnimationTake_["Baba_Unit_Down"].push_back(std::make_pair(36, 38));
	AnimationTake_["Baba_Unit_Down"].push_back(std::make_pair(39, 41));
	AnimationTake_["Baba_Unit_Down"].push_back(std::make_pair(42, 44));
	//AnimationTake_["Baba_Unit_Down"].push_back(std::make_pair(45, 47));
}


Baba_Text::Baba_Text() 
{
}

Baba_Text::~Baba_Text() 
{
}

void Baba_Text::SettingAbility()
{
	Name_ = ObjectName::Baba_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;
	TextUnit_ = Baba_Unit::GetInst();

	Image_ = GameEngineImageManager::GetInst()->Find("text_baba_Sheet.bmp");
	AnimationTake_["Baba_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Baba_Text_ON"].push_back(std::make_pair(3, 5));


}
