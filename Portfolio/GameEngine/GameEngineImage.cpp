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
	// �̹��� Scale�� 0�� �̹��� Ȯ�� �Լ�
	if (true == _Scale.IsZero2D())
	{
		MsgBoxAssert("ũ�Ⱑ 0�� �̹����� �����Ϸ��� �߽��ϴ�.");
		return false;
	}

	// ���� �����Ϸ��� �̹��� ũ�⸸�� �� ��Ʈ���� ����
	BitMap_ = CreateCompatibleBitmap(GameEngineWindow::GetHDC(), _Scale.ix(), _Scale.iy());

	// ����ִ� �� ������ 1,1 ���� ũ���� ������ �̹����� ����ִ�
	ImageDC_ = CreateCompatibleDC(nullptr);

	if (nullptr == ImageDC_)
	{
		MsgBoxAssert("ImageDc ������ �����߽��ϴ�.");
	}

	OldBitMap_ = (HBITMAP)SelectObject(ImageDC_, BitMap_);

	// �̹��� ���� ����
	ImageScaleCheck();

	return true;
}

// �̹��� ���� ����
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