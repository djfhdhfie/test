#pragma once
class Paladin : public Warrior, public Wizard {
public:
	Paladin()
	{
		intellect = 25;
		strength = 19;
		health = 25;
		damage = 25;

		Create(); // теперь вызывается сам Паладин

	}
	void Create() override
	{
		// realizyite v Npc 
		cout << "Вы создали паладина \nЗадайте имя игрока\n" << endl;
		cin >> name;

		GetInfo();
		GetWeapon();
		LearnSpell();
	};
	void GetInfo()
	{
		Warrior::GetInfo();
		cout << "интеллект: " << intellect << endl;
	};
	~Paladin() {
		cout << "отошел в мир иной..." << endl;
	}
};