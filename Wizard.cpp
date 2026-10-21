#include "Wizard.h"

#include <cstddef>
#include <iostream>

Wizard::Wizard()
{
    damage = 27;
    health = 21;
    armor = 10;

    for (std::size_t i = 0; i < static_cast<std::size_t>(lvl); ++i)
    {
        LvlUp();
    }
}

void Wizard::Create()
{
    std::cout << "Вы создали волшебник\nЗадайте имя игрока\n" << std::endl;
    std::cin >> name;

    GetInfo();
    LearnSpell();
}

void Wizard::GetInfo()
{
    NPC::GetInfo();
    std::cout << "интеллект: " << intellect << std::endl;
}

void Wizard::LearnSpell()
{
    Spell spell;
    spell.damage = 2;
    spell.name = "вспышка";
    spells.push_back(spell);

    std::cout << name << " изучил заклинание " << spells[0].name << std::endl;
    std::cout << " добавка к урону = " << spells[0].damage << std::endl;
}

void Wizard::Relaculate()
{
    NPC::Relaculate();
    damage += intellect / 10;
}

Wizard::~Wizard()
{
    std::cout << name << " испускает дух" << std::endl;
}