#include "StageName.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include "GamePlayEnum.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineImageManager.h>
#include "MainLevel.h"

StageName::StageName()
{
}

StageName::~StageName()
{
}

void StageName::Start()
{
	SetPosition((GameEngineWindow::GetScale() - float4{ (33 * DotSizeX), (18 * DotSizeY)}).Half() );
	StageRenderer_[Stage::Stage0] = CreateRenderer("Baba_Is_You.bmp", 3, RenderPivot::LeftUp, { 0 , -40 });
	StageRenderer_[Stage::Stage1] = CreateRenderer("Where_Do_I_Go.bmp", 3, RenderPivot::LeftUp, { 0 , -40 });
	StageRenderer_[Stage::Stage2] = CreateRenderer("Now_What_Is_This.bmp", 3, RenderPivot::LeftUp, { 0 , -40 });
	StageRenderer_[Stage::Stage3] = CreateRenderer("Out_Of_Reach.bmp", 3, RenderPivot::LeftUp, { 0 , -40 });
	StageRenderer_[Stage::Stage4] = CreateRenderer("Still_Out_Of_Reach.bmp", 3, RenderPivot::LeftUp, { 0 , -40 });
	StageRenderer_[Stage::Stage5] = CreateRenderer("VOLCANO.bmp", 3, RenderPivot::LeftUp, { 0 , -40 });
	StageRenderer_[Stage::Stage6] = CreateRenderer("OFF_LIMITS.bmp", 3, RenderPivot::LeftUp, { 0 , -40 });
	StageRenderer_[Stage::Stage7] = CreateRenderer("Grass_Yard.bmp", 3, RenderPivot::LeftUp, { 0 , -40 });
	for (auto iter : StageRenderer_)
	{
		iter.second->Off();
	}
}

void StageName::Update()
{
	for (auto iter : StageRenderer_)
	{
		iter.second->Off();
	}
	if (MainLevel::GetCurrentStage() != Stage::MainStage && MainLevel::GetCurrentStage() != Stage::DebugStage)
	{
		StageRenderer_[MainLevel::GetCurrentStage()]->On();
	}
}

void StageName::Render()
{

}

