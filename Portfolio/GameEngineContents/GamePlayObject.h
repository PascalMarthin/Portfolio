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

	inline GameEngineImage* GetImage() const
	{
		return Image_;
	}

	
	inline const ObjectName GetName() const
	{
		return Name_;
	}
	inline const ObjectType GetType() const
	{
		return Type_;
	}

	inline const TextType GetTextType() const
	{
		return TextType_;
	}

	virtual void SettingAbility(){}

	// 필요할때 사용
	virtual void UnitObjectFucntion() 
	{
		MsgBoxAssert("오버라이드가 안되어있습니다(or 유닛오브젝트가 아닙니다)");
	}
	//virtual void Reset() {}
	virtual void Destroy() = 0;

protected:
	GameEngineImage* Image_;

	ObjectName Name_;
	ObjectType Type_;
	TextType TextType_;
	StatName Stat_;

private:

};

