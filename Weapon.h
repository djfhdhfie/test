#pragma once
#include <string>
#include "Enums.h"

struct Weapon
{
	std::string name{ "weapon" };
	unsigned int damage{ 1 };
	WeaponQuality quality{ WeaponQuality::Common }; // Поле качества
};
