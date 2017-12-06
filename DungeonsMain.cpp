#include <iostream>
#include "Dungeons.cpp"
using namespace std;

int main(){

	string n;

	//Get player's name
	cout << "----------------------------------------------------" << endl;	
	cout << "What is your name?" << endl; 
	getline(cin, n);
	cout << "----------------------------------------------------" << endl;

	//Define Player Character
	Character Player;
	Player.name = n;
	Player.attack = 5;
	Player.defense = 5; 
	Player.health = 5;
	Player.speed = 5;
	Player.gold = 20;
	Character backpack[10];
	Character equipped[3];

	//Define Item Characters
	Character greatSword;
	greatSword.name = "Sword";
	greatSword.attack = 5;
	greatSword.defense = 0;
	greatSword.health = 0;
	greatSword.speed = 0;
	greatSword.gold = 10;

	Character mightyShield;
	mightyShield.name = "Shield";
	mightyShield.attack = 0;
	mightyShield.defense = 5;
	mightyShield.health = 0;
	mightyShield.speed = 0;
	mightyShield.gold = 10;

	Character battleSet;
	battleSet.name = "Battle Set";
	battleSet.attack = 5;
	battleSet.defense = 5;
	battleSet.health = 0;
	battleSet.speed = 5;
	battleSet.gold = 25;

	//Define Monster Characters
	Character Monster;
	Monster.name = "Monster";
	Monster.attack = 10;
	Monster.defense = 5;
	Monster.health = 15;
	Monster.speed = 5;

	//Define Rooms
	Room Home;
	Home.name = "Home";
	Home.description = "It feels good to be home!";

	Room Path;
	Path.name = "a Path";
	Path.description = "You like walking the path!";
	
	Room Town;
	Town.name = "your Town";
	Town.description = "All your friends and family live here. And there's a shop!";
	//declare a shop event to happen in town
	Town.shopBool = true;
	//define the shop's goods in the town
	Town.shopGoods[0] = greatSword;
	Town.shopGoods[1] = mightyShield;
	Town.shopGoods[2] = battleSet;	
	
	Room Forest;
	Forest.name = "the Forest";
	Forest.description = "There is something ominous about the forest today...";
	//declare a battle event to happen in the forest
	Forest.battleBool = true;
	//define the monster in the forest
	Forest.Monster = Monster;

	Room Junkyard;
	Junkyard.name = "the Junkyard";
	Junkyard.description = "One man's trash is another man's treasure.";

	Room Vineyard;
	Vineyard.name = "the Vineyard";
	Vineyard.description = "It's nice. They make wine here.";

	//set dimensions of room matrix
	const int xMax = 3;
	const int yMax = 3;

	//add rooms to matrix
	Room matrix[xMax][yMax] = {{Forest, Path, Vineyard},
							   {Path, Home, Path},
							   {Town, Path, Junkyard}};

	//set player starting position
	int x = 1;
	int y = 1;

	bool run = true;

	do {
		matrix[x][y].describeRoom();

		if (matrix[x][y].battleBool == true){
			matrix[x][y].battle(Player, equipped);

			if (Player.health <= 0 or matrix[x][y].Monster.health <= 0){
				break;
			}
		}

		if (matrix[x][y].shopBool == true){
			matrix[x][y].shop(Player, backpack);
		}

		cout << "Where do you go?" << endl;
		if (x != 0){
			cout << "North ";
		}
		if (x != xMax - 1){
			cout << "South ";
		}
		if (y != yMax - 1){
			cout << "East ";
		}
		if (y != 0){
			cout << "West ";
		}
		cout << endl;

		string i;
		getline(cin, i);
		cout << "----------------------------------------------------" << endl;			

		if (i == "North"){
			if (x != 0){
				x -= 1;
			}
			else {
				cout << "Enter a supported choice!" << endl;
			}
		}
		else if (i == "South"){
			if (x != xMax - 1){
				x += 1;
			}
			else {
				cout << "Enter a supported choice!" << endl;
			}
		}		
		else if (i == "East"){
			if (y != yMax - 1){
				y += 1;
			}
			else {
				cout << "Enter a supported choice!" << endl;
			}
		}
		else if (i == "West"){
			if (y != 0){
				y -= 1;
			}
			else {
				cout << "Enter a supported choice!" << endl;
			}
		}
					
		else if (i == "Equip"){
			addEquipped(backpack, equipped);
		}
		else if (i == "Unequip"){
			deleteEquipped(equipped);
		}
		else if (i == "Throwaway"){
			deleteBackpack(backpack);
		}			  
		else {
			cout << "Enter a supported choice!" << endl;
		}

	} while(run == true);

	return 0;
}
