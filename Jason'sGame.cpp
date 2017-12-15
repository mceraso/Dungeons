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

	cout << "You enter Mr. Binkey's sex shop where your friend Kevin said he was trapped. You don't know much else. His text said to hurry." << endl;

	//Define Player Character
	Character Player;
	Player.name = n;
	Player.attack = 5;
	Player.defense = 5; 
	Player.health = 10;
	Player.speed = 5;
	Player.gold = 20;
	Character backpack[10];
	Character equipped[3];

	//Define Item Characters
	Character thotParty;
	thotParty.name = "Thot Party DVD Box Set";
	thotParty.attack = 0;
	thotParty.defense = 5;
	thotParty.health = 2;
	thotParty.speed = -4;
	thotParty.gold = 5;

	Character dildo;
	dildo.name = "Dildo with Chain";
	dildo.attack = 4;
	dildo.defense = 1;
	dildo.health = -4;
	dildo.speed = 0;
	dildo.gold = 5;

	Character pills;
	pills.name = "Purple Pills";
	pills.attack = 3;
	pills.defense = -2;
	pills.health = -4;
	pills.speed = 6;
	pills.gold = 5;

	Character suit;
	suit.name = "Spider Man Suit";
	suit.attack = 0;
	suit.defense = -1;
	suit.health = 1;
	suit.speed = 2;
	suit.gold = 5;

	Character soy;
	soy.name = "Soy";
	soy.attack = -5;
	soy.defense = -3;
	soy.health = 1;
	soy.speed = -1;
	soy.gold = 5;

	Character fur;
	fur.name = "Tasteful Fur";
	fur.attack = -2;
	fur.defense = 0;
	fur.health = 4;
	fur.speed = 0;
	fur.gold = 5;

	//Define Monster Characters
	Character a_Monster;
	a_Monster.name = "Zombie";
	a_Monster.attack = 15;
	a_Monster.defense = 5;
	a_Monster.health = 15;
	a_Monster.speed = 5;

	Character d_Monster;
	d_Monster.name = "Zombie";
	d_Monster.attack = 5;
	d_Monster.defense = 15;
	d_Monster.health = 15;
	d_Monster.speed = 5;

	Character s_Monster;
	s_Monster.name = "Zombie";
	s_Monster.attack = 5;
	s_Monster.defense = 5;
	s_Monster.health = 15;
	s_Monster.speed = 15;

	Character b_Monster;
	b_Monster.name = "Sexy Mage";
	b_Monster.attack = 10;
	b_Monster.defense = 10;
	b_Monster.health = 15;
	b_Monster.speed = 10;			

	//Define Rooms
	Room Home;
	Home.name = "the Entrance";
	Home.description = "You hear zombies to your left and right. You shudder at the thought of what they're doing to Kevin.";

	Room Center;
	Center.name = "the Center of the Store";
	Center.description = "Used condoms are piled high. Several shoppers are enganging in heinous sexual acts. Clerks are selling items to your left and right. " 

	Room Top;
	Top.name = "the Back of the Store"
	Top.description = "Kevin is trapped in a cage. He is naked, afraid, and alone. The mage is to your left. A zombie is to your right."

	Room a_Den;
	a_Den.name = "a Zombie Den";
	a_Den.description = "Suits made from human flesh and broken dildos lie around the room. You smell semen, blood, and sweat.";
	a_Den.battleBool = true;
	a_Den.Monster = a_Monster;

	Room d_Den;
	d_Den.name = "a Zombie Den";
	d_Den.description = "Suits made from human flesh and broken dildos lie around the room. You smell semen, blood, and sweat.";
	d_Den.battleBool = true;
	d_Den.Monster = d_Monster;

	Room s_Den;
	s_Den.name = "a Zombie Den";
	s_Den.description = "Suits made from human flesh and broken dildos lie around the room. You smell semen, blood, and sweat.";	
	s_Den.battleBool = true;
	s_Den.Monster = s_Monster;

	Room b_Den;
	b_Den.name = "the Mage's Quarters";
	b_Den.description = "The mage is naked except for two strap-on dildos. His cock looks just as hard as the dildos it bounces nearby. You smell blood and sweat.";	
	b_Den.battleBool = true;
	b_Den.Monster = b_Monster;

	Room Aisle_1;
	Aisle_1.name = "an Aisle";
	Aisle_1.description = "Blood and shit cover the floor. A clerk is selling items.";
	Aisle_1.shopBool = true;
	Aisle_1.shopGoods[0] = pills;
	Aisle_1.shopGoods[1] = soy;
	Aisle_1.shopGoods[2] = fur;

	Room Aisle_2;
	Aisle_2.name = "an Aisle";
	Aisle_2.description = "Blood and shit cover the floor. A clerk is selling items.";
	Aisle_2.shopBool = true;
	Aisle_2.shopGoods[0] = thotParty;
	Aisle_2.shopGoods[1] = suit;
	Aisle_2.shopGoods[2] = dildo;		

	//set dimensions of room matrix
	const int xMax = 3;
	const int yMax = 3;

	//add rooms to matrix
	Room matrix[xMax][yMax] = {{b_Den, Top, a_Den},
							   {Aisle_1, Center, Aisle_2},
							   {s_Den, Home, d_Den}};

	//set player starting position
	int x = 1;
	int y = 2;

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
