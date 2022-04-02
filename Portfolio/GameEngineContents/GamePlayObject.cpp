#include "GamePlayObject.h"

GamePlayObject::GamePlayObject()
	: Name_(ObjectName::Error)
	, Type_(ObjectType::Error)
	, TextType_(TextType::Error)
	, IsActive_(false)
	, Image_(nullptr)
{
}

GamePlayObject::~GamePlayObject() 
{
}
