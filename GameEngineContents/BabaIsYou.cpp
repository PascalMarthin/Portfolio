#include "BabaIsYou.h"
#include "PlayLevel.h"
#include "EndingLevel.h"
#include "TitleLevel.h"

BabaIsYou::BabaIsYou() 
{
}

BabaIsYou::~BabaIsYou() 
{
}

void BabaIsYou::GameInit()
{

}
void BabaIsYou::GameLoop()
{
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Title");
}
void BabaIsYou::GameEnd()
{

}