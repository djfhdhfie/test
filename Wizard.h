#include <iostream> 
#include<vector>
#include "NPC.h"
#include "Spell.h"

class Wizard : virtual public NPC
{
protected:
	short intellect{ 29 };
	vector<Spell> spells;
public:
	Wizard(){};
	void Create() override{};
	void GetInfo(){};
	void LearnSpell(){};

	void Relaculate() {};
	~Wizard() {};
};