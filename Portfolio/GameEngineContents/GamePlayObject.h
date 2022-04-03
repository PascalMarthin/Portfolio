#pragma once
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "GamePlayEnum.h"

// ���� :
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

	// �ʿ��Ҷ� ���
	virtual void UnitObjectFucntion() 
	{
		MsgBoxAssert("�������̵尡 �ȵǾ��ֽ��ϴ�(or ���ֿ�����Ʈ�� �ƴմϴ�)");
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

