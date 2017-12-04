#include <iostream>
#include "Dungeons.cpp"
using namespace std;

int main(){

	string n;

	//collect user input
	cout << "----------------------------------------------------" << endl;	
	cout << "What is your name?" << endl; 
	getline(cin, n);
	cout << "----------------------------------------------------" << endl;

	//Define Player Character
	Character Player;
	Player.name = n;
	Player.setAttack(5);
	Player.setDefense(5);
	Player.setHealth(5);
	Player.setSpeed(5);
	Player.setGold(20);
	Character backpack[10];
	Character equipped[3];

	//Define Item Characters
	Character greatSword;
	greatSword.name = "Sword";
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
	mightyShield.name = "Shield";
	mightyShield.setAttack(0);
	mightyShield.setDefense(5);
	mightyShield.setHealth(0);
	mightyShield.setSpeed(0);
	mightyShield.setGold(10);

	Character battleSet;
	battleSet.name = "Battle Set";
	battleSet.setAttack(5);
	battleSet.setDefense(5);
	battleSet.setHealth(0);
	battleSet.setSpeed(5);
	battleSet.setGold(25);

	//Define Monster Characters
	Character Monster;
	Monster.name = "Monster";
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

	string r = "1";

//Create Character Matrix of Rooms
//Create function with matrix argument that auto-handles the navigation	
//Use booleans to determine when a room has a battle or shop
//Function should sucessfully create 2x2, 3x3, and 4x4 maps

	while(Player.getHealth() > 0 or Monster.getHealth() > 0){

		if (r == "1"){
			Home.describeCharacter();
			cout << "Where do you go?" << endl;
			cout << "North or East" << endl;

			string i;
			getline(cin, i);
			cout << "----------------------------------------------------" << endl;			

			if (i == "North"){
				r = "3";
			}
			else if (i == "East"){
				r = "2";
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
		}

		if (r == "3"){
			Path.describeCharacter();
			cout << "Where do you go?" << endl;
			cout << "East or South" << endl;

			string i;
			getline(cin, i);
			cout << "----------------------------------------------------" << endl;

			if (i == "East"){
				r = "4";
			}
			else if (i == "South"){
				r = "1";
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
		}

		if (r == "2"){
			Town.describeCharacter();
			shop(Player, greatSword, mightyShield, battleSet, backpack);
			/*for (int i=0; i<10; i++){
				cout << backpack[i].name << endl;
			}*/

			cout << "Where do you go?" << endl;			
			cout << "North or West" << endl;

			string i;
			getline(cin, i);
			cout << "----------------------------------------------------" << endl;

			if (i == "North"){
				r = "4";
			}
			else if (i == "West"){
				r = "1";
			}
			else if (i == "Equip"){
				addEquipped(backpack, equipped);
				/*for (int i=0; i<3; i++){
					cout << equipped[i].name << endl;
				}*/				
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
		}

		if (r == "4"){
			Forest.describeCharacter();
			battle(Player, Monster, equipped);

			if (Player.getHealth() <= 0 or Monster.getHealth() <= 0){
				break;
			}

			cout << "Where do you go?" << endl;
			cout << "South or West" << endl;

			string i;
			getline(cin, i);
			cout << "----------------------------------------------------" << endl;

			if (i == "South"){
				r = "2";
			}
			else if (i == "West"){
				r = "3";
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
		}

	}
	return 0;
}
