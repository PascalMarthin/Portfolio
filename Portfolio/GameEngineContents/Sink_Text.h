#include "GamePlayTextObject.h"

// Ό³Έν :
class Sink_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Sink_Text();
	~Sink_Text();

	// delete Function
	Sink_Text(const Sink_Text& _Other) = delete;
	Sink_Text(Sink_Text&& _Other) noexcept = delete;
	Sink_Text& operator=(const Sink_Text& _Other) = delete;
	Sink_Text& operator=(Sink_Text&& _Other) noexcept = delete;

protected:

private:

};

