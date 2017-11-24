#include <iostream>
using namespace std;

class Character{
public:
	string name;
	int attack;
	int defense;
	int health;
	int speed;
	int gold;

	void setName(string n);
	void setAttack(int a);
	void setDefense(int def);
	void setHealth(int h);
	void setSpeed(int spe);
	void setGold(int g);

	string getName();
	int getAttack();
	int getDefense();
	int getHealth();
	int getSpeed();
	int getGold();

	~Character(){
	}
};

class Room{
public:
	string name;
	string description;
	bool north;
	bool east;
	bool south;
	bool west;

	void setName(string n);
	void setDescription(string d);
	void setNorth(bool no);
	void setEast(bool s);
	void setSouth(bool e);
	void setWest(bool w);

	string getName();
	string getDescription();
	bool getNorth();
	bool getEast();
	bool getSouth();
	bool getWest();
	void describeRoom();
};

void battle(Character&, Character&);
void playerBought(Character&, Character&);
void shop(Character&, Character&, Character&, Character&);