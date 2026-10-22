#include <iostream> 
#include<vector>
using namespace std;
//ключевые понятия (принципы) ООП:
//1) наследование
//2) полиморфизм
//3) абстракция
//4) инкапсуляция (геттер and сеттер)

// public - везде
// protected - можно в наследледуеммых или в исходнном
// private - толюко в исходном, не наследуется

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

	virtual void GetInfo()
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

struct Weapon
{
	string name{ "weapon" };
	unsigned int damage{ 1 };
	WeaponQuality quality{ WeaponQuality::Common }; //поле качества
};

class Warrior : virtual public NPC
{
protected:
	short strength{ 21 };
	vector<Weapon> weapons;
public:
	//конструктор по умолчанию
	Warrior()
	{
		//cout << "конструктор война" << endl;
		damage = 20;
		health = 30;
		armor = 15;
		//Create(); (чтобы создавалсяя только Паладин, убираем это)
	}
	//кастомный конструктор
	Warrior(string name, unsigned int lvl)
	{
		damage = 20;
		health = 30;
		armor = 15;
		this->name = name; //такой способ задания поля уместен только для сеттер
		for (size_t i = 0; i < lvl; i++)
		{
			LvlUp();
		}
		//this->lvl = lvl; //this - указывает на конкретный экземпляр класса
	}
	void Create() override
	{
		cout << "Вы создали война\nЗадайте имя игрока\n" << endl;
		cin >> name;
		GetInfo();
		GetWeapon();
	}
	virtual void GetInfo()
	{
		NPC::GetInfo();
		cout << "сила: " << strength << endl;
	};
	void GetWeapon()
	{
		Weapon weapon;
		weapon.damage = 5;
		weapon.name = "Стальной меч";
		weapon.quality = WeaponQuality::Rare;
		weapons.push_back(weapon);

		cout << name << " взял в руки оружие " << weapons[0].name << endl;
		cout << "Качество оружия: " << GetQualityName(weapons[0].quality) << endl;
	}

	void Relaculate() {
		NPC::Relaculate();
		damage += strength / 10;
		health += strength / 5;
	}
	~Warrior() //деструктор (вызывается сам в момент высвобождения памяти экземпляра)
	{
		cout << name << " пал смертью храбрых" << endl;
	}
};

struct Spell
{
	string name{ "spell" };
	unsigned int damage{ 1 };
};

class Wizard : virtual public NPC
{
protected:
	short intellect{ 29 };
	vector<Spell> spells;
public:
	Wizard()//конструктор вызывается в момент создания экземпляра
	{
		//cout << "конструктор волшебник" << endl;
		damage = 27;
		health = 21;
		armor = 10;
		for (size_t i = 0; i < lvl; i++)
		{
			LvlUp();
		}
		//this->lvl = lvl; //this - указывает на конкретный экземпляр класса
		//Create(); (чтобы создавался только Паладин, убираем это)
	}
	void Create() override
	{
		cout << "Вы создали волшебник\nЗадайте имя игрока\n" << endl;
		cin >> name;

		GetInfo();
		LearnSpell();
	};
	virtual void GetInfo()
	{
		NPC::GetInfo();
		cout << "интеллект: " << intellect << endl;
	};
	void LearnSpell()
	{
		Spell spell;
		spell.damage = 2;
		spell.name = "вспышка";
		spells.push_back(spell);

		cout << name << " изучил заклинание " << spells[0].name << endl;
		cout << " добавка к урону = " << spells[0].damage << endl;
	};

	void Relaculate() {
		NPC::Relaculate();
		damage += intellect / 10;


	}
	~Wizard()
	{
		cout << name << " испускает дух" << endl;
	}
};

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

//множественное наследование
class Paladin : public Warrior, public Wizard {
public:
	Paladin()
	{
		intellect = 25;
		strength = 19;
		health = 25;
		damage = 25;

		//Create(); // теперь вызывается сам Паладин

	}
	void Create() override
	{
		// realizyite v Npc 
		cout << "Вы создали паладина \nЗадайте имя игрока\n" << endl;
		cin >> name;

		GetInfo();
		GetWeapon();
		LearnSpell();
	};
	void GetInfo()
	{
		Warrior::GetInfo();
		cout << "интеллект: " << intellect << endl;
	};
	void Relaculate() {
		Warrior::Relaculate();
		Wizard::Relaculate();
	}
	~Paladin() {
		cout << "отошел в мир иной..." << endl;
	}
};

//дружественные классы
class Player
{
private:
	unique_ptr<NPC> currentCharacter{nullptr}; // сам будет очищаться, если не будем пользоваться
public:
	void Create(unique_ptr<NPC> character)
	{
		currentCharacter = move(character);
		currentCharacter->Create();
	}
	NPC* GetCharacter()
	{
		return currentCharacter.get();
	}
	/*
	void GetInfo(unique_ptr<NPC> character) // ДЗ: СДЕЛАТЬ ДРУЖ.МЕТОД
	{
		currentCharacter.swap(, Wizard);

		

	};
	*/
};

void TakeDamage(NPC* npc, unsigned int damage)
{
	npc->SetHealth(npc->GetHealth() - damage); //npc.health - можно благодаря тому, что дружественный класс (напрямую)
	cout << "Вам нанесли урон: " << endl;
	cout << "Оставшееся здоровье = " <<npc->health << endl;
}


class Archer : virtual public NPC
{
protected:
	short agility{ 25 };
	vector<Weapon> weapons;
public:
	Archer()
	{
		name = "Лучник";
		damage = 15;
		health = 25;
		armor = 10;
	}
	void Create() override
	{
		cout << "Вы создали лучника\nЗадайте имя игрока\n" << endl;
		cin >> name;
		GetInfo();
		GetWeapon();
	};
	void GetInfo() override
	{
		NPC::GetInfo();
		cout << "ловкость: " << agility << endl;
	};
	void GetWeapon()
	{
		Weapon bow;
		bow.damage = 8;
		bow.name = "Длинный лук";
		bow.quality = WeaponQuality::Common;
		weapons.push_back(bow);

		cout << name << " взял в руки оружие " << weapons[0].name << endl;
		cout << "Качество оружия: " << GetQualityName(weapons[0].quality) << endl;
	};
	void Relaculate() {
		NPC::Relaculate();
		damage += agility / 10;
	}
	~Archer() { cout << name << " сдался без боя" << endl; }
};

class Rogue : virtual public NPC
{
protected:
	short stealth{ 30 };
	vector<Weapon> weapons;
public:
	Rogue()
	{
		name = "Разбойник";
		damage = 25;
		health = 18;
		armor = 5;
	}
	void Create() override
	{
		cout << "Вы создали разбойника\nЗадайте имя игрока\n" << endl;
		cin >> name;
		GetInfo();
		GetWeapon();
	};
	void GetInfo() override
	{
		NPC::GetInfo();
		cout << "скрытность: " << stealth << endl;
	};
	void GetWeapon()
	{
		Weapon dagger;
		dagger.damage = 12;
		dagger.name = "Отравленный кинжал";
		dagger.quality = WeaponQuality::Legendary;
		weapons.push_back(dagger);

		cout << name << " взял в руки оружие " << weapons[0].name << endl;
		cout << "Качество оружия: " << GetQualityName(weapons[0].quality) << endl;
	};
	void Relaculate() {
		NPC::Relaculate();
		damage += stealth / 10;
	}
	~Rogue() { cout << name << " скрылся в тенях" << endl; }
};


enum class CharacterType {
	Warrior = 1, // Воин
	Wizard = 2,    // Маг
	Paladin = 3,  // Паладин
	Archer = 4,   //Лучник
	Rogue = 5    // Разбойник
};

enum class WeaponQuality {
	Common,    // Обычное
	Rare,      // Редкое
	Epic,      // Эпическое
	Legendary  // Легендарное
};

// Вспомогательная функция для вывода качества оружия в консоль
string GetQualityName(WeaponQuality quality) {
	switch (quality) {
	case WeaponQuality::Common: return "Обычное";
	case WeaponQuality::Rare: return "Редкое";
	case WeaponQuality::Epic: return "Эпическое";
	case WeaponQuality::Legendary: return "Легендарное";
	default: return "Неизвестно";
	}
}

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Rus");

	Player player;


	cout << "Присядь путник у костра и расскажи, кто ты: " << endl;
	cout << "\t1 - воин\n\t2 - волшебник\n\t3 - паладин" << endl;
	short choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1:
		player.Create(make_unique<Warrior>());
		break;
	case 2:
		player.Create(make_unique<Wizard>());
		break;
	case 3:
		player.Create(make_unique<Paladin>());
		break;
	default:
		cout << "Таких ***** героев еще не было в наших краях.\nПопытай удачу в поле!" << endl;
	}

	//TakeDamage


	/*
	Warrior* warrior = new Warrior("друг война", 5); //как только создал новый экземпляр, для него вызвался конструктор
	warrior->GetInfo(); //стрелка работает с указателями (ссылка). Через точку - напрямую.
	cout << warrior->GetHealth();
	delete warrior;
	warrior = nullptr;

	Wizard wizard;
	*/


	//Paladin paladin;


	// превратить злодеев в вектор (указателей, умных)
	/*
	vector <unique_ptr <Evil>> evils;

	evils.push_back(make_unique<Evil>());
	evils.push_back(make_unique<Evil>("Скелет"));
	evils.push_back(make_unique<Evil>("Рыцарь", 12));
	evils.push_back(make_unique<Evil>("Дитя дракона", 15, 20));
	evils.push_back(make_unique<Evil>("Батя дракон", 50, 100, 200));

	for (auto& evil : evils)
		evil->GetInfo();
	*/






	return 0;
}


//ДЗ с 08.09: drawio (дорисовать диаграммку, добавить в репозиторий




//===================================== ТЕМА 22.10.26: enum class =====================================
/*
1)enum class - специальный тип данных, который помогает определить именованный набор констант (ограниченный список понятный имен). Например, дни недели, варианты цветов, статусы заказа).
2)отличие enum class от обычного enum:
enum:
- имена перечислений могут просочиться в глобальную область видимости или область блока, где объявлен enum (может возникнуть конфликт имен).
- значения enum неявно преобразуются в целочисленные типы (обычно int). Удобно, но небезопасно, т.к можно случайно сравнить значения из несвязанных перечислений.
enum class:
- инкапсуляция перечислителей: перечислители живут внутри самого типа enum class и доступны только через идентификатор (color::red) - решает проблему конфликтов имен и делает код более читаемым.
- отсутствия неявного преобразования в int. Значения enum class нельзя неявно присвоить целочисленной переменной. Для такого преобразования требуется явное приведение, например, с помощью static_cast<int>. Это повышает безопасность типов.
- явное указание базового типа. Можно явно задать целочисленный тип для хранения значений (например, std::uint8_t, std::uint16_t), что полезно для экономии памяти или при работе с сериализацией.
- отсутствие неявного вывода в потоки. Значения enum class нельзя напрямую вывести в поток std::cout — требуется явное приведение к типу, поддерживающему поток.
3)«Магические числа» — это числа, вписанные в код напрямую, смысл которых непонятен без контекста (например, if (userState == 3)).
Использование перечислений дает следующие плюсы:
•	Читаемость и самодокументируемость: Код if (userState == State::Blocked) говорит сам за себя, в отличие от if (userState == 3).
•	Удобство поддержки (Maintainability): Если потребуется изменить числовое значение константы, это делается в одном месте (в объявлении enum), и не нужно бегать по всему коду и менять цифры.
•	Безопасность типов: Компилятор не позволит передать в функцию бессмысленное число, если она ожидает конкретный тип перечисления. Это отсекает целый класс ошибок.
•	Рефакторинг: Современные IDE (среды разработки) могут автоматически находить все места использования конкретной именованной константы.
4)как значения перечисления связаны с целыми числами и как получить/задать числовое значение:
Под капотом каждое значение перечисления хранится как целое число.
•	По умолчанию: Первому элементу присваивается 0, второму 1 и так далее. Вы также можете задать значения явно при объявлении: enum class Code { Ok = 200, NotFound = 404 };.
•	Получить числовое значение: Из-за строгой типизации enum class не приводится к числу неявно. Чтобы получить число, нужно использовать явное приведение типов: int value = static_cast<int>(Code::NotFound); (получим 404).
•	Задать числовое значение (создать из числа): Чтобы сделать значение перечисления из числа, также используется приведение: Code c = static_cast<Code>(200);. Важно: при этом компилятор не проверяет, существует ли такое значение в перечислении, поэтому ответственность за корректность лежит на программисте.

*/




