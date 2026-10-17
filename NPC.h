#include <iostream> 
#include<vector>
using namespace std;

class NPC
{
protected:
	string name{ "npc" };
	unsigned int damage{ 2 };
	unsigned int health{ 5 };
	short lvl = 1;
	unsigned int armor = 2;
private:
	bool isEnemy = true;
public:
	unsigned int GetDamage() { return damage; };
	unsigned int GetHealth() { return health; }; // геттер
	void SetHealth(unsigned int health) { this->health = health; }; // сеттер

	void GetInfo()
	{
		cout << "имя: " << name << endl;
		cout << "здоровье: " << health << endl;
		cout << "урон: " << damage << endl;
		cout << "уровень: " << lvl << endl;
		cout << "броня: " << armor << endl;
	};
	virtual void Create() {}; // one metod virtual -> whole class virtual
	void LvlUp()
	{
		cout << name << " получил новый уровень" << endl;
		lvl;
		Relaculate();
	}
	void Relaculate() //кастомизировать для воина и волшебника зависимости от интеллекта/силы
	{
		damage += (1 + lvl * 0.1);
		health += (1 + lvl * 0.1);
		armor += (1 + lvl * 0.1);
	}


	friend void TakeDamage(NPC* npc, unsigned int damage);

	virtual~NPC() = default;
};