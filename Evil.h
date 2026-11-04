#pragma once
#include <iostream>
#include <string>
#include "NPC.h"
#include "Characters.h"

class Evil : public NPC
{
public:
	Evil()
	{
		name = "Злодей";
		health = 10;
		damage = 5;
		armor = 3;
	}

	//делегирование конструкторов
	Evil(std::string name) : Evil()
	{
		this->name = name;
	}

	Evil(std::string name, unsigned int damage) : Evil(name)
	{
		this->damage = damage;
	}

	Evil(std::string name, unsigned int damage, unsigned int health) : Evil(name, damage)
	{
		this->health = health;
	}

	Evil(std::string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health)
	{
		this->armor = armor;
	}

	~Evil()
	{
		std::cout << name << " упал в обморок" << std::endl;
	}
};