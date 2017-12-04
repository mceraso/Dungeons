#include <iostream>
#include "Dungeons.h"
using namespace std;

	//default constructor used
	/*Character::Character(){
	}*/

	//defining Character accessors
	void Character::setName(string n){
		name = n;
	}

	void Character::setDescription(string d){
		description = d;
	}

	void Character::setAttack(int a){
		attack = a;
	}

	void Character::setDefense(int def){
		defense = def;
	}

	void Character::setHealth(int h){
		health = h;
	}

	void Character::setSpeed(int spe){
		speed = spe;
	}

	void Character::setGold(int g){
		gold = g;
	}

	//defining Character mutators
	string Character::getName(){
		return name;
	}

	string Character::getDescription(){
		return description;
	}

	int Character::getAttack(){
		return attack;
	}

	int Character::getDefense(){
		return defense;
	}
	
	int Character::getHealth(){
		return health;
	}

	int Character::getSpeed(){
		return speed;
	}

	int Character::getGold(){
		return gold;
	}

	void Character::describeCharacter(){
		cout << "This is " << name << endl;
		cout << description << endl;
	}

	//defining battle function
	void battle(Character& Player, Character& Monster, Character equipped[3]){
		cout << endl << Player.name << ", you are approached by a " << Monster.getName() << endl;

		int eA = Player.getAttack();
		int eD = Player.getDefense();
		int eS = Player.getSpeed();
		int eH = Player.getHealth();
		for (int n = 0; n < 3; n ++){
			eA += equipped[n].getAttack();
			eD += equipped[n].getDefense();
			eS += equipped[n].getSpeed();
			eH += equipped[n].getHealth();
		}


		int x = 0;
		while (x == 0){
			bool netS = false;
			if (Monster.getSpeed() >= eS){
				netS = true;
				cout << "The " << Monster.getName() << " attacked you!" << endl;
				int netA = Monster.getAttack() - eD;
				if (netA < 0){
					netA = 1;
				}
				eH -= netA;
				if (eH <= 0){
					break;
				}				
			}

			cout << "What do you do?" << endl;
			cout << "Attack or Run" << endl;
			string i;
			getline(cin, i);
			cout << "----------------------------------------------------" << endl;;

			if (i == "Run"){
				cout << "You got away safely!" << endl;
				break;
			}
			else if (i == "Attack"){
				cout << "You attacked the " << Monster.getName() << "!" << endl;
				int netA = eA - Monster.getDefense();
				if (netA < 0){
					netA = 1;
				}
				Monster.setHealth(Monster.getHealth() - netA);
				if (Monster.getHealth() <= 0){
					break;
				}
			} 
			else {
				cout << "Enter a supported choice!" << endl;
			}
			if (netS == false){
				cout << "The " << Monster.getName() << " attacked you!" << endl;
				int netA = Monster.getAttack() - eD;
				if (netA <= 0){
					netA = 1;
				}
				eH -= netA;
				if (eH <= 0){
					break;
				}
			}	
		}

		if (eH <= 0){
			cout << "The " << Monster.getName() << " killed you!" << endl;
			cout << "Game Over" << endl;
			cout << "----------------------------------------------------" << endl;;
			Player.health = eH;
		}	

		else if (Monster.getHealth() <= 0){
			cout << "You killed the " << Monster.getName() << "!" << endl;
			cout << "Congratulations, " << Player.getName() << "! You won the game!" << endl;
			cout << "----------------------------------------------------" << endl;;			
		}
	}

	void playerBought(Character& Player, Character item){
		cout << "You bought the " << item.getName() << "!" << endl;
		cout << "Gold is decreased by " << item.getGold() << "." << endl;
		Player.setGold(Player.getGold() - item.getGold());

		cout << "When equipped, " << endl;
		if (item.getAttack() < 0){
			cout << "Attack is decreased by " << item.getAttack() << "." << endl;
		}
		else if (item.getAttack() > 0){
			cout << "Attack is increased by " << item.getAttack() << "." << endl;
		}
		else {
			cout << "Attack is unchanged." << endl;
		}
		if (item.getDefense() < 0){
			cout << "Defense is decreased by " << item.getDefense() << "." << endl;
		}
		else if (item.getDefense() > 0){
			cout << "Defense is increased by " << item.getDefense() << "." << endl;
		}
		else {
			cout << "Defense is unchanged." << endl;
		}
		if (item.getHealth() < 0){
			cout << "Health is decreased by " << item.getAttack() << "." << endl;
		}
		else if (item.getHealth() > 0){
			cout << "Health is increased by " << item.getAttack() << "." << endl;
		}
		else {
			cout << "Health is unchanged." << endl;
		}
		if (item.getSpeed() < 0){
			cout << "Speed is decreased by " << item.getSpeed() << "." << endl;
		}
		else if (item.getSpeed() > 0){
			cout << "Speed is increased by " << item.getSpeed() << "." << endl;
		}
		else {
			cout << "Speed is unchanged." << endl;
		}			
		cout << "Thank you!" << endl << endl;
	}

	void shop(Character& Player, Character item1, Character item2, Character item3, Character backpack[10]){
		cout << endl << "Welcome to the shop!" << endl;
		cout << "Looks like you have " << Player.getGold() << " Gold" << endl;
		if (Player.getGold() <= 0){
			cout << "Go get more Gold!" << endl;
			return;
		}

		int x = 0;
		while (x == 0){
			cout << "What would you like?" << endl;
			cout << item1.getName() << " for " << item1.getGold() << " Gold" << endl;
			cout << item2.getName() << " for " << item2.getGold() << " Gold" << endl;
			cout << item3.getName() << " for " << item3.getGold() << " Gold" << endl;
			cout << "Nothing" << endl;

			string a;
			getline(cin, a);
			cout << "----------------------------------------------------" << endl;			

			for (int i = 0; i < 3; i++){
				if (a == backpack[i].name){
					cout << "You already have that!" << endl;
					return;
				}
			}

			if (a == item1.getName()){
				playerBought(Player, item1);
				addBackpack(backpack, item1);
				break;
			}
			else if (a == item2.getName()){
				playerBought(Player, item2);
				addBackpack(backpack, item2);
				break;
			}
			else if (a == item3.getName()){
				playerBought(Player, item3);
				addBackpack(backpack, item3);
				break;
			}
			else if (a == "Nothing"){
				cout << "Thank you!" << endl << endl;
				break;
			}										
			else {
				cout << "Enter a supported choice!" << endl;
			}

		}
	}

	void addBackpack(Character backpack[10], Character item){
		for (int i = 0; i < 10; i++){
			if (backpack[i].name == "") {
				backpack[i] = item;
				return;
			}
		}
		cout << "You have no room in your backpack!" << endl;
	}

	void deleteBackpack(Character backpack[10]){
		cout << "What would you like to throwaway?" << endl;
		for (int i = 0; i < 10; i++){
			if (backpack[i].name == ""){
				cout << "-empty slot-" << endl;
			}
			else {
				cout << backpack[i].name << endl;
			}
		}
		string a;
		getline(cin, a);
		cout << "----------------------------------------------------" << endl;
		Character blank;

		for (int i = 0; i < 10; i++){
			if (a == backpack[i].name){
				backpack[i] = blank;
				cout << "You threw away " << a << "!" << endl;
				return;
			}
		}		
		cout << "That's not in your backpack anyway!" << endl;
	}

	void addEquipped(Character backpack[10], Character equipped[3]){
		cout << "What would you like to equip?" << endl;
		for (int i = 0; i < 10; i++){
			if (backpack[i].name == ""){
				cout << "-empty slot-" << endl;
			}
			else {
				cout << backpack[i].name << endl;
			}
		}
		string a;
		getline(cin, a);
		cout << "----------------------------------------------------" << endl;			

		for (int i = 0; i < 3; i++){
			if (a == equipped[i].name){
				cout << "That's already equipped!" << endl;
				return;
			}
		}

		for (int i = 0; i < 10; i++){
			if (a == backpack[i].name){
				Character e = backpack[i];
				for (int i = 0; i < 3; i++){
					if (equipped[i].name == ""){
						equipped[i] = e;
						cout << "You equipped " << a << "!" << endl;
						return;
					}
				}
				cout << "You cannot equip anything else!" << endl;
				return;
			}
		}
		cout << "That's not in your backpack!" << endl;
	}	

	void deleteEquipped(Character equipped[3]){
		cout << "What would you like to unequip?" << endl;
		for (int i = 0; i < 3; i++){
			if (equipped[i].name == ""){
				cout << "-empty slot-" << endl;
			}
			else {
				cout << equipped[i].name << endl;
			}
		}
		string a;
		getline(cin, a);
		cout << "----------------------------------------------------" << endl;
		Character blank;

		for (int i = 0; i < 3; i++){
			if (a == equipped[i].name){
				equipped[i] = blank;
				cout << "You unequiped " << a << "!" << endl;
				return;
			}
		}	
		cout << "That's not equipped anyway!" << endl;	
	}		
	