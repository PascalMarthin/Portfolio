#include "GamePlayObject.h"

GamePlayObject::GamePlayObject()
	: Name_(ObjectName::Error)
	, Type_(ObjectType::Error)
	, TextType_(TextType::Error)
	, Stat_(StatName::Error)
	, IsActive_(false)
	, Image_(nullptr)
	, TextUnit_(nullptr)
{
}

GamePlayObject::~GamePlayObject() 
{
}
