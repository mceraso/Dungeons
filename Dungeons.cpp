#include <iostream>
#include "Dungeons.h"
using namespace std;

	Character::Character(){
		attack = 0;
		defense = 0;
		health = 0;
		speed = 0;
		gold = 0;
		isKey = false;
	}

	Room::Room(){
		battleBool = false;
		monsterItemBool = false;
		shopBool = false;
		chestBool = false;
		blockBool = false;
		portalBool = false;
		openWith.name = "Open";
	}

	void Room::describeRoom(){
		cout << "This is " << name << endl;
		cout << description << endl;
	}

	//defining battle function
	void Room::battle(Character& Player, Character equipped[3]){
		cout << endl << Player.name << ", you are approached by a " << Monster.name << endl;

		int eA = Player.attack;
		int eD = Player.defense;
		int eS = Player.speed;
		int eH = Player.health;
		for (int n = 0; n < 3; n++){
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
				if (netA <= 0){
					netA = 1;
				}
				eH -= netA;
				if (eH <= 0){
					break;
				}				
			}
			
			cout << "Your health is " << eH << "." << endl;
			cout << "The " << Monster.name << "'s health is " << Monster.health << "." << endl;
			cout << "What do you do?" << endl;
			cout << "Attack or Run" << endl;
			string i;
			getline(cin, i);
			cout << "----------------------------------------------------" << endl;

			if (i == "Run"){

   				srand(time(NULL));
    			int number = rand() % 100 + 1;  //Generate random number 1 to 100

          		if (number <= 50) { //50% chance
					cout << "You got away safely!" << endl;
					break;
				}
					
          		else {
					cout << "You could not escape!" << endl;
          		}
			}

			else if (i == "Attack"){
				cout << "You attacked the " << Monster.name << "!" << endl;
				int netA = eA - Monster.defense;
				if (netA <= 0){
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
			cout << "Congratulations, " << Player.name << "!" << endl;
			cout << "Your base Attack, Defense, Speed, and Health have all increased by +1" << endl;
			Player.attack = Player.attack + 1;
			Player.defense = Player.defense + 1;
			Player.health = Player.health + 1;
			Player.speed = Player.speed + 1;

			cout << "----------------------------------------------------" << endl;			
		}
	}

	void Room::playerGot(Character& Player, Character item){
		cout << "You put the " << item.name << " in your backpack!" << endl;
		
		if (item.gold > 0){
		cout << "Gold is decreased by " << item.gold << "." << endl;
		Player.gold = Player.gold - item.gold;
		}

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
	}

	void Room::chest(Character& Player, Character backpack[10]){
		cout << endl << "You find a " << chestItem.name << "! " << endl;
		playerGot(Player, chestItem);
		addBackpack(backpack, chestItem);
	}

	void Room::monsterDrop(Character& Player, Character backpack[10]){
		cout << endl << "You find a " << monsterItem.name << "! " << endl;
		playerGot(Player, monsterItem);
		addBackpack(backpack, monsterItem);
	}	

	void Room::shop(Character& Player, Character backpack[10]){
		cout << endl << "Welcome to the shop!" << endl;
		cout << "Looks like you have " << Player.gold << " Gold" << endl;
		if (Player.gold <= 0){
			cout << "Go get more Gold!" << endl;
			return;
		}

		Character item1 = shopGoods[0];
		Character item2 = shopGoods[1];
		Character item3 = shopGoods[2];

		int x = 0;
		while (x == 0){
			cout << "What would you like?" << endl;
			cout << item1.name << " for " << item1.gold << " Gold" << endl;
			cout << item2.name << " for " << item2.gold << " Gold" << endl;
			cout << item3.name << " for " << item3.gold << " Gold" << endl;
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
				playerGot(Player, item1);
				addBackpack(backpack, item1);
				cout << "Thank you for your purchase!" << endl << endl;
				break;
			}
			else if (a == item2.name) {
				playerGot(Player, item2);
				addBackpack(backpack, item2);
				cout << "Thank you for your purchase!" << endl << endl;
				break;
			}
			else if (a == item3.name) {
				playerGot(Player, item3);
				addBackpack(backpack, item3);
				cout << "Thank you for your purchase!" << endl << endl;
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
	