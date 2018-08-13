# Dungeons
Teaching myself cpp with a text adventure. Development has stopped in order to pursue PCB and Arduino-based projects. The idea is to come back to the text adventure to add features based on what I learn while completing Arduino projects.

# 8.6.18: Development is back on.
* [x] Player can travel through a one-way portal to get to the Focus VQ HQ and through a different one-way portal to get home.
* [x] Player can find items in chests and in rooms without having to go through a shop mechanic.
* [x] Player experiences a more dynamic map with tunnels. The map is no longer just an n x n grid and can be molded into any configuration
* [x] Player can acquire items by killing monsters. Monsters drop items. 8.9.18
* [x] Player can unlock doors with consummable keys in their backpack. 8.9.18
* [x] Player can type shortcuts for North, South, East, West, Equip, Unequip, Throwaway, Attack, and Run

# 8.6.18: Things Learned:
* [x] using continue to skip the rest of a while loop iteration after meeting a certain condition
* [x] using Booleans to control navigation, shops, battles, chests, and portals in each room
* [x] using std::vector<string> and find() to check if input is an accepted shortcut for an available command

# Player Stories completed before first commit:
* [x] Player inputs their name at start; name is used for dialogoue throughout

* [x] Player sees name and description of each Room they enter. Player begins at Home and can travel to Town, Path, Forest, and back Home.
The Rooms are organized in a 2x2 grid.

* [x] Player is able to navigate Level by typing Cardinal Directions: North, South, East, or West.

* [x] Player is able to buy Great Sword, Mighty Shield, or Battle Set from the Shop in Town.
Player starts game with 10 Gold and can only buy one item. Each item affects the Player's Attack, Defense, Health, Speed, and Gold stats (or data members) differently

* [x] Player is able to Battle a Monster in the Forest. Player chooses whether to Attack or Run by typing the command. After the Player Attacks, the Monster Attacks.
Attacks affect Player and Monster health with an algorithm taking into account Attack, Defense, and Health stats. Player is always able to Run.

* [x] Player wins game after killing the Monster. Player loses the game if killed by the Monster.

# Player Story Objectives:
* [x] Equipped items affect Player performance in Battle
 
* [x] Player needs to think about Speed because Speed determines whether the Player or the Monster attacks first.

* [x] Player is able to navigate a 3x3 grid.

* [x] Player experiences more Shops and Battle events. There are more than 3 Items and more than 1 Monster

* [x] Player is able to afford more than 1 Item from the Shop either through being given more Gold at the start or finding more Gold in the Level

* [x] Player is able to equip and de-equip Items. There are limits to what can be equipped at the same time

* [x] Player sees formatting in Command Line that makes it easy to understand where was the last input and most recent output

* [x] Player receives better feedback in a battle

* [x] Battle events incorporate randomness / probability

* [] Player cannot win battles by running and returning with full health

* [] Player can choose to use an Item during Battle. Some items are un-equipable but can be used in Battle

* [] Player can earn Gold or Items by completing Find and Deliver Quests

* [] Player can check their stats at any time

* [] Player can check item stats before purchase

* [x] Player is restricted access to certain Rooms until after acquiring a certain Item

* [] Player is able to obtain a backpack with unlimited capacity (vector backpack)

# Things Learned:
* [x] while-if control loops to keep player from inputting unsupported choices

* [x] creation of header file, class and function definition file, and main function file with communication among them

* [x] creation of class with public variables

* [x] passing multiple class instances as function arguments

* [x] passing function arguments by reference to affect variables declared in main

* [x] passing arrays as function arguments

* [x] const int declaration for known matrix dimensions

* [x] do-while control loop for handling matrix of rooms of known-size

* [x] randomness in battle event: https://stackoverflow.com/questions/23055585/program-with-probability

* [x] vectors (simplified navigation)

* [] array.fill() and array.swap() (monster attack dynamics)

* [] namespace creation (game wrapper / workspace)

