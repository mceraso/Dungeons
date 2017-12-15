#include <iostream>
using namespace std;

class Character{
public:
	Character();
	string name;
	string description;
	int attack;
	int defense;
	int health;
	int speed;
	int gold;
	
	void describeCharacter();

	~Character(){
	}
};

class Room{
public:
	Room();
	string name;
	string description;
	void describeRoom();

	bool battleBool;
	Character Monster;
	bool shopBool;
	Character shopGoods[3];

	void battle(Character&, Character equipped[3]);
	void shop(Character&, Character backpack[10]);

	~Room(){
	}

private:
	void playerBought(Character&, Character);

};

void addBackpack(Character backpack[10], Character);
void deleteBackpack(Character backpack[10]);
void addEquipped(Character backpack[10], Character equipped[3]);
void deleteEquipped(Character equipped[3]);