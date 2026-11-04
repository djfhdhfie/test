#pragma once
#include <string>

enum class CharacterType { Warrior = 1, Wizard = 2, Paladin = 3, Archer = 4, Rogue = 5 };
enum class WeaponQuality { Common = 1, Uncommon, Rare, Epic, Legendary };

std::string GetQualityName(WeaponQuality quality);