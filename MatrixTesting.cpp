#include <iostream>
#include "Dungeons.cpp"
using namespace std;

void level(int x, int y, int xMax, Character matrix[][3], Character backpack[10], Character equipped[3]){
	bool run = true;
	do {
		matrix[x][y].describeCharacter();
		cout << "Where do you go?" << endl;

		if (x != 0){
			cout << "North ";
		}
		if (x != xMax - 1){
			cout << "South ";
		}
		if (y != 2){
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
			if (y != 2){
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
		else if (i== "Throwaway"){
			deleteBackpack(backpack);
		}			  
		else {
			cout << "Enter a supported choice!" << endl;
		}

	} while(run == true);
}

int main(){

	string n;

	//collect user input
	cout << "----------------------------------------------------" << endl;	
	cout << "What is your name?" << endl; 
	getline(cin, n);
	cout << "----------------------------------------------------" << endl;

	//Define Player Character
	Character Player;
	Player.setName(n);
	Player.setAttack(5);
	Player.setDefense(5);
	Player.setHealth(5);
	Player.setSpeed(5);
	Player.setGold(20);
	Character backpack[10];
	Character equipped[3];

	//Define Item Characters
	Character greatSword;
	greatSword.setName("Sword");
	greatSword.setAttack(5);
	greatSword.setDefense(0);
	greatSword.setHealth(0);
	greatSword.setSpeed(0);
	greatSword.setGold(10);
	//addBackpack(backpack, greatSword);
	//addEquipped(backpack, equipped);
	//deleteBackpack(backpack);
	/*for (int i=0; i<10; i++){
		cout << backpack[i].name << endl;
	}*/

	Character mightyShield;
	mightyShield.setName("Shield");
	mightyShield.setAttack(0);
	mightyShield.setDefense(5);
	mightyShield.setHealth(0);
	mightyShield.setSpeed(0);
	mightyShield.setGold(10);

	Character battleSet;
	battleSet.setName("Battle Set");
	battleSet.setAttack(5);
	battleSet.setDefense(5);
	battleSet.setHealth(0);
	battleSet.setSpeed(5);
	battleSet.setGold(25);

	//Define Monster Characters
	Character Monster;
	Monster.setName("Monster");
	Monster.setAttack(10);
	Monster.setDefense(5);
	Monster.setHealth(15);
	Monster.setSpeed(5);

	//Define Room Characters
	Character Home;
	Home.setName("Home");
	Home.setDescription("It feels good to be home!");

	Character Path;
	Path.setName("a Path");
	Path.setDescription("You like walking the path!");
	
	Character Town;
	Town.setName("your Town");
	Town.setDescription("All your friends and family live here. And there's a shop!");
	
	Character Forest;
	Forest.setName("the Forest");
	Forest.setDescription("There is something ominous about the forest today...");

	Character Junkyard;
	Junkyard.setName("the Junkyard");
	Junkyard.setDescription("One man's trash is another man's treasure.");

	Character Vineyard;
	Vineyard.setName("the Vineyard");
	Vineyard.setDescription("It's nice. They make wine here.");

//Create Character Matrix of Rooms
//Create function with matrix argument that auto-handles the navigation	
//Use booleans to determine when a room has a battle or shop
//Function should sucessfully create 2x2, 3x3, and 4x4 maps

	Character matrix[3][3] = {{Forest, Path, Vineyard},
							  {Path, Home, Path},
							  {Town, Path, Junkyard}};

	level(1, 1, 3, matrix, backpack, equipped);

	return 0;
}
