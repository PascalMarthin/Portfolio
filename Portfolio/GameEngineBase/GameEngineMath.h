#pragma once

// 설명 : 게임 엔진의 수학적 기능을 담당하는 클래스 (3D까지 생각)
class GameEngineMath
{
public:
	GameEngineMath();
	~GameEngineMath();


	GameEngineMath(const GameEngineMath& _Other) = delete;
	GameEngineMath(GameEngineMath&& _Other) noexcept = delete;
	GameEngineMath& operator=(const GameEngineMath& _Other) = delete;
	GameEngineMath& operator=(GameEngineMath&& _Other) noexcept = delete;

protected:

private:

};

class float4
{
public:
	// 좌표는 항상 중앙(Center)을 기준
	float x;
	float y;
	float z;
	float w;

public:
	// float -> int로 캐스팅
	int ix()
	{
		return static_cast<int>(x);
	}

	int iy()
	{
		return static_cast<int>(y);
	}

	int iz()
	{
		return static_cast<int>(z);
	}

	int iw()
	{
		return static_cast<int>(w);
	}

	// 기준은 오브젝트 중앙이기에 길이의 반을 나누는 경우가 잦다
	int hix()
	{
		return static_cast<int>(x * 0.5f);
	}

	int hiy()
	{
		return static_cast<int>(y * 0.5f);
	}

	int hiz()
	{
		return static_cast<int>(z * 0.5f);
	}

	float4 Half()
	{
		return { x * 0.5f, y * 0.5f , z * 0.5f, 1.0f };
	}
};

struct GameEngineRect
{
public:
	float4 Pos;
	float4 Scale;

public:
	// X 좌표
	int CenterLeft()
	{
		return Pos.ix() - Scale.hix();
	}
	// CX 좌표
	int CenterRight()
	{
		return Pos.ix() + Scale.hix();
	}
	// Y 좌표
	int CenterTop()
	{
		return Pos.iy() - Scale.hiy();
	}
	// CY 좌표
	int CenterBot()
	{
		return Pos.iy() + Scale.hiy();
	}

public:
	GameEngineRect(float4 _Pos, float4 _Scale)
		: Pos(_Pos)
		, Scale(_Scale)
	{

	}
};
