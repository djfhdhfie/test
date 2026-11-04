#pragma once
#include <vector>
#include <string>
#include "NPC.h"
#include "Weapon.h"

class Rogue : virtual public NPC
{
protected:
	short stealth{ 30 };
	std::vector<Weapon> weapons;

public:
	Rogue();
	void Create() override;
	void GetInfo();
	void Relaculate();

	void GetWeapon();

	~Rogue();
};