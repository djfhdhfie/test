#pragma once
#include <vector>
#include <string>
#include "NPC.h"
#include "Weapon.h"

class Archer : virtual public NPC
{
protected:
	short agility{ 25 };
	std::vector<Weapon> weapons;

public:
	Archer(); // Конструктор (без тела)

	// Переопределенные методы (обрати внимание на override, без тела)
	void Create() override;
	void GetInfo();
	void Relaculate();

	// Собственный метод
	void GetWeapon();

	~Archer(); // Деструктор
};