#include <iostream>
#include "Dungeons.cpp"
using namespace std;

int main(){

	string n;

	//collect user input
	cout << "What is your name?" << endl; 
	getline(cin, n);
	cout << "----------------------------------------------------" << endl;

	Character Player;
	Player.setName(n);
	Player.setAttack(5);
	Player.setDefense(5);
	Player.setHealth(5);
	Player.setSpeed(5);
	Player.setGold(10);

	Character greatSword;
	greatSword.setName("Great Sword");
	greatSword.setAttack(15);
	greatSword.setDefense(0);
	greatSword.setHealth(0);
	greatSword.setSpeed(-5);
	greatSword.setGold(10);

	Character mightyShield;
	mightyShield.setName("Mighty Shield");
	mightyShield.setAttack(0);
	mightyShield.setDefense(15);
	mightyShield.setHealth(0);
	mightyShield.setSpeed(-5);
	mightyShield.setGold(10);

	Character battleSet;
	battleSet.setName("Battle Set");
	battleSet.setAttack(5);
	battleSet.setDefense(5);
	battleSet.setHealth(0);
	battleSet.setSpeed(5);
	battleSet.setGold(10);

	Character Monster;
	Monster.setName("Monster");
	Monster.setAttack(10);
	Monster.setDefense(5);
	Monster.setHealth(15);
	Monster.setSpeed(5);

	Room Home;
	Home.setName("Home");
	Home.setDescription("It feels good to be home!");

	Room Path;
	Path.setName("a Path");
	Path.setDescription("You like walking the path!");
	
	Room Town;
	Town.setName("your Town");
	Town.setDescription("All your friends and family live here. And there's a shop!");
	
	Room Forest;
	Forest.setName("the Forest");
	Forest.setDescription("There is something ominous about the forest today...");

	string r = "1";

	while(Player.getHealth() > 0 or Monster.getHealth() > 0){

		if (r == "1"){
			Home.describeRoom();
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
			else {
				cout << "Enter a supported choice!" << endl;
			}
		}

		if (r == "3"){
			Path.describeRoom();
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
			else {
				cout << "Enter a supported choice!" << endl;
			}

		}

		if (r == "2"){
			Town.describeRoom();
			shop(Player, greatSword, mightyShield, battleSet);

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
			else {
				cout << "Enter a supported choice!" << endl;
			}
		}

		if (r == "4"){
			Forest.describeRoom();
			battle(Player, Monster);

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
			else {
				cout << "Enter a supported choice!" << endl;
			}
		}

	}
	return 0;
}
