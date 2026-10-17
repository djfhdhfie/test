#pragma once
class Player
{
private:
	unique_ptr<NPC> currentCharacter{ nullptr }; // сам будет очищаться, если не будем пользоваться
public:
	void Create(unique_ptr<NPC> character)
	{
		currentCharacter = move(character);
		currentCharacter->Create();
	}
	NPC* GetCharacter()
	{
		return currentCharacter.get();
	}
	/*
	void GetInfo(unique_ptr<NPC> character) // ДЗ: СДЕЛАТЬ ДРУЖ.МЕТОД
	{
		currentCharacter.swap(, Wizard);



	};
	*/
};