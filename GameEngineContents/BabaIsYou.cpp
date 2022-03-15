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
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Title");
}
void BabaIsYou::GameLoop()
{
	
}
void BabaIsYou::GameEnd()
{

}