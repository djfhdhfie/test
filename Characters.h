#pragma once
#include <vector>
#include <iostream>
#include "NPC.h"
#include "Weapon.h"
#include "Enums.h"

class Warrior : virtual public NPC {};

class Wizard : virtual public NPC {};

class Evil : public NPC {};

class Paladin : public Warrior, public Wizard {};

class Archer : virtual public NPC {};

class Rogue : virtual public NPC {};


//сюда классы Warrior, Wizard, Evil, Paladin, Archer, Rogue
//в них должен использоваться std::string и std::vector (или добавьте using namespace std; в начале этого файла)