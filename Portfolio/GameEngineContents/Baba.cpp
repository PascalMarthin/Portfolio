#include "Baba.h"

Baba_Unit::Baba_Unit()
{
}

Baba_Unit::~Baba_Unit()
{
}

void Baba_Unit::Start()
{
	CreateRenderer("baba_0_2.bmp");
}

void Baba_Unit::Update()
{
	SetPosition(GetObjectCPos());
}

Baba_Text::Baba_Text() 
{
}

Baba_Text::~Baba_Text() 
{
}

