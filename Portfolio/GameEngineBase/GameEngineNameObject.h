#pragma once
#include <string>

// 설명 : String을 통한 Object(Actor, Level 등) 이름관리 클래스
class GameEngineNameObject
{
public:
	GameEngineNameObject();
	// 자식 소멸자 호출을 위한 가상함수 선언 
	virtual ~GameEngineNameObject();

	GameEngineNameObject(const GameEngineNameObject& _Other) = delete;
	GameEngineNameObject(GameEngineNameObject&& _Other) noexcept = delete;
	GameEngineNameObject& operator=(const GameEngineNameObject& _Other) = delete;
	GameEngineNameObject& operator=(GameEngineNameObject&& _Other) noexcept = delete;


	inline void SetName(const std::string& _Name)
	{
		Name_ = _Name;
	}

	std::string GetNameCopy()
	{
		return Name_;
	}

	const std::string& GetNameConstRef()
	{
		return Name_;
	}

	const char* GetNameConstPtr()
	{
		return Name_.c_str();
	}


protected:

private:
	std::string Name_;

};

