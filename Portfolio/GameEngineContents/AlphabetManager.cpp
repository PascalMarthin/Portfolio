#include "AlphabetManager.h"
#define VectorSpeed 1.0f

AlphabetManager::AlphabetManager() 
	: AlphabetSheet_(nullptr)
	, Random_(nullptr)
	, Speed_(0)
	, AddSpeed_(1.0f)
	, MoveRange_(0.0f)
	, MaxRange_(0.0f)
{

}

AlphabetManager::~AlphabetManager() 
{
	if (TextQueue_.empty() == false)
	{

	}
	while (TextQueue_.empty() == false)
	{
		delete TextQueue_.front();
		TextQueue_.pop_front();
	}
	if (Random_ != nullptr)
	{
		delete Random_;
	}
}
void AlphabetManager::Start()
{
	{
		Alphabet_['A'] = {0 , DotSizeY * 0 };
		Alphabet_['B'] = {0 , DotSizeY * 1 };
		Alphabet_['C'] = {0 , DotSizeY * 2 };
		Alphabet_['D'] = {0 , DotSizeY * 3 };
		Alphabet_['E'] = {0 , DotSizeY * 4 };
		Alphabet_['F'] = {0 , DotSizeY * 5 };
		Alphabet_['G'] = {0 , DotSizeY * 6 };
		Alphabet_['H'] = {0 , DotSizeY * 7 };
		Alphabet_['I'] = {0 , DotSizeY * 8 };
		Alphabet_['J'] = {0 , DotSizeY * 9 };
		Alphabet_['K'] = {0 , DotSizeY * 10};
		Alphabet_['L'] = {0 , DotSizeY * 11 };
		Alphabet_['M'] = {0 , DotSizeY * 12 };
		Alphabet_['N'] = {0 , DotSizeY * 13 };
		Alphabet_['O'] = {0 , DotSizeY * 14 };
		Alphabet_['P'] = {0 , DotSizeY * 15 };
		Alphabet_['Q'] = {0 , DotSizeY * 16 };
		Alphabet_['R'] = {0 , DotSizeY * 17 };
		Alphabet_['S'] = {0 , DotSizeY * 18 };
		Alphabet_['T'] = {0 , DotSizeY * 19 };
		Alphabet_['U'] = {0 , DotSizeY * 20 };
		Alphabet_['V'] = { 0 , DotSizeY * 21 };
		Alphabet_['W'] = { 0 , DotSizeY * 22 };
		Alphabet_['X'] = { 0 , DotSizeY * 23 };
		Alphabet_['Y'] = { 0 , DotSizeY * 24 };
		Alphabet_['Z'] = { 0 , DotSizeY * 25 };
		Alphabet_['?'] = { 0 , DotSizeY * 26 };
		Alphabet_['0'] = { 0 , DotSizeY * 27 };
		Alphabet_['1'] = { 0 , DotSizeY * 28 };
		Alphabet_['2'] = { 0 , DotSizeY * 29 };
		Alphabet_['3'] = { 0 , DotSizeY * 30 };
		Alphabet_['4'] = { 0 , DotSizeY * 31 };
		Alphabet_['5'] = { 0 , DotSizeY * 32 };
		Alphabet_['6'] = { 0 , DotSizeY * 33 };
		Alphabet_['7'] = { 0 , DotSizeY * 34 };
		Alphabet_['8'] = { 0 , DotSizeY * 35 };
		Alphabet_['9'] = { 0 , DotSizeY * 36 };
		Alphabet_[' '] = { 0 , DotSizeY * 37 };

	}
	AlphabetSheet_ = GameEngineImageManager::GetInst()->Find("BabaChar_Sheet.bmp");
	
	Random_ = new GameEngineRandom();
}

//const float4& AlphabetManager::FindAlphabet(const char& _char)
//{
//	if (Alphabet_.find(_char) == Alphabet_.end())
//	{
//		MsgBoxAssert("존재하지 않는 알파벳입니다");
//	}
//	return Alphabet_[_char];
//}

void AlphabetManager::EndText()
{
	for (TextQueue* Iter : TextQueue_)
	{
		Iter->State_ = TextQueueState::SmallbyBig;
	}
}
void AlphabetManager::Update()
{
	if (TextQueue_.empty() == false)
	{
		std::list<TextQueue*>::iterator StartIter = TextQueue_.begin();
		std::list<TextQueue*>::iterator EndIter = TextQueue_.end();

		for (; StartIter != EndIter;)
		{
			switch ((*StartIter)->State_)
			{
			case TextQueueState::BigbySmall:
				if ((*StartIter)->SizeUp() == true)
				{
					(*StartIter)->State_ = TextQueueState::Nomal;
				}
				break;
			case TextQueueState::Nomal:
				(*StartIter)->DancingAlphabet(Speed_);
				break;
			case TextQueueState::SmallbyBig:
				if ((*StartIter)->SizeDown() == true)
				{
					(*StartIter)->End_ = true;
				}
				break;
			}
			if ((*StartIter)->End_ == true)
			{
				delete* StartIter;
				StartIter = TextQueue_.erase(StartIter);
				continue;
			}
			StartIter++;
		}
		Speed_ -= AddSpeed_;
		MoveRange_ = (Speed_ > 0 ? Speed_ : Speed_ * -1.0f);
		if (MoveRange_ > MaxRange_)
		{
			if (Speed_ < -12.0f)
			{
				Speed_ = -8.0f;
				AddSpeed_ = -0.2f;
				MaxRange_ = 20.0f;
				MoveRange_ = 0.0f;
			}
			else if (Speed_ > 12.0f)
			{
				Speed_ = 8.0f;
				AddSpeed_ = 0.2f;
				MaxRange_ = 20.0f;
				MoveRange_ = 0.0f;
			}
		}
	}
}
void AlphabetManager::Render()
{
	if (TextQueue_.empty() == false)
	{
		std::list<TextQueue*>::iterator StartIter = TextQueue_.begin();
		std::list<TextQueue*>::iterator EndIter = TextQueue_.end();

		for (; StartIter != EndIter;)
		{
			ViewText(*StartIter);
			StartIter++;
		}

	}
}

void AlphabetManager::SetText(const float4& _Pos /*LU*/, const std::string& _Text, const float4& _CharSize, const float
	_interval/*const AlphabetColor _Color*/)
{
	MaxRange_ = 15.0f;
	MoveRange_ = 0.0f;
	Speed_ = 12.0f;
	AddSpeed_ = 0.5f;
	TextQueue* NewText = new TextQueue();
	{

		int PastSelect = 10;
		NewText->Pos_ = { _Pos.x - ((_Text.size() / 2) * (_CharSize.x - _interval/2)) - (_Text.size() % 2 == 0 ? 0.0f : _CharSize.Half().x) , _Pos.y - _CharSize.Half().y};
		// 대문자로 변환
		NewText->CurrentInterTime_ = 0.01f;
		NewText->UpperText_ = GameEngineString::ToUpperReturn(_Text);
		for (size_t i = 0; i < _Text.size(); i++)
		{
			// 중앙으로 위치 변경(중앙에 출력되도록 변경)
			float4 Pos = { NewText->Pos_.x + ((_CharSize.x - _interval / 2) * i) , NewText->Pos_.y};
			int CurrentSelect = 0; 
			do
			{
				CurrentSelect = Random_->RandomInt(0, 7);

			} while (CurrentSelect == PastSelect);
			switch (CurrentSelect)
			{
			case 0:
				NewText->MinMaxPos_.push_back(float4{ 0 , -VectorSpeed });
				break;
			case 1:
				NewText->MinMaxPos_.push_back(float4{ VectorSpeed , -VectorSpeed });
				break;
			case 2:
				NewText->MinMaxPos_.push_back(float4{ VectorSpeed, 0 });
				break;
			case 3:
				NewText->MinMaxPos_.push_back(float4{ VectorSpeed, VectorSpeed });
				break;
			case 4:
				NewText->MinMaxPos_.push_back(float4{ 0 , VectorSpeed });
				break;
			case 5:
				NewText->MinMaxPos_.push_back(float4{ -VectorSpeed, VectorSpeed });
				break;
			case 6:
				NewText->MinMaxPos_.push_back(float4{ -VectorSpeed, 0 });
				break;
			case 7:
				NewText->MinMaxPos_.push_back(float4{ -VectorSpeed, -VectorSpeed });
				break;
			default:
				break;
			}
			PastSelect = CurrentSelect;
			NewText->MovePos_.push_back(Pos);
		}
		NewText->CharSize_ = _CharSize;
		//NewText->Color_ = _Color;
	}
	TextQueue_.push_back(NewText);
}

void AlphabetManager::ViewText(TextQueue* _TextQueue)
{

	for (size_t i = 0; i < _TextQueue->UpperText_.size(); i++)
	{
		GameEngine::BackBufferImage()->TransCopy(AlphabetSheet_, _TextQueue->MovePos_[i], _TextQueue->CurrentCharSize_, Alphabet_[_TextQueue->UpperText_[i]], {DotSizeX, DotSizeY}, RGB(255, 0, 255));
	}

}
TextQueue::TextQueue()
	: CurrentInterTime_(0.0f)
	, End_(false)
	, CurrentCharSize_(float4::ZERO)
	, State_(TextQueueState::BigbySmall)
	, Color_(AlphabetColor::White)
{

}
TextQueue::~TextQueue()
{

}

void TextQueue::DancingAlphabet(float _Speed)
{
	for (size_t i = 0; i < MovePos_.size(); i++)
	{
		MovePos_[i] += (MinMaxPos_[i] * GameEngineTime::GetDeltaTime(0) * _Speed);
	}
}

bool TextQueue::SizeUp()
{
	float XIndex = CharSize_.x / 25;
	float YIndex = CharSize_.y / 25;
	CurrentCharSize_.x += XIndex;
	CurrentCharSize_.y += YIndex;
	for (float4& Iter : MovePos_)
	{
		Iter.x = Iter.x - XIndex / 2;
		Iter.y = Iter.y - YIndex / 2;
	}
	if (CharSize_.x < CurrentCharSize_.x)
	{
		CurrentCharSize_.x = CharSize_.x;
		CurrentCharSize_.y = CharSize_.y;
		return true;
	}
	if (CharSize_.y < CurrentCharSize_.y)
	{
		CurrentCharSize_.x = CharSize_.x;
		CurrentCharSize_.y = CharSize_.y;
		return true;
	}
	return false;

}

bool TextQueue::SizeDown()
{
	float XIndex = CharSize_.x / 25;
	float YIndex = CharSize_.y / 25;
	CurrentCharSize_.x -= XIndex;
	CurrentCharSize_.y -= YIndex;
	for (float4& Iter : MovePos_)
	{
		Iter.x = Iter.x + XIndex / 2;
		Iter.y = Iter.y + YIndex / 2;
	}
	if (0 > CurrentCharSize_.x)
	{
		CurrentCharSize_.x = 0;
		CurrentCharSize_.y = 0;
		return true;
	}
	if (0 > CurrentCharSize_.y)
	{
		CurrentCharSize_.x = 0;
		CurrentCharSize_.y = 0;
		return true;
	}

	return false;
}