#include "Rogue.h"
#include <iostream>
#include "Enums.h"

Rogue::Rogue()
{
	name = "Разбойник";
	damage = 25;
	health = 18;
	armor = 5;
}

void Rogue::Create()
{
	std::cout << "Вы создали разбойника\nЗадайте имя игрока\n" << std::endl;
	std::cin >> name;
	GetInfo();
	GetWeapon();
}

void Rogue::GetInfo()
{
	NPC::GetInfo();
	std::cout << "скрытность: " << stealth << std::endl;
}

void Rogue::GetWeapon()
{
	Weapon dagger;
	dagger.damage = 12;
	dagger.name = "Отравленный кинжал";
	dagger.quality = WeaponQuality::Legendary;
	weapons.push_back(dagger);

	std::cout << name << " взял в руки оружие " << weapons[0].name << std::endl;
	std::cout << "Качество оружия: " << GetQualityName(weapons[0].quality) << std::endl;
}

void Rogue::Relaculate()
{
	NPC::Relaculate();
	damage += stealth / 10;
}

Rogue::~Rogue()
{
	std::cout << name << " скрылся в тенях" << std::endl;
}