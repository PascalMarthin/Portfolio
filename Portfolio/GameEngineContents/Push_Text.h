#include "GamePlayTextObject.h"

// ���� :
class Push_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Push_Text();
	~Push_Text();

	// delete Function
	Push_Text(const Push_Text& _Other) = delete;
	Push_Text(Push_Text&& _Other) noexcept = delete;
	Push_Text& operator=(const Push_Text& _Other) = delete;
	Push_Text& operator=(Push_Text&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update() override {}
	void Render() override {}
private:

};

