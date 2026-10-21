#pragma once

#include <string>
#include <vector>

#include "NPC.h"

struct Spell
{
    std::string name{ "spell" };
    unsigned int damage{ 1 };
};

class Wizard : virtual public NPC
{
protected:
    short intellect{ 29 };
    std::vector<Spell> spells;

public:
    Wizard(); // конструктор вызывается в момент создания экземпляра

    void Create() override;

    void GetInfo();

    void LearnSpell();

    void Relaculate();

    ~Wizard();
};