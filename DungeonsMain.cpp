#include <iostream>
#include "Dungeons.cpp"
using namespace std;

int main(){

	//put continue statements in your control loops

	string n;

	//Get player's name
	cout << "----------------------------------------------------" << endl;	
	cout << "Welcome to the game.\nControl your character by typing commands.\nType Equip, Unequip, or Throwaway to access your inventory." << endl;
	cout << "What is your name?" << endl; 
	getline(cin, n);
	cout << "----------------------------------------------------" << endl;

	cout << "Input setting here." << endl << endl;

	//Define Player Character
	Character Player;
	Player.name = n;
	Player.attack = 5;
	Player.defense = 5; 
	Player.health = 10;
	Player.speed = 5;
	Player.gold = 15;
	Character backpack[10];
	Character equipped[3];

	//Define Item Characters
	Character item1;
	item1.name = "Item 1";
	item1.attack = 0;
	item1.defense = 5;
	item1.health = 2;
	item1.speed = -4;
	item1.gold = 5;

	Character item2;
	item2.name = "Item 2";
	item2.attack = 0;
	item2.defense = 5;
	item2.health = 2;
	item2.speed = -4;
	item2.gold = 5;

	Character item3;
	item3.name = "Item 3";
	item3.attack = 0;
	item3.defense = 5;
	item3.health = 2;
	item3.speed = -4;
	item3.gold = 5;

	Character item4;
	item4.name = "Item 4";
	item4.attack = 0;
	item4.defense = 5;
	item4.health = 2;
	item4.speed = -4;
	item4.gold = 5;

	Character item5;
	item5.name = "Item 5";
	item5.attack = 0;
	item5.defense = 5;
	item5.health = 2;
	item5.speed = -4;
	item5.gold = 5;

	Character item6;
	item6.name = "Item 6";
	item6.attack = 0;
	item6.defense = 5;
	item6.health = 2;
	item6.speed = -4;
	item6.gold = 5;

	//Define Monster Characters
	Character a_Monster;
	a_Monster.name = "Attack Monster";
	a_Monster.attack = 10;
	a_Monster.defense = 5;
	a_Monster.health = 10;
	a_Monster.speed = 5;

	Character d_Monster;
	d_Monster.name = "Defense Monster";
	d_Monster.attack = 5;
	d_Monster.defense = 10;
	d_Monster.health = 10;
	d_Monster.speed = 5;

	Character s_Monster;
	s_Monster.name = "Speed Monster";
	s_Monster.attack = 5;
	s_Monster.defense = 5;
	s_Monster.health = 10;
	s_Monster.speed = 10;

	Character b_Monster;
	b_Monster.name = "Boss Monster";
	b_Monster.attack = 10;
	b_Monster.defense = 10;
	b_Monster.health = 10;
	b_Monster.speed = 10;			

	//Define Rooms
	Room Home;
	Home.name = "the Entrance";
	Home.description = "Description.";

	Room Center;
	Center.name = "the Center";
	Center.description = "Description."; 

	Room Top;
	Top.name = "the Back";
	Top.description = "Description.";

	Room a_Den;
	a_Den.name = "a Monster Den";
	a_Den.description = "Description.";
	a_Den.battleBool = true;
	a_Den.Monster = a_Monster;

	Room d_Den;
	d_Den.name = "a Monster Den";
	d_Den.description = "Description.";
	d_Den.battleBool = true;
	d_Den.Monster = d_Monster;

	Room s_Den;
	s_Den.name = "a Monster Den";
	s_Den.description = "Description.";
	s_Den.battleBool = true;
	s_Den.Monster = s_Monster;

	Room b_Den;
	b_Den.name = "the Boss's Quarters";
	b_Den.description = "Description.";
	b_Den.battleBool = true;
	b_Den.Monster = b_Monster;

	Room Store_1;
	Store_1.name = "Store 1";
	Store_1.description = "Description.";
	Store_1.shopBool = true;
	Store_1.shopGoods[0] = pills;
	Store_1.shopGoods[1] = soy;
	Store_1.shopGoods[2] = fur;

	Room Store_2;
	Store_2.name = "Store 2";
	Store_2.description = "Description.";
	Store_2.shopBool = true;
	Store_2.shopGoods[0] = thotParty;
	Store_2.shopGoods[1] = suit;
	Store_2.shopGoods[2] = dildo;		

	//set dimensions of room matrix
	const int xMax = 3;
	const int yMax = 3;

	//add rooms to matrix
	Room matrix[xMax][yMax] = {{b_Den, Top, a_Den},
							   {Store_1, Center, Store_2},
							   {s_Den, Home, d_Den}};

	//set player starting position
	int x = 2;
	int y = 1;

	bool run = true;

	int monsterCount = 4;

	do {
		matrix[x][y].describeRoom();

		if (matrix[x][y].battleBool == true){
			matrix[x][y].battle(Player, equipped);

			if (Player.health <= 0){
				break;
			}
			else if (matrix[x][y].Monster.health <= 0){
				monsterCount = monsterCount - 1;
				matrix[x][y].battleBool = false;
			}	
			if (monsterCount == 0){
				cout << Player.name << ", you won the game!" << endl;
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
