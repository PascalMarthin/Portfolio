#include "GamePlayObject.h"

GamePlayObject::GamePlayObject()
	: Name_(ObjectName::Error)
	, Type_(ObjectType::Error)
	, TextType_(TextType::Error)
	, Stat_(StatName::Error)
	, Image_(nullptr)
{
}

GamePlayObject::~GamePlayObject() 
{
}
