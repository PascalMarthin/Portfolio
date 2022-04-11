#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngine/GameEngineActor.h>
#include "GamePlayEnum.h"
#include "GamePlayObject.h"
#include "GamePlayUnitObject.h"
#include "GamePlayUnitText.h"
#include <vector>


class Coordinate : public GameEngineActor
{
public:
	Coordinate();
	~Coordinate();


	Coordinate(const Coordinate& _Other) = delete;
	Coordinate(Coordinate&& _Other) noexcept = delete;
	Coordinate& operator=(const Coordinate& _Other) = delete;
	Coordinate& operator=(Coordinate&& _Other) noexcept = delete;

	inline GamePlayUnitObject* GetUnitObjectInst() const
	{
		return UnitObject_;
	}

	inline GamePlayText* GetTextObjectInst() const
	{
		return TextObject_;
	}

	inline ObjectType GetObjectType() const
	{
		return Type_;
	}

	void SetCFrame(int _Start, int _End)
	{
		CurrentFrame_ = _Start;
		StartFrame_ = _Start;
		EndFrame_ = _End;
	}
	void SetPos(const float4& _Pos, const float4& _CPos)
	{
		CurrentPos_ = _Pos;
		CurrentLUPos_ = _CPos;
		PastPos_ = CurrentPos_;
		PastLUPos_ = CurrentLUPos_;
		SetPosition({ CurrentLUPos_.x + (DotSizeX / 2), CurrentLUPos_.y + (DotSizeY / 2) });
	}
	inline const float4& GetPos() const
	{
		return CurrentPos_;
	}
	inline Direction GetDir() const
	{
		return UnitDir_;
	}

	inline void SetOFF()
	{
		IsActive_ = false;
	}
	inline void SetON()
	{
		IsActive_ = true;
	}
	inline bool IsActive() const
	{
		return IsActive_;
	}

	inline void SetMove(bool _Bool)
	{
		IsMove_ = _Bool;
	}
	inline const bool IsMove() const
	{
		return IsMove_;
	}

	inline void KeyIsPushOn()
	{
		IsKeyPush_ = true;
	}

	inline bool IsUnitUpdate()
	{
		return UnitUpdate_;
	}

	inline void UpdateON()
	{
		UnitUpdate_ = true;
	}
	inline void UpdateOFF()
	{
		UnitUpdate_ = false;
	}

	inline void SetBridgeUnit(unsigned int _idx)
	{
		BridgeUnit_ = _idx;
	}

	void ChangePos(const float4& _Pos, const float4& _CPos, Direction _Dir);
	void ChangeBackPos(const float4& _Pos, const float4& _CPos, Direction _Dir);
	void SetValue(GamePlayObject* _Object, Direction _Dir = Direction::Right, const float4& _Size = { DotSizeX, DotSizeY });

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	float4 PastPos_;
	float4 PastLUPos_;
	float4 CurrentPos_;
	float4 CurrentLUPos_;
	int PastByCurrentRange_;

	


	GamePlayUnitObject* UnitObject_;
	GamePlayText* TextObject_;
	ObjectType Type_;

	bool IsActive_;
	bool IsMove_;
	bool IsKeyPush_;
	bool IsBackTothePast_;
	bool UnitUpdate_;

	unsigned int BridgeUnit_;
	void BridgeUnitCheck();
	void ActorOrderCheck();
	
	// img
	const std::vector<std::pair<int, int>>* CurrentImageIndex_;
	int CurrentFrame_;
	int StartFrame_;
	int EndFrame_;
	int SceneFrame_;
	float CurrentInterTime_;
	float4 CurrentImgScale_;
	float4 CurrentImgPivot_;
	Direction UnitDir_;

	void FrameUpdate();
	void SetCurrentImage();
};

