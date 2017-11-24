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
	void battle(Character& Player, Character& Monster){
		cout << endl << Player.getName() << ", you are approached by a " << Monster.getName() << endl;

		int x = 0;
		while (x == 0){
			bool netS = false;
			if (Monster.getSpeed() >= Player.getSpeed()){
				netS = true;
				cout << "The " << Monster.getName() << " attacked you!" << endl;
				int netA = Monster.getAttack() - Player.getDefense();
				if (netA < 0){
					netA = 1;
				}
				Player.setHealth(Player.getHealth() - netA);
				if (Player.getHealth() <= 0){
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
				int netA = Player.getAttack() - Monster.getDefense();
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
				int netA = Monster.getAttack() - Player.getDefense();
				if (netA <= 0){
					netA = 1;
				}
				Player.setHealth(Player.getHealth() - netA);
				if (Player.getHealth() <= 0){
					break;
				}
			}	
		}

		if (Player.getHealth() <= 0){
			cout << "The " << Monster.getName() << " killed you!" << endl;
			cout << "Game Over" << endl;
			cout << "----------------------------------------------------" << endl;;
		}	

		else if (Monster.getHealth() <= 0){
			cout << "You killed the " << Monster.getName() << "!" << endl;
			cout << "Congratulations, " << Player.getName() << "! You won the game!" << endl;
			cout << "----------------------------------------------------" << endl;;			
		}
	}

	void playerBought(Character& Player, Character& item){
		cout << "You bought the " << item.getName() << "!" << endl;
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
		cout << "Gold is decreased by " << item.getGold() << "." << endl;
		Player.setAttack(Player.getAttack() + item.getAttack());
		Player.setDefense(Player.getDefense() + item.getDefense());		
		Player.setHealth(Player.getHealth() + item.getHealth());
		Player.setSpeed(Player.getSpeed() + item.getSpeed());		
		Player.setGold(Player.getGold() - item.getGold());
		cout << "Thank you!" << endl << endl;
	}

	void shop(Character& Player, Character& item1, Character& item2, Character& item3){
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

			string i;
			getline(cin, i);
			cout << "----------------------------------------------------" << endl;			

			if (i == item1.getName()){
				playerBought(Player, item1);
				break;
			}
			else if (i == item2.getName()){
				playerBought(Player, item2);
				break;
			}
			else if (i == item3.getName()){
				playerBought(Player, item3);
				break;
			}					
			else {
				cout << "Enter a supported choice!" << endl;
			}

		}
	}