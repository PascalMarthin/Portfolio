#pragma once

// Ό³Έν :
class Destroy
{
public:
	// constrcuter destructer
	Destroy();
	~Destroy();

	// delete Function
	Destroy(const Destroy& _Other) = delete;
	Destroy(Destroy&& _Other) noexcept = delete;
	Destroy& operator=(const Destroy& _Other) = delete;
	Destroy& operator=(Destroy&& _Other) noexcept = delete;

protected:

private:

};

