#include <iostream>
#include "Dungeons.cpp"
using namespace std;

int main(){

	string n;

	//Get player's name
	cout << "----------------------------------------------------" << endl;	
	cout << "Welcome to the game.\nControl your character by typing commands.\nType Equip, Unequip, or Throwaway to access your inventory." << endl;
	cout << "What is your name?" << endl; 
	getline(cin, n);
	cout << "----------------------------------------------------" << endl;

	cout << "You wake up in your room to the sound of screaming townspeople.\nYou are brave and head out." << endl << endl;

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
	Character chainmail;
	chainmail.name = "Chainmail";
	chainmail.attack = 0;
	chainmail.defense = 5;
	chainmail.health = 2;
	chainmail.speed = -4;
	chainmail.gold = 5;

	Character mace;
	mace.name = "Mace";
	mace.attack = 4;
	mace.defense = 1;
	mace.health = -4;
	mace.speed = 0;
	mace.gold = 5;

	Character potion;
	potion.name = "Purple Potion";
	potion.attack = 3;
	potion.defense = -2;
	potion.health = -4;
	potion.speed = 6;
	potion.gold = 5;

	Character shoes;
	shoes.name = "Shoes of Swiftness";
	shoes.attack = 0;
	shoes.defense = -1;
	shoes.health = 1;
	shoes.speed = 2;
	shoes.gold = 5;

	Character soy;
	soy.name = "Soy";
	soy.attack = -5;
	soy.defense = -3;
	soy.health = 1;
	soy.speed = -1;
	soy.gold = 5;

	Character fur;
	fur.name = "Fur Coat";
	fur.attack = -2;
	fur.defense = 0;
	fur.health = 4;
	fur.speed = 0;
	fur.gold = 5;

	Character glory;
	glory.name = "Glorious, Golden Sword";
	glory.attack = 10;
	glory.defense = 5;
	glory.health = 5;
	glory.speed = 0;
	glory.gold = 0;	

	//Define Monster Characters
	Character a_Monster;
	a_Monster.name = "Goblin";
	a_Monster.attack = 10;
	a_Monster.defense = 5;
	a_Monster.health = 10;
	a_Monster.speed = 5;

	Character d_Monster;
	d_Monster.name = "Goblin";
	d_Monster.attack = 5;
	d_Monster.defense = 10;
	d_Monster.health = 10;
	d_Monster.speed = 5;

	Character s_Monster;
	s_Monster.name = "Goblin";
	s_Monster.attack = 5;
	s_Monster.defense = 5;
	s_Monster.health = 10;
	s_Monster.speed = 10;

	Character b_Monster;
	b_Monster.name = "Wizard";
	b_Monster.attack = 10;
	b_Monster.defense = 10;
	b_Monster.health = 10;
	b_Monster.speed = 10;			

	//Define Rooms
	Room Home;
	Home.name = "Outside Your Home";
	Home.description = "You hear goblins to your left and right.\nThey should not be near such a pleasant town.";

	Room Center;
	Center.name = "the Center of Town";
	Center.description = "Several townspeople are hudled together.\nYou hear hushed tones and crying as one mother explains\nhow a goblin ate her children."; 
	//Center.blockBool = true; // test block function

	Room Top;
	Top.name = "the Back of Town";
	Top.description = "The Mayor's Daughter is trapped in a cage.\nShe is afraid and cries for help.\nThe wizard is to your left.\nA goblin is to your right.\nYou notice a strange cave to the North.";
	//Top.chestBool = true; // test chest function
	//Top.chestItem = glory; // test chest function

	Room a_Den;
	a_Den.name = "a Goblin's Lounge";
	a_Den.description = "A child's toy bear lies on the ground.\nThe Goblin's lounge smells disgusting.";
	a_Den.battleBool = true;
	a_Den.Monster = a_Monster;

	Room d_Den;
	d_Den.name = "a Goblin's Lounge";
	d_Den.description = "The Mayor's robe is torn up and lies on the ground.\nYou wonder if he is alive.";
	d_Den.battleBool = true;
	d_Den.Monster = d_Monster;

	Room s_Den;
	s_Den.name = "a Goblin's Lounge";
	s_Den.description = "A child's skull lies on the ground.\nIt looks like it has been licked clean.";	
	s_Den.battleBool = true;
	s_Den.Monster = s_Monster;

	Room b_Den;
	b_Den.name = "the Wizard's Quarters";
	b_Den.description = "The Wizard laughs at you.\nHe explains that he has killed the Mayor\nand taken his daughter prisoner.";	
	b_Den.battleBool = true;
	b_Den.Monster = b_Monster;

	Room Aisle_1;
	Aisle_1.name = "the Market";
	Aisle_1.description = "People are gossiping about the Mayor's whereabouts.\nA clerk is selling items.";
	Aisle_1.shopBool = true;
	Aisle_1.shopGoods[0] = potion;
	Aisle_1.shopGoods[1] = soy;
	Aisle_1.shopGoods[2] = shoes;

	Room Aisle_2;
	Aisle_2.name = "the Shop";
	Aisle_2.description = "The clerk holds back his tears upon seeing you enter.\nHe puts away a picture of his daughter.";
	Aisle_2.shopBool = true;
	Aisle_2.shopGoods[0] = chainmail;
	Aisle_2.shopGoods[1] = mace;
	Aisle_2.shopGoods[2] = fur;

	Room cave_entrance;
	cave_entrance.name = "a strange cave entrance";
	cave_entrance.description = "You're frightened but marvel at what might be here.";		

	Room cave_tunnel;
	cave_tunnel.name = "a tunnel inside the cave";
	cave_tunnel.description = "You have been walking for a while and stop to take a break.";

	Room cave_chamber;
	cave_chamber.name = "the cave's main chamber";
	cave_chamber.description = "You see a glorious, golden chest.";
	cave_chamber.chestBool = true;
	cave_chamber.chestItem = glory;

	//set dimensions of room matrix
	const int xMax = 3;
	const int yMax = 3;

	//add rooms to matrix
	Room matrix[xMax][yMax] = {{b_Den, Top, a_Den},
							   {Aisle_1, Center, Aisle_2},
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
				cout << "You let the Mayor's Daughter out of her cage. She's doing just fine." << endl;
				cout << "You take her to the center of town, and the crowd cheers!" << endl;
				cout << "They elect you Mayor, and you keep the town safe for 100 more years." << endl; 
				cout << "The end?" << endl; 
				break;
			}
		}

		if (matrix[x][y].shopBool == true){
			matrix[x][y].shop(Player, backpack);
		}

		if (matrix[x][y].chestBool == true){
			matrix[x][y].chest(Player, backpack);
			matrix[x][y].chestBool = false;
		}

		cout << "Where do you go?" << endl;
		if (x > 0){
			if (matrix[x-1][y].blockBool == false){
				cout << "North ";
			}
		}
		if (x < xMax - 1){
			if (matrix[x+1][y].blockBool == false){
				cout << "South ";
			}
		}
		if (y < yMax - 1){
			if (matrix[x][y+1].blockBool == false){
				cout << "East ";
			}
		}
		if (y > 0 ){
			if (matrix[x][y-1].blockBool == false){
				cout << "West ";
			}
		}
		cout << endl;

		string i;
		getline(cin, i);
		cout << "----------------------------------------------------" << endl;			

		if (i == "North"){
			if (x > 0){
				if (matrix[x-1][y].blockBool == false){
					x -= 1;
				}
			}
			else {
				cout << "Enter a supported choice!" << endl;
			}
		}
		else if (i == "South"){
			if (x < xMax - 1){
				if (matrix[x+1][y].blockBool == false){
					x += 1;
				}
			}
			else {
				cout << "Enter a supported choice!" << endl;
			}
		}		
		else if (i == "East"){
			if (y < yMax - 1){
				if (matrix[x][y+1].blockBool == false){
					y += 1;
				}
			}
			else {
				cout << "Enter a supported choice!" << endl;
			}
		}
		else if (i == "West"){
			if (y > 0 ){
				if (matrix[x][y-1].blockBool == false){
					y -= 1;
				}
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
