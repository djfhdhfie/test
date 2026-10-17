#include <iostream> 
#include<vector>
#include "NPC.h"
#include "Wizard.h"
Wizard::Wizard()//конструктор вызывается в момент создания экземпляра
{
	//cout << "конструктор волшебник" << endl;
	damage = 27;
	health = 21;
	armor = 10;
	for (size_t i = 0; i < lvl; i++)
	{
		LvlUp();
	}
	//this->lvl = lvl; //this - указывает на конкретный экземпляр класса
	//Create(); (чтобы создавался только Паладин, убираем это)
}
void Wizard::Create()
{
	cout << "Вы создали волшебник\nЗадайте имя игрока\n" << endl;
	cin >> name;

	GetInfo();
	LearnSpell();
};
void Wizard::GetInfo()
{
	NPC::GetInfo();
	cout << "интеллект: " << intellect << endl;
};
void Wizard::LearnSpell()
{
	Spell spell;
	spell.damage = 2;
	spell.name = "вспышка";
	spells.push_back(spell);

	cout << name << " изучил заклинание " << spells[0].name << endl;
	cout << " добавка к урону = " << spells[0].damage << endl;
};

void Wizard::Relaculate() {
	NPC::Relaculate();
	damage += intellect / 10;
}
Wizard::~Wizard()
{
	cout << name << " испускает дух" << endl;
}
