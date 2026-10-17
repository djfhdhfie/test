#include <iostream> 
#include<vector>
#include "NPC.h"
#include "Warrior.h"

//конструктор по умолчанию
Warrior::Warrior()
{
	//cout << "конструктор война" << endl;
	damage = 20;
	health = 30;
	armor = 15;
	//Create(); (чтобы создавалсяя только Паладин, убираем это)
};
//кастомный конструктор
Warrior::Warrior(string name, unsigned int lvl)
{
	damage = 20;
	health = 30;
	armor = 15;
	this->name = name; //такой способ задания поля уместен только для сеттер
	for (size_t i = 0; i < lvl; i++)
	{
		LvlUp();
	}
	//this->lvl = lvl; //this - указывает на конкретный экземпляр класса
}
void Warrior::Create()
{
	cout << "Вы создали война\nЗадайте имя игрока\n" << endl;
	cin >> name;

	GetInfo();
	GetWeapon();
};
void Warrior::GetInfo()
{
	NPC::GetInfo();
	cout << "сила: " << strength << endl;
};
void Warrior::GetWeapon()
{
	Weapon weapon;
	weapon.damage = 1;
	weapon.name = "кулаки";
	weapons.push_back(weapon);

	cout << name << " взял в руки оружие " << weapons[0].name << endl;
	cout << " добавка к урону = " << weapons[0].damage << endl;
};

void Warrior::Relaculate() {
	NPC::Relaculate();
	damage += strength / 10;
	health += strength / 5;
}
Warrior::~Warrior() //деструктор (вызывается сам в момент высвобождения памяти экземпляра)
{
	cout << name << " пал смертью храбрых" << endl;
}