#include "Paladin.h"

#include <iostream>

Paladin::Paladin()
{
    intellect = 25;
    strength = 19;
    health = 25;
    damage = 25;

    Create(); // теперь вызывается сам Паладин
}

void Paladin::Create()
{
    std::cout << "Вы создали паладина \nЗадайте имя игрока\n" << std::endl;
    std::cin >> name;

    GetInfo();
    GetWeapon();
    LearnSpell();
}

void Paladin::GetInfo()
{
    Warrior::GetInfo();
    std::cout << "интеллект: " << intellect << std::endl;
}

Paladin::~Paladin()
{
    std::cout << "отошел в мир иной..." << std::endl;
}