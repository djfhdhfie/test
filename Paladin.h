#pragma once

#include "Warrior.h"
#include "Wizard.h"

// множественное наследование
class Paladin : public Warrior, public Wizard
{
public:
    Paladin();

    void Create() override;

    void GetInfo();

    ~Paladin();
};