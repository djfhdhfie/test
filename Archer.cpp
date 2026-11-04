#include "Archer.h"
#include <iostream>
#include "Enums.h" //для WeaponQuality и GetQualityName

Archer::Archer()
{
	name = "Лучник";
	damage = 15;
	health = 25;
	armor = 10;
}

void Archer::Create()
{
	std::cout << "Вы создали лучника\nЗадайте имя игрока\n" << std::endl;
	std::cin >> name;
	GetInfo();
	GetWeapon();
}

void Archer::GetInfo()
{
	NPC::GetInfo();
	std::cout << "ловкость: " << agility << std::endl;
}

void Archer::GetWeapon()
{
	Weapon bow;
	bow.damage = 8;
	bow.name = "Длинный лук";
	bow.quality = WeaponQuality::Common;
	weapons.push_back(bow);

	std::cout << name << " взял в руки оружие " << weapons[0].name << std::endl;
	std::cout << "Качество оружия: " << GetQualityName(weapons[0].quality) << std::endl;
}

void Archer::Relaculate()
{
	NPC::Relaculate();
	damage += agility / 10;
}

Archer::~Archer()
{
	std::cout << name << " сдался без боя" << std::endl;
}