#pragma once

// ���� : ���� ������ ������ ����� ����ϴ� Ŭ���� (3D���� ����)
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
	// ��ǥ�� �׻� �߾�(Center)�� ����
	float x;
	float y;
	float z;
	float w;

public:
	// 2D ũ�Ⱑ 0���� Ȯ�� ���ִ� �Լ�
	bool IsZero2D()
	{
		return x == 0.0f && y == 0.0f;
	}

	// float -> int�� ĳ����
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

	// ������ ������Ʈ �߾��̱⿡ ������ ���� ������ ��찡 ���
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

	// �˴� ������ �����
	float4 Half()
	{
		return { x * 0.5f, y * 0.5f , z * 0.5f, 1.0f };
	}

public :
	// ������
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
	// X ��ǥ
	int CenterLeft()
	{
		return Pos.ix() - Scale.hix();
	}
	// CX ��ǥ
	int CenterRight()
	{
		return Pos.ix() + Scale.hix();
	}
	// Y ��ǥ
	int CenterTop()
	{
		return Pos.iy() - Scale.hiy();
	}
	// CY ��ǥ
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
