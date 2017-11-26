#include <iostream>
using namespace std;

class Character{
public:
	string name;
	string description;
	int attack;
	int defense;
	int health;
	int speed;
	int gold;

	void setName(string n);
	void setDescription(string d);
	void setAttack(int a);
	void setDefense(int def);
	void setHealth(int h);
	void setSpeed(int spe);
	void setGold(int g);

	string getName();
	string getDescription();
	int getAttack();
	int getDefense();
	int getHealth();
	int getSpeed();
	int getGold();
	
	void describeCharacter();

	~Character(){
	}
};

void battle(Character&, Character&);
void playerBought(Character&, Character&);
void shop(Character&, Character&, Character&, Character&, Character backpack[10]);
void addBackpack(Character backpack[10], Character&);
void deleteBackpack(Character backpack[10]);
void addEquipped(Character backpack[10], Character equipped[3]);
void deleteEquipped(Character equipped[3]);