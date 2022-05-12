#include "PlayAndMainGrid.h"
#include "GamePlayGobal.h"
#include "PlayLevel.h"
#include "MainLevel.h"

PlayAndMainGrid::PlayAndMainGrid() 
	: MapScale_(float4::ZERO)
	, StartDrawing_(float4::ZERO)
	, MapSizeX_(0)
	, MapSizeY_(0)
	, MapMaxSizeX_(0)
	, MapMaxSizeY_(0)
{
}

PlayAndMainGrid::~PlayAndMainGrid() 
{
}

void PlayAndMainGrid::Start()
{
	GameEngineActor::SetOrder(8);
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
		HDC BackGround = GameEngine::BackBufferImage()->ImageDC();
		int StartX = StartDrawing_.ix();
		int StartY = StartDrawing_.iy();

		for (size_t i = 1; i < MapSizeY_; i++)
		{
			for (size_t j = 0; j < MapMaxSizeX_; j++)
			{
				SetPixel(BackGround, StartX + j, StartY + (iDotSizeY * i), RGB(255, 255, 255));
			}
		}
		for (size_t i = 1; i < MapSizeX_; i++)
		{
			for (size_t j = 0; j < MapMaxSizeY_; j++)
			{
				SetPixel(BackGround, StartX + (iDotSizeX * i), StartY + j, RGB(255, 255, 255));
			}
		}
	}
}

void PlayAndMainGrid::Reset()
{
	MapScale_ = float4::ZERO;
	if (GetLevel()->GetNameConstRef() == "PlayLevel")
	{
		MapScale_ = dynamic_cast<PlayLevel*>(GetLevel())->GetMapScale();
		StartDrawing_ = { (GameEngineWindow::GetScale().x - MapScale_.x * DotSizeX) / 2,  (GameEngineWindow::GetScale().y - MapScale_.y * DotSizeY) / 2 };
		MapSizeX_ = MapScale_.ix();
		MapSizeY_ = MapScale_.iy();
		MapMaxSizeX_ = MapScale_.x * DotSizeX;
		MapMaxSizeY_ = MapScale_.y * DotSizeY;

	}
	else if (GetLevel()->GetNameConstRef() == "MainLevel")
	{

	}
}