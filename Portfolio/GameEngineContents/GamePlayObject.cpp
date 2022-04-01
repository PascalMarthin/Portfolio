#include "GamePlayObject.h"

GamePlayObject::GamePlayObject()
	: Name_(ObjectName::Error)
	, Type_(ObjectType::Error)
	, Image_(nullptr)
{
}

GamePlayObject::~GamePlayObject() 
{
}
