#pragma once
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
	Evil(string name) : Evil() //делегирование конструктора (то есть вызовется вначале базовый)
	{
		this->name = name;
	}
	Evil(string name, unsigned int damage) : Evil(name)
	{
		this->damage = damage;
	}
	Evil(string name, unsigned int damage, unsigned int health) : Evil(name, damage)
	{
		this->health = health;
	}
	Evil(string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health)
	{
		this->armor = armor;
	}

	~Evil()
	{
		cout << name << " упал в обморок" << endl;
	}
	//придумать интересный деструктор для злодеев
};