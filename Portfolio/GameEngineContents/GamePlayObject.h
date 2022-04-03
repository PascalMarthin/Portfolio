#pragma once
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "GamePlayEnum.h"

// 설명 :
class GamePlayObject
{
public:
	GamePlayObject();
	virtual ~GamePlayObject();

	GamePlayObject(const GamePlayObject& _Other) = delete;
	GamePlayObject(GamePlayObject&& _Other) noexcept = delete;
	GamePlayObject& operator=(const GamePlayObject& _Other) = delete;
	GamePlayObject& operator=(GamePlayObject&& _Other) noexcept = delete;

	inline GameEngineImage* GetImage()
	{
		return Image_;
	}

	
	inline ObjectName GetName() const
	{
		return Name_;
	}
	inline ObjectType GetType() const
	{
		return Type_;
	}

	inline TextType GetTextType() const
	{
		return TextType_;
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

	GamePlayObject* GetTextUnit()
	{
		if (TextType_ != TextType::Unit_Text)
		{
			MsgBoxAssert("Unit _ Text 형식이 아닌 GamePlayObject 입니다")
		}
		return TextUnit_;
		
	}

	std::vector<ObjectName>& GetApplyStat()
	{
		if (Type_ != ObjectType::Unit)
		{
			MsgBoxAssert("Unit 형식이 아닌 GamePlayObject 입니다")
		}
		return ApplyStat_;
	}

	virtual void SettingAbility(){}
	//virtual void Reset() {}
	virtual void Destroy() = 0;

protected:
	// Only Text_Unit, OtherObject must be nullptr
	GamePlayObject* TextUnit_;
	//
	GameEngineImage* Image_;

	ObjectName Name_;
	ObjectType Type_;
	TextType TextType_;
	StatName Stat_;

	bool IsActive_;

	std::vector<ObjectName> ApplyStat_;
private:

};

