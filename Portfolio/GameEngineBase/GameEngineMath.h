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
	static float4 LEFT;
	static float4 RIGHT;
	static float4 UP;
	static float4 DOWN;
public:
	// 좌표는 항상 중앙(Center)을 기준
	float x;
	float y;
	float z;
	float w;

public:
	// 2D 크기가 0인지 확인 해주는 함수
	bool IsZero2D() const
	{
		return x == 0.0f && y == 0.0f;
	}

	// float -> int로 캐스팅
	int ix() const
	{
		return static_cast<int>(x);
	}

	int iy() const
	{
		return static_cast<int>(y);
	}

	int iz() const
	{
		return static_cast<int>(z);
	}

	int iw() const
	{
		return static_cast<int>(w);
	}

	// 기준은 오브젝트 중앙이기에 길이의 반을 나누는 경우가 잦다
	int hix() const
	{
		return static_cast<int>(x * 0.5f);
	}

	int hiy() const
	{
		return static_cast<int>(y * 0.5f);
	}

	int hiz() const
	{
		return static_cast<int>(z * 0.5f);
	}

	// 죄다 반으로 갈라라
	float4 Half() const
	{
		return { x * 0.5f, y * 0.5f , z * 0.5f, 1.0f };
	}

	float4 operator-(const float4& _Other) const
	{
		return { x - _Other.x, y - _Other.y, z - _Other.z, 1.0f };
	}

	float4 operator+(const float4& _Other) const
	{
		return { x + _Other.x, y + _Other.y, z + _Other.z, 1.0f };
	}
	float4 operator*(const float _Value) const
	{
		return { x * _Value, y * _Value, z * _Value, 1.0f };
	}


	float4& operator+=(const float4& _Other)
	{
		x += _Other.x;
		y += _Other.y;
		z += _Other.z;

		return *this;
	}


public :
	// 생성자
	float4()
		: x(0.0f), y(0.0f), z(0.0f), w(1.0f)
	{

	}
	float4(float _x, float _y)
		: x(_x), y(_y), z(0.0f), w(1.0f)
	{

	}
	float4(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z), w(1.0f)
	{

	}
	float4(float _x, float _y, float _z, float _w)
		: x(_x), y(_y), z(_z), w(_w)
	{

	}

};

struct GameEngineRect
{
public:
	float4 Pos;
	float4 Scale;

public:
	// X 좌표
	// 실제 좌표를 구해주는 함수
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
