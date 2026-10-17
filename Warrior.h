#include <iostream> 
#include<vector>
#include "NPC.h"
#include "Weapon.h"

using namespace std;

class Warrior : virtual public NPC
{
protected:
	short strength{ 21 };
	vector<Weapon> weapons;
public:
	//конструктор по умолчанию
	Warrior() {};
	//кастомный конструктор
	Warrior(string name, unsigned int lvl) {};
	void Create() override{};
	void GetInfo(){};
	void GetWeapon(){};

	void Relaculate() {};
	~Warrior() {};
};