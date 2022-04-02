#include "Default.h"

Default* Default::Inst_ = new Default();

Default::Default() 
{
}

Default::~Default() 
{
}

void Default::SettingAbility()
{
	Name_ = ObjectName::Default;
	Image_ = GameEngineImageManager::GetInst()->Find("Main_stage_sheet.bmp");
}
