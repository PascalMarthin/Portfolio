#include "GamePlayObject.h"

GamePlayObject::GamePlayObject()
	: Name_(ObjectName::Error)
	, Type_(ObjectType::Error)
	, TextType_(TextType::Error)
	, Image_(nullptr)
{
}

GamePlayObject::~GamePlayObject() 
{
}
