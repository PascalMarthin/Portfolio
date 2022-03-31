#include "Default.h"

Default* Default::Inst_ = new Default();

Default::Default() 
{
}

Default::~Default() 
{
}

void Default::SettingImg()
{
	Name_ = ObjectName::Default;
	Image_ = GameEngineImageManager::GetInst()->Find("default_sheet.bmp");
}
