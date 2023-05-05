# COMP-2113-Course-Project
# COMP-2113-group129
## Group members:  
Name: Chaoyi   UID: 3035845136
Name: Lin Qianli  UID: 3035947348
# 1. General information  
## 1.1 Execution Instruction:
Please click "code" and then download the zip.  
Open the zip file with a folder, then you may use the files inside the folder for execution.

# 2. Introduction
# 1.1 Game Introduction
This is a combat card game between a computer and a player. If either one's health has been reduced to 0, then the game ends and the one who reduces the other's health to 0 wins. Due to the complexity of the cards and rules, please refer to the detail explanation below.
# 1.2 Gameplay Instuctions
In the beginning of the game, the computer and the player is each allocated with 4 random cards from the card pile. Both the computer and the player has 5 health points and this shall be the maximum health throughout the game.

Generally, this game is carried out by recurring rounds. In each round, player goes first, and be assigned with another 3 cards. Then during the player's round, player could use the available cards, note that the computer will automatically respond to the player's cards which require response (You may see the useage of each card later). When the player decides to end this round, he/she may follow the instruction on the screen to end the round. At the end of each round, the numner of cards that a player or computer has shall not exceed the current health point. The system will ask the player to discard some cards and for the computer it will automatically decide which cards to dsicard.

In a computer's round, computer will be generated 3 cards and automatically use available cards. After both the computer and the player end their rounds, one game round is finished. Then, if the game has not been finished (i.e. Both the computer and the player have positive health), then another game round will start and the player will be generated with another 3 cards. Then the game goes exactly as described above.
# 1.3 Card description
There are many cards in this game which correspond to different use. In each round the player may access the card list for the information of all cards, and the information of each card is also shown below.

In general, there are three types of cards, 

1. [ Ability ] cards should be activated by the player or the computer to be effective
2. [ Armor ] cards could be put on by the player or the computer on the "Armor" slot to have certain effects.
3. [ Weapon ] cards could be put on similarly on the "Weapon" slot.

Here are the usage of each card:
   TYPE          Name                      Description
 [ Ability ]    【 Attack 】       In attempt to cost 1 damage.\n
 [ Ability ]    【 Dodge 】        In reponse to avoid 1 【 Attack 】.
 [ Ability ]    【 Heal 】         Gain 1 health, maximum health is 5.
 [ Ability ]    【 Demolish 】     Destroy/Discard one of the opponent's cards.
 [ Ability ]    【 Plunder 】      Take one card from opponent's cards and turn it into an avable card for use.
 [ Ability ]    【 Invade 】       The opponent must use【Attack】in response, otherwise cost 1 damage.
 [ Ability ]    【 Rainfire 】     Cost 1 unavoidable damage, but can only be avoided if the opponent has put on【 Matrix 】.
 [ Ability ]    【 Duel 】         The one who has fewer【 Attack 】cards loses and receives 1 damage.
 [ Ability ]    【 Truce 】        Everyone's health increases by 1, maximum health is 5.
 [ Weapon ]     【 Rifle 】        Inacvtive the opponent's armor.
 [ Weapon ]     【 Casper 】       Every【 Attack 】will cost 2 damage, but can still be avoided by 1 【 Dodge 】.
 [ Armor ]      【 Matrix 】       Immune to【 Rainfire】and【 Invade 】.
 [ Armor ]      【 Shield 】       Immune to【 Demolish】.
 
 










