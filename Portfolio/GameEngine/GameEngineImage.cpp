#include "GameEngineImage.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>

GameEngineImage::GameEngineImage()
{
}

GameEngineImage::~GameEngineImage()
{
}



bool GameEngineImage::Create(float4 _Scale)
{
	// 이미지 Scale이 0인 이미지 확인 함수
	if (true == _Scale.IsZero2D())
	{
		MsgBoxAssert("크기가 0인 이미지를 제작하려고 했습니다.");
		return false;
	}

	// 먼저 생성하려는 이미지 크기만한 빈 비트맵을 생성
	BitMap_ = CreateCompatibleBitmap(GameEngineWindow::GetHDC(), _Scale.ix(), _Scale.iy());

	// 비어있는 것 같지만 1,1 만한 크기의 쓰레기 이미지가 들어있다
	ImageDC_ = CreateCompatibleDC(nullptr);

	if (nullptr == ImageDC_)
	{
		MsgBoxAssert("ImageDc 생성에 실패했습니다.");
	}

	OldBitMap_ = (HBITMAP)SelectObject(ImageDC_, BitMap_);

	// 이미지 정보 추출
	ImageScaleCheck();

	return true;
}

// 이미지 정보 추출
void GameEngineImage::ImageScaleCheck()
{
  //GetObject [in]     [in]            [out]
	GetObject(BitMap_, sizeof(BITMAP), &Info_);
}

//class HBITMAP 
//{
//	float4 _Scale;
//	int* Pixels;
//};