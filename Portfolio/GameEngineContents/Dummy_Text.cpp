#include "Dummy_Text.h"

Dummy_Text* Dummy_Text::Inst_ = new Dummy_Text();

Dummy_Text::Dummy_Text() 
{
}

Dummy_Text::~Dummy_Text() 
{
}


void Dummy_Text::SettingAbility()
{
	Name_ = ObjectName::Dummy_Text;
	Type_ = ObjectType::Unit;
	TextType_ = TextType::Error;
	Stat_ = StatName::Error;

}
