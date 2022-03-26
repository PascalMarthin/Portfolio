#include "GamePlayTextObject.h"

// Ό³Έν :
class Hot_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Hot_Text();
	~Hot_Text();

	// delete Function
	Hot_Text(const Hot_Text& _Other) = delete;
	Hot_Text(Hot_Text&& _Other) noexcept = delete;
	Hot_Text& operator=(const Hot_Text& _Other) = delete;
	Hot_Text& operator=(Hot_Text&& _Other) noexcept = delete;

protected:

private:
	

};

