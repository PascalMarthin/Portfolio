#pragma once
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineImageManager.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class GamePlayObject
{
public:
	GamePlayObject();
	virtual ~GamePlayObject();

	GamePlayObject(const GamePlayObject& _Other) = delete;
	GamePlayObject(GamePlayObject&& _Other) noexcept = delete;
	GamePlayObject& operator=(const GamePlayObject& _Other) = delete;
	GamePlayObject& operator=(GamePlayObject&& _Other) noexcept = delete;

	inline GameEngineImage* GetImage() const
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

	virtual void SettingImg(){}
	virtual void Destroy() = 0;

protected:
	GameEngineImage* Image_;

	ObjectName Name_;
	ObjectType Type_;

	TextType TextType_;
	bool IsActive_;

private:

};

