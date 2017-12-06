#include <iostream>
#include "Dungeons.h"
using namespace std;

	//default constructor used
	/*Character::Character(){
	}*/

	void Character::describeCharacter(){
		cout << "This is " << name << endl;
		cout << description << endl;
	}

	//defining battle function
	void battle(Character& Player, Character& Monster, Character equipped[3]){
		cout << endl << Player.name << ", you are approached by a " << Monster.name << endl;

		int eA = Player.attack;
		int eD = Player.defense;
		int eS = Player.speed;
		int eH = Player.health;
		for (int n = 0; n < 3; n ++){
			eA += equipped[n].attack;
			eD += equipped[n].defense;
			eS += equipped[n].speed;
			eH += equipped[n].health;
		}


		int x = 0;
		while (x == 0){
			bool netS = false;
			if (Monster.speed >= eS){
				netS = true;
				cout << "The " << Monster.name << " attacked you!" << endl;
				int netA = Monster.attack - eD;
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
				cout << "You attacked the " << Monster.name << "!" << endl;
				int netA = eA - Monster.defense;
				if (netA < 0){
					netA = 1;
				}
				Monster.health = Monster.health - netA;
				if (Monster.health <= 0){
					break;
				}
			} 
			else {
				cout << "Enter a supported choice!" << endl;
			}
			if (netS == false){
				cout << "The " << Monster.name << " attacked you!" << endl;
				int netA = Monster.attack - eD;
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
			cout << "The " << Monster.name << " killed you!" << endl;
			cout << "Game Over" << endl;
			cout << "----------------------------------------------------" << endl;;
			Player.health = eH;
		}	

		else if (Monster.health <= 0){
			cout << "You killed the " << Monster.name << "!" << endl;
			cout << "Congratulations, " << Player.name << "! You won the game!" << endl;
			cout << "----------------------------------------------------" << endl;;			
		}
	}

	void playerBought(Character& Player, Character item){
		cout << "You bought the " << item.name << "!" << endl;
		cout << "Gold is decreased by " << item.gold << "." << endl;
		Player.gold = Player.gold - item.gold;

		cout << "When equipped, " << endl;
		if (item.attack < 0){
			cout << "Attack is decreased by " << item.attack << "." << endl;
		}
		else if (item.attack > 0){
			cout << "Attack is increased by " << item.attack << "." << endl;
		}
		else {
			cout << "Attack is unchanged." << endl;
		}
		if (item.defense < 0){
			cout << "Defense is decreased by " << item.defense << "." << endl;
		}
		else if (item.defense > 0){
			cout << "Defense is increased by " << item.defense << "." << endl;
		}
		else {
			cout << "Defense is unchanged." << endl;
		}
		if (item.health < 0){
			cout << "Health is decreased by " << item.health << "." << endl;
		}
		else if (item.health > 0){
			cout << "Health is increased by " << item.health << "." << endl;
		}
		else {
			cout << "Health is unchanged." << endl;
		}
		if (item.speed < 0){
			cout << "Speed is decreased by " << item.speed << "." << endl;
		}
		else if (item.speed > 0){
			cout << "Speed is increased by " << item.speed << "." << endl;
		}
		else {
			cout << "Speed is unchanged." << endl;
		}			
		cout << "Thank you!" << endl << endl;
	}

	void shop(Character& Player, Character item1, Character item2, Character item3, Character backpack[10]){
		cout << endl << "Welcome to the shop!" << endl;
		cout << "Looks like you have " << Player.gold << " Gold" << endl;
		if (Player.gold <= 0){
			cout << "Go get more Gold!" << endl;
			return;
		}

		int x = 0;
		while (x == 0){
			cout << "What would you like?" << endl;
			cout << item1.name << " for " << item1.name << " Gold" << endl;
			cout << item2.name << " for " << item2.name << " Gold" << endl;
			cout << item3.name << " for " << item3.name << " Gold" << endl;
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

			if (a == item1.name) {
				playerBought(Player, item1);
				addBackpack(backpack, item1);
				break;
			}
			else if (a == item2.name) {
				playerBought(Player, item2);
				addBackpack(backpack, item2);
				break;
			}
			else if (a == item3.name) {
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
	