#include "StudyGame.h"
#include "PlayLevel.h"
#include "EndingLevel.h"
#include "TitleLevel.h"

StudyGame::StudyGame()
{
}

StudyGame::~StudyGame()
{
}

void StudyGame::GameInit()
{
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
}

void StudyGame::GameLoop()
{

}
void StudyGame::GameEnd()
{

}