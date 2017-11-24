# Dungeons
Teaching myself cpp with a text adventure

# Player Stories completed before first commit:
[x] Player inputs their name at start; name is used for dialogoue throughout

[x] Player sees name and description of each Room they enter. Player begins at Home and can travel to Town, Path, Forest, and back Home.
The Rooms are organized in a 2x2 grid.

[x] Player is able to navigate Level by typing Cardinal Directions: North, South, East, or West.

[x] Player is able to buy Great Sword, Mighty Shield, or Battle Set from the Shop in Town.
Player starts game with 10 Gold and can only buy one item. Each item affects the Player's Attack, Defense, Health, Speed, and Gold stats (or data members) differently

[x] Player is able to Battle a Monster in the Forest. Player chooses whether to Attack or Run by typing the command. After the Player Attacks, the Monster Attacks.
Attacks affect Player and Monster health with an algorithm taking into account Attack, Defense, and Health stats. Player is always able to Run.

[x] Player wins game after killing the Monster. Player loses the game if killed by the Monster.

# Player Story Objectives:
[] Player needs to think about Speed because Speed determines whether the Player or the Monster attacks first.

[] Player is able to navigate a 3x3 grid with more Shops and Battle events. There are more than 3 Items and more than 1 Monster

[] Player is able to afford more than 1 Item from the Shop either through being given more Gold at the start or finding more Gold in the Level

[] Player is able to equip and de-equip Items. There are limits to what can be equipped at the same time

[] Player can choose to use an Item during Battle. Some items are un-equipable but can be used in Battle

[] Player can earn Gold or Items by completing Find and Deliver Quests

[] Player can check their stats at any time

[] Player can check item stats before purchase

[] Player is restricted access to certain Rooms until after acquiring a certain Item

[] Player sees formatting in Command Line that makes it easy to understand where was the last input and most recent output
