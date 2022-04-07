#include "Text.h"
Text_Unit* Text_Unit::Inst_ = new Text_Unit();

Text_Unit::Text_Unit() 
{
}

Text_Unit::~Text_Unit() 
{
}


void Text_Unit::SettingAbility()
{
	Name_ = ObjectName::Text_Unit;
	Type_ = ObjectType::Text;
}