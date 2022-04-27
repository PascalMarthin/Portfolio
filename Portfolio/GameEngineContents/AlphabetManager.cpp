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
		Alphabet_['A'] = { 0, 0 };
		Alphabet_['B'] = { DotSizeX * 1,  0};
		Alphabet_['C'] = { DotSizeX * 2,  0};
		Alphabet_['D'] = { DotSizeX * 3,  0};
		Alphabet_['E'] = { DotSizeX * 4,  0};
		Alphabet_['F'] = { DotSizeX * 5,  0};
		Alphabet_['G'] = { DotSizeX * 6,  0};
		Alphabet_['H'] = { DotSizeX * 7,  0};
		Alphabet_['I'] = { DotSizeX * 8,  0};
		Alphabet_['L'] = { DotSizeX * 9,  0};
		Alphabet_['M'] = { DotSizeX * 10, 0};
		Alphabet_['N'] = { DotSizeX * 11, 0 };
		Alphabet_['O'] = { DotSizeX * 12, 0 };
		Alphabet_['R'] = { DotSizeX * 13, 0 };
		Alphabet_['S'] = { DotSizeX * 14, 0 };
		Alphabet_['T'] = { DotSizeX * 15, 0 };
		Alphabet_['U'] = { DotSizeX * 16, 0 };
		Alphabet_['V'] = { DotSizeX * 17, 0 };
		Alphabet_['W'] = { DotSizeX * 18, 0 };
		Alphabet_['X'] = { DotSizeX * 19, 0 };
	}
	AlphabetSheet_ = GameEngineImageManager::GetInst()->Find("Alphabet_sheet.bmp");
	
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

void AlphabetManager::SetText(const float4& _Pos /*LU*/, const std::string& _Text, const float4& _CharSize /*const AlphabetColor _Color*/)
{
	MaxRange_ = 15.0f;
	MoveRange_ = 0.0f;
	Speed_ = 12.0f;
	AddSpeed_ = 0.5f;
	TextQueue* NewText = new TextQueue();
	{

		int PastSelect = 10;
		NewText->Pos_ = { _Pos.x - (_Text.size() / 2) * _CharSize.x - (_Text.size() % 2 == 0 ? 0.0f : _CharSize.Half().x) , _Pos.y - _CharSize.Half().y};
		// 대문자로 변환
		NewText->CurrentInterTime_ = 0.01f;
		NewText->UpperText_ = GameEngineString::ToUpperReturn(_Text);
		for (size_t i = 0; i < _Text.size(); i++)
		{
			// 중앙으로 위치 변경(중앙에 출력되도록 변경)
			float4 Pos = { NewText->Pos_.x + (_CharSize.x * i) , NewText->Pos_.y};
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