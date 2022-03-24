#include "Stage0.h"
Stage0::Stage0() 
{
	SetScale({ 33, 18 });
	
	Data_[6][11] = new Coordinate(ObjectName::Baba_Text);
	Data_[6][12] = new Coordinate(ObjectName::Is_Text);
	Data_[6][13] = new Coordinate(ObjectName::You_Text);
	Data_[6][19] = new Coordinate(ObjectName::Flag_Text);
	Data_[6][20] = new Coordinate(ObjectName::Is_Text);
	Data_[6][21] = new Coordinate(ObjectName::Win_Text);
	Data_[8][11] = new Coordinate(ObjectName::Wall_Object);
	Data_[8][12] = new Coordinate(ObjectName::Wall_Object);
	Data_[8][13] = new Coordinate(ObjectName::Wall_Object);
	Data_[8][14] = new Coordinate(ObjectName::Wall_Object);
	Data_[8][15] = new Coordinate(ObjectName::Wall_Object);
	Data_[8][16] = new Coordinate(ObjectName::Wall_Object);
	Data_[8][17] = new Coordinate(ObjectName::Wall_Object);
	Data_[8][18] = new Coordinate(ObjectName::Wall_Object);
	Data_[8][19] = new Coordinate(ObjectName::Wall_Object);
	Data_[8][20] = new Coordinate(ObjectName::Wall_Object);
	Data_[8][21] = new Coordinate(ObjectName::Wall_Object);
	Data_[9][11] = new Coordinate(ObjectName::Tile_Object);
	Data_[9][12] = new Coordinate(ObjectName::Tile_Object);
	Data_[9][13] = new Coordinate(ObjectName::Tile_Object);
	Data_[9][14] = new Coordinate(ObjectName::Tile_Object);
	Data_[9][15] = new Coordinate(ObjectName::Tile_Object);
	Data_[9][16] = new Coordinate(ObjectName::Rock_Object);
	Data_[9][17] = new Coordinate(ObjectName::Tile_Object);
	Data_[9][18] = new Coordinate(ObjectName::Tile_Object);
	Data_[9][19] = new Coordinate(ObjectName::Tile_Object);
	Data_[9][20] = new Coordinate(ObjectName::Tile_Object);
	Data_[9][21] = new Coordinate(ObjectName::Tile_Object);
	Data_[10][11] = new Coordinate(ObjectName::Tile_Object);
	Data_[10][12] = new Coordinate(ObjectName::Baba_Object);
	Data_[10][13] = new Coordinate(ObjectName::Tile_Object);
	Data_[10][14] = new Coordinate(ObjectName::Tile_Object);
	Data_[10][15] = new Coordinate(ObjectName::Tile_Object);
	Data_[10][16] = new Coordinate(ObjectName::Rock_Object);
	Data_[10][17] = new Coordinate(ObjectName::Tile_Object);
	Data_[10][18] = new Coordinate(ObjectName::Tile_Object);
	Data_[10][19] = new Coordinate(ObjectName::Tile_Object);
	Data_[10][20] = new Coordinate(ObjectName::Flag_Object);
	Data_[10][21] = new Coordinate(ObjectName::Tile_Object);
	Data_[11][11] = new Coordinate(ObjectName::Tile_Object);
	Data_[11][12] = new Coordinate(ObjectName::Tile_Object);
	Data_[11][13] = new Coordinate(ObjectName::Tile_Object);
	Data_[11][14] = new Coordinate(ObjectName::Tile_Object);
	Data_[11][15] = new Coordinate(ObjectName::Tile_Object);
	Data_[11][16] = new Coordinate(ObjectName::Rock_Object);
	Data_[11][17] = new Coordinate(ObjectName::Tile_Object);
	Data_[11][18] = new Coordinate(ObjectName::Tile_Object);
	Data_[11][19] = new Coordinate(ObjectName::Tile_Object);
	Data_[11][20] = new Coordinate(ObjectName::Tile_Object);
	Data_[11][21] = new Coordinate(ObjectName::Tile_Object);
	Data_[12][11] = new Coordinate(ObjectName::Wall_Object);
	Data_[12][12] = new Coordinate(ObjectName::Wall_Object);
	Data_[12][13] = new Coordinate(ObjectName::Wall_Object);
	Data_[12][14] = new Coordinate(ObjectName::Wall_Object);
	Data_[12][15] = new Coordinate(ObjectName::Wall_Object);
	Data_[12][16] = new Coordinate(ObjectName::Wall_Object);
	Data_[12][17] = new Coordinate(ObjectName::Wall_Object);
	Data_[12][18] = new Coordinate(ObjectName::Wall_Object);
	Data_[12][19] = new Coordinate(ObjectName::Wall_Object);
	Data_[12][20] = new Coordinate(ObjectName::Wall_Object);
	Data_[12][21] = new Coordinate(ObjectName::Wall_Object);
	Data_[14][11] = new Coordinate(ObjectName::Wall_Text);
	Data_[14][12] = new Coordinate(ObjectName::Is_Text);
	Data_[14][13] = new Coordinate(ObjectName::Stop_Text);
	Data_[14][19] = new Coordinate(ObjectName::Rock_Text);
	Data_[14][20] = new Coordinate(ObjectName::Is_Text);
	Data_[14][21] = new Coordinate(ObjectName::Push_Text);
	Startiter = Data_.begin();
	Enditer = Data_.end();
	
	for (;Startiter != Enditer; ++Startiter)
	{
		std::map<int, Coordinate*>& Second = (Startiter->second);
		for (Startiter2 = Second.begin(), Enditer2 = Second.end(); Startiter2 != Enditer2; ++Startiter2)
		{
			(Startiter2->second)->SetStage(Stage::Stage0);
			(Startiter2->second)->SetPos((float)(Startiter->first), (float)(Startiter2->first));
		}
	}
}

Stage0::~Stage0() 
{
	Startiter = Data_.begin();
	Enditer = Data_.end();

	for (; Startiter != Enditer; ++Startiter)
	{
		std::map<int, Coordinate*>& Second = (Startiter->second);
		for (Startiter2 = Second.begin(), Enditer2 = Second.end(); Startiter2 != Enditer2; ++Startiter2)
		{
			if (Startiter2->second != nullptr)
			{
				delete Startiter2->second;
				Startiter2->second = nullptr;
			}
			
		}
	}
}



