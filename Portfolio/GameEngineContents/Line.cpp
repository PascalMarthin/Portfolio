#include "Line.h"

Line* Line::Inst_ = new Line();

Line::Line() 
{
}

Line::~Line() 
{
}

void Line::SettingImg()
{
	Name_ = ObjectName::Line;
	Image_ = GameEngineImageManager::GetInst()->Find("unit_line_sheet.bmp");
}