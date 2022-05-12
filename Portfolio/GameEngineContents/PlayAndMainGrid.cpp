#include "PlayAndMainGrid.h"
#include "GamePlayGobal.h"
#include "PlayLevel.h"
#include "MainLevel.h"

PlayAndMainGrid::PlayAndMainGrid() 
	: MapScale_(float4::ZERO)
	, StartDrawing_(float4::ZERO)
	, MapSizeX_(0)
	, MapSizeY_(0)
	, MapMaxSize_(float4::ZERO)
	, GridMap_(nullptr)
{
}

PlayAndMainGrid::~PlayAndMainGrid() 
{
}

void PlayAndMainGrid::Start()
{
	GameEngineActor::SetOrder(8);
	GridMap_ = GameEngineImageManager::GetInst()->Find("StageTileRazenta.bmp");
	Reset();
}

void PlayAndMainGrid::Update()
{
	if (GamePlayGobal::EnableGrid_ == false)
	{
		return;
	}
}

void PlayAndMainGrid::Render()
{
	if (GamePlayGobal::EnableGrid_ == false || MapScale_.CompareInt2D(float4::ZERO))
	{
		return;
	}
	else
	{
		GameEngine::BackBufferImage()->TransCopy(GridMap_, StartDrawing_, MapMaxSize_, float4::ZERO, MapMaxSize_, RGB(255, 0, 255));
	}
}

void PlayAndMainGrid::Reset()
{
	MapScale_ = float4::ZERO;
	if (GetLevel()->GetNameConstRef() == "PlayLevel")
	{
		MapScale_ = dynamic_cast<PlayLevel*>(GetLevel())->GetMapScale();

	}
	else if (GetLevel()->GetNameConstRef() == "MainLevel")
	{
		MapScale_ = { 33, 18 };
	}
	if (MapScale_.CompareInt2D(float4::ZERO) != true)
	{
		StartDrawing_ = { (GameEngineWindow::GetScale().x - MapScale_.x * DotSizeX) / 2,  (GameEngineWindow::GetScale().y - MapScale_.y * DotSizeY) / 2 };
		MapSizeX_ = MapScale_.ix();
		MapSizeY_ = MapScale_.iy();
		MapMaxSize_ = { MapScale_.x * DotSizeX , MapScale_.y * DotSizeY };
	}
}