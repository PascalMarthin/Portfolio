#include "Stage0.h"


Stage0::Stage0() 
{
	SetScale({ 33, 18 });
	SetStage(Stage::Stage0);
	
	Data_[6][11]  = ObjectName::Baba_Text;
	Data_[6][12]  = ObjectName::Is_Text;
	Data_[6][13]  = ObjectName::You_Text;
	Data_[6][19]  = ObjectName::Flag_Text;
	Data_[6][20]  = ObjectName::Is_Text;
	Data_[6][21]  = ObjectName::Win_Text;
	Data_[8][11]  = ObjectName::Wall_Object;
	Data_[8][12]  = ObjectName::Wall_Object;
	Data_[8][13]  = ObjectName::Wall_Object;
	Data_[8][14]  = ObjectName::Wall_Object;
	Data_[8][15]  = ObjectName::Wall_Object;
	Data_[8][16]  = ObjectName::Wall_Object;
	Data_[8][17]  = ObjectName::Wall_Object;
	Data_[8][18]  = ObjectName::Wall_Object;
	Data_[8][19]  = ObjectName::Wall_Object;
	Data_[8][20]  = ObjectName::Wall_Object;
	Data_[8][21]  = ObjectName::Wall_Object;
	Data_[9][11]  = ObjectName::Tile_Object;
	Data_[9][12]  = ObjectName::Tile_Object;
	Data_[9][13]  = ObjectName::Tile_Object;
	Data_[9][14]  = ObjectName::Tile_Object;
	Data_[9][15]  = ObjectName::Tile_Object;
	Data_[9][16]  = ObjectName::Rock_Object;
	Data_[9][17]  = ObjectName::Tile_Object;
	Data_[9][18]  = ObjectName::Tile_Object;
	Data_[9][19]  = ObjectName::Tile_Object;
	Data_[9][20]  = ObjectName::Tile_Object;
	Data_[9][21]  = ObjectName::Tile_Object;
	Data_[10][11] = ObjectName::Tile_Object;
	Data_[10][12] = ObjectName::Baba_Object;
	Data_[10][13] = ObjectName::Tile_Object;
	Data_[10][14] = ObjectName::Tile_Object;
	Data_[10][15] = ObjectName::Tile_Object;
	Data_[10][16] = ObjectName::Rock_Object;
	Data_[10][17] = ObjectName::Tile_Object;
	Data_[10][18] = ObjectName::Tile_Object;
	Data_[10][19] = ObjectName::Tile_Object;
	Data_[10][20] = ObjectName::Flag_Object;
	Data_[10][21] = ObjectName::Tile_Object;
	Data_[11][11] = ObjectName::Tile_Object;
	Data_[11][12] = ObjectName::Tile_Object;
	Data_[11][13] = ObjectName::Tile_Object;
	Data_[11][14] = ObjectName::Tile_Object;
	Data_[11][15] = ObjectName::Tile_Object;
	Data_[11][16] = ObjectName::Rock_Object;
	Data_[11][17] = ObjectName::Tile_Object;
	Data_[11][18] = ObjectName::Tile_Object;
	Data_[11][19] = ObjectName::Tile_Object;
	Data_[11][20] = ObjectName::Tile_Object;
	Data_[11][21] = ObjectName::Tile_Object;
	Data_[12][11] = ObjectName::Wall_Object;
	Data_[12][12] = ObjectName::Wall_Object;
	Data_[12][13] = ObjectName::Wall_Object;
	Data_[12][14] = ObjectName::Wall_Object;
	Data_[12][15] = ObjectName::Wall_Object;
	Data_[12][16] = ObjectName::Wall_Object;
	Data_[12][17] = ObjectName::Wall_Object;
	Data_[12][18] = ObjectName::Wall_Object;
	Data_[12][19] = ObjectName::Wall_Object;
	Data_[12][20] = ObjectName::Wall_Object;
	Data_[12][21] = ObjectName::Wall_Object;
	Data_[14][11] = ObjectName::Wall_Text;
	Data_[14][12] = ObjectName::Is_Text;
	Data_[14][13] = ObjectName::Stop_Text;
	Data_[14][19] = ObjectName::Rock_Text;
	Data_[14][20] = ObjectName::Is_Text;
	Data_[14][21] = ObjectName::Push_Text;

}

Stage0::~Stage0() 
{
	
}



