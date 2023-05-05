# COMP-2113-Course-Project
# COMP-2113-group129
## Group members:
1. Name: Chaoyi   UID: 3035845136
2. Name: Lin Qianli  UID: 3035947348
# 1. General information  
## 1.1 Execution Instruction:
Please click "code" and then download the zip.  
Open the zip file with a folder, then you may use the files inside the folder for execution.
Please use the following Makefile command:
g++ -pedantic-errors -std=c++11 main.cpp save_status.cpp -o game

# 2. Introduction
# 2.1 Game Introduction
This is a combat card game between a computer and a player. If either one's health has been reduced to 0, then the game ends and the one who reduces the other's health to 0 wins. Due to the complexity of the cards and rules, please refer to the detail explanation below.
# 2.2 Gameplay Instuctions
In the beginning of the game, the computer and the player is each allocated with 4 random cards from the card pile. Both the computer and the player has 5 health points and this shall be the maximum health throughout the game.

Generally, this game is carried out by recurring rounds. In each round, player goes first, and be assigned with another 3 cards. Then during the player's round, player could use the available cards, note that the computer will automatically respond to the player's cards which require response (You may see the useage of each card later). When the player decides to end this round, he/she may follow the instruction on the screen to end the round. At the end of each round, the numner of cards that a player or computer has shall not exceed the current health point. The system will ask the player to discard some cards and for the computer it will automatically decide which cards to dsicard.

In a computer's round, computer will be generated 3 cards and automatically use available cards. After both the computer and the player end their rounds, one game round is finished. Then, if the game has not been finished (i.e. Both the computer and the player have positive health), then another game round will start and the player will be generated with another 3 cards. Then the game goes exactly as described above.
# 2.3 Card description
There are many cards in this game which correspond to different use. In each round the player may access the card list for the information of all cards, and the information of each card is also shown below.

In general, there are three types of cards, 

1. [ Ability ] cards should be activated by the player or the computer to be effective
2. [ Armor ] cards could be put on by the player or the computer on the "Armor" slot to have certain effects.
3. [ Weapon ] cards could be put on similarly on the "Weapon" slot.

Here are the usage of each card:
   TYPE          Name                      Description
1.  [ Ability ]    【 Attack 】       In attempt to cost 1 damage. 
2.  [ Ability ]    【 Dodge 】        In reponse to avoid 1 【 Attack 】.
3.  [ Ability ]    【 Heal 】         Gain 1 health, maximum health is 5.
4.  [ Ability ]    【 Demolish 】     Destroy/Discard one of the opponent's cards. 
5.  [ Ability ]    【 Plunder 】      Take one card from opponent's cards and turn it into an avable card for use.
6.  [ Ability ]    【 Invade 】       The opponent must use【Attack】in response, otherwise cost 1 damage.
7.  [ Ability ]    【 Rainfire 】     Cost 1 unavoidable damage, but can only be avoided if the opponent has put on【 Matrix 】.
8.  [ Ability ]    【 Duel 】         The one who has fewer【 Attack 】cards loses and receives 1 damage.
9.  [ Ability ]    【 Truce 】        Everyone's health increases by 1, maximum health is 5.
10. [ Weapon ]     【 Rifle 】        Inacvtive the opponent's armor.
11. [ Weapon ]     【 Casper 】       Every【 Attack 】will cost 2 damage, but can still be avoided by 1 【 Dodge 】.
12. [ Armor ]      【 Matrix 】       Immune to【 Rainfire】and【 Invade 】.
13. [ Armor ]      【 Shield 】       Immune to【 Demolish】.
 
# 3. Code Requirement Implementation
## 3.1 Generation of random games or events
(1) At the start of the game, 4 random cards are generated. 
(2) In each round, 2 cards will be generated for the player and the computer. 
## 3.2 Data structures for storing the game status
There are 4 totally data structures to store the game status.  
(1) A structure "Condition" has been used to store the player's and computer's current health, weapon, armor and cards.
(2) Inside the structure of the player and the computer, an array has been used to store the cards that the player or the computer has.
## 3.3 Dynamic memory management
In the structure, we use dynamic memory to access and change the current status of the player and computer. 
## 3.4 File input/output
(1) Current game status will be output to a file called "game_status.txt" once the player decides to quit the game.
(2) In the start of each game, the player may choose to load the archived game status or start a new game. If loading existing data has been chosen, the program will input the information inside "game_status.txt" (if exists), then the game continues by the game status stored last time when the player decides to exit the game.
## 3.5 Program codes in multiple files
Since most procedures in the game involve directly changing the global variable "player" and "computer" in the structure "Condition", and that the sections in the main file has been clearly divided, we have used a different file to store the function for saving the current game status.
Another "game_status.txt" file is used so that when the player enter the game without any existing data and select the option "load data", so that we generate the initial conditions inside this text file first and the game would continue as usual. When further a loading decision has been made this file will be overwritten.
## 3.6  Proper indentation and naming styles
1. For most of the variables, we have used names that are easy to read (i.e. player.health, player.armor,player.cardnum,...), apart from some of the trivial and temporary variables (i.e. temp, pc, ...) that are used to stored some date and be referenced shortly after declaration.
2. The functions defined by the names of the cards (i.e. heal(int input), truce(),...) are for activating thier fuctionalities whenever the card has been used.
3. The "Show()" and "Display" functions are used to show on the screen whenever a card has been used (either by the computer or the player) or at the start of each round for the player to make decisions according to the current game status.
4. The "ini_card", "generate_player_cards" and "generate_computer_cards" are used whenever some random cards should be generated for the computer or the player. For example, at the start of the game 4 cards are randomly generated for both the player and the computer and 2 cards will be generated in each round.
5. "player_round" and "use_card0" are functions executing the player's round, including asking the player to use cards.
6. "computer_round" and "use_card1" are used similarly but this time the strategy of the computer has been carefully designed so that it will make optimal dicisions each time.
7. One thing to notice is that the "attack()" function, even though seemingly the as most basic card in the game, may generate complex situations. Therefore, we have used the "computer_attacked()" to be called inside "attack()" for the computer to make decisions whenever the player uses 【 Attack 】. Also, "computer_attack()" is used whenever the computer decides to use 【 Attack 】and the player will asked to do decisions accordingly (use 【 Dodge 】!).
## 3.7  In-code documentation
Comments are given in the code for referencing the usage of the command.

# 4 HEAD FILES INCLUDE
<iostream>
<fstream>
<cstdlib>
"save_status.h"

