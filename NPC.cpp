#include "NPC.h"

#include <iostream>
using namespace std;

unsigned int NPC::GetDamage()
{
    return damage;
}

unsigned int NPC::GetHealth()
{
    return health;
}

void NPC::SetHealth(unsigned int health)
{
    this->health = health;
}

void NPC::GetInfo()
{
    cout << "имя: " << name << endl;
    cout << "здоровье: " << health << endl;
    cout << "урон: " << damage << endl;
    cout << "уровень: " << lvl << endl;
    cout << "броня: " << armor << endl;
}

void NPC::Create()
{}

void NPC::LvlUp()
{
    cout << name << " получил новый уровень" << endl;
    lvl;
    Relaculate();
}

void NPC::Relaculate()
{
    damage += (1 + lvl * 0.1);
    health += (1 + lvl * 0.1);
    armor += (1 + lvl * 0.1);
}

void TakeDamage(NPC* npc, unsigned int damage)
{
    npc->SetHealth(npc->GetHealth() - damage);
    cout << "Вам нанесли урон: " << endl;
    cout << "Оставшееся здоровье = " << npc->health << endl;
}