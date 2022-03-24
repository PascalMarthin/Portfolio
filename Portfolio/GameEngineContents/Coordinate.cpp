#include "Coordinate.h"

Coordinate::Coordinate() 
	: Pos_(),
	Stage_(Stage::Error)
{
}
Coordinate::Coordinate(ObjectName _Object)
	: Pos_(),
	Stage_(Stage::Error)
{
	Object_.push_back(_Object);
}

Coordinate::Coordinate(float4 _Pos, ObjectName _Object)
	: Pos_(_Pos),
	Stage_(Stage::Error)
{
	Object_.push_back(_Object);
}

Coordinate::Coordinate(float4 _Pos, Stage _Stage, ObjectName _Object)
	: Pos_(_Pos),
	Stage_(_Stage)
{
	Object_.push_back(_Object);
}

Coordinate::~Coordinate() 
{
}

