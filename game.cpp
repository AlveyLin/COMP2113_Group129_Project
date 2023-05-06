//game.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "save_status.h"

using namespace std;

void Display(int cardtype){
    // This function is called whenever cards are asked to be displayed.
    switch(cardtype){
        case 1: cout << "  [Ability] " << " 【 Attack 】" << endl; break;
        case 2: cout << "  [Ability] " << " 【 Dodge 】" << endl; break;
        case 3: cout << "  [Ability] " << " 【 Heal 】" << endl; break;
        case 4: cout << "  [Ability] " << " 【 Demolish 】" << endl; break;
        case 5: cout << "  [Ability] " << " 【 Plunder 】" << endl; break;
        case 6: cout << "  [Ability] " << " 【 Invade 】" << endl; break;
        case 7: cout << "  [Ability] " << " 【 Rainfire 】" << endl; break;
        case 8: cout << "  [Ability] " << " 【 Duel 】" << endl; break;
        case 9: cout << "  [Ability] " << " 【 Truce 】" << endl; break;
        case 10: cout << " [Weapon]  " << " 【 Rifle 】" << endl; break;
        case 11: cout << " [Weapon]  " << " 【 Casper 】" << endl; break;
        case 12: cout << " [Armor]   " << " 【 Matrix 】" << endl; break;
        case 13: cout << " [Armor]   " << " 【 Shield 】" << endl; break;
    }
}

int cardpile; // This variable is used as a global variable to generate different card piles in the start of each game.

int stack_1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,9,10,10,11,11,12,12,13,13};

int stack_2[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,11,11,12,12,13,13};

int stack_3[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,11,11,12,12,13,13};

int stack_4[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,11,11,12,12,13,13};

int stack_5[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,11,11,12,12,13,13};

int stack_6[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,11,11,12,12,13,13};
// The above are just some random piles but with small changes that would not affect the proportion of card distribution too much to ensure that rand() generates different outcomes when different piles are chosen.


int ini_card(int cardpile){
    // According to different numbers chosen at the beginning, this function generates corresponding piles.
    int rand_card = 1 + rand() % 64;
    if (cardpile == 0){
        return stack_1[rand_card];
    }
    if (cardpile == 1){
        return stack_2[rand_card];
    }
    if (cardpile == 2){
        return stack_3[rand_card];
    }
    if (cardpile == 3){
        return stack_4[rand_card];
    }
    if (cardpile == 4){
        return stack_5[rand_card];
    }
    if (cardpile == 5){
        return stack_6[rand_card];
    }
    return 0;
}

struct Condition{
    // Structure for the computer and the player.
    int health;
    int cardnum;
    int card[10];
    int armor;
    int weapon;
};


Condition player;
Condition computer;

void Show(){
    // This function is called every time when data is asked to be displayed.
    computer.cardnum = 0;
    for (int i = 0; i < 10; i++){
        if (computer.card[i] > 0){
            computer.cardnum += 1;
        }
    }
    cout << "Computer's health:           " << computer.health << endl;
    cout << "Computer's cards number:     " << computer.cardnum << endl;
    if (computer.weapon == 10){
        cout << "Computer's weapon:           " << "Rifle" << endl;
    }
    else if (computer.weapon == 11){
        cout << "Computer's weapon:           " << "Casper" << endl;
    }
    else {
        cout << "Computer's weapon:           Empty" << endl;
    }
    if (computer.armor == 12){
        cout << "Computer's armor:            " << "Matrix" << endl;
    }
    else if(computer.armor == 13){
        cout << "Computer's armor:            " << "Shield" << endl;
    }
    else {
        cout << "Computer's armor:            Empty" << endl;
    }
    cout << endl;
    cout << "***********************************" << endl;
    cout << endl;
    cout << "Player's health:             " << player.health << endl;
    player.cardnum = 0;
    for (int i = 0; i < 10; i++){
        if (player.card[i] > 0){
            player.cardnum += 1;
        }
    }
    cout << "Player's cards number:       " << player.cardnum << endl;
    if (player.weapon == 10){
        cout << "Player's weapon:             " << "Rifle" << endl;
    }
    else if (player.weapon == 11){
        cout << "Player's weapon:             " << "Casper" << endl;
    }
    else {
        cout << "Player's weapon:             Empty" << endl;
    }
    if (player.armor == 12){
        cout << "Player's armor:              " << "Matrix" << endl;
    }
    else if (player.armor == 13){
        cout << "Player's armor:              " << "Shield" << endl;
    }
    else {
        cout << "Player's armor:              Empty" << endl;
    }
    cout << endl;
    cout << "Player's cards: " << endl;
    for (int i = 0; i < 10; i++){
        if (player.card[i] > 0){
        cout << player.card[i] << " "; Display(player.card[i]);}
    }
}

void generate_player_card(){
    // Generate random player cards.
    for (int i = 0; i < 10; i++){
        if (player.card[i] > 0);
        else{
            player.card[i] = ini_card(cardpile);
            break;
        }
    }
    player.cardnum += 1;
}

void generate_computer_card(){
    // Generate random computer cards.
    for (int i = 0; i < 10; i++){
        if (computer.card[i] > 0);
        else{
            computer.card[i] = ini_card(cardpile);
            break;
        }
    }
    computer.cardnum += 1;
}

void comp_attack(){
    // This function is used for the computer to make independent decision on using【 Attack 】.
    cout << "Computer used【 Attack 】,";
    int player_dodge = 0, temp;
    for (int i = 0; i < 10; i++){
        if (player.card[i] == 2){
            player_dodge += 1;
            temp = i;
        }
    }
    if (player_dodge == 0){
        if (computer.weapon != 11){
            cout << "Player received 1 damage." << endl;
            player.health -= 1;
        }
        else if (computer.weapon == 11){
            cout << "Player received 2 damage." << endl;
            player.health -= 2;
        }
    }
    else if (player_dodge > 0){
        cout << " Please use dodge, input card number: " << endl;
        int input;
        cin >> input;
        if (input == 2){
            cout << "Player used 【 Dodge 】." << endl;
            cout << endl;
            for (int i = 0; i < 10; i++){
                if (player.card[i] == 2){
                    player.card[i] = -1;
                    player.cardnum -= 1;
                    break;
                }
            }
        }
        while (input != 2){
            cout << "This card is invalid! Please input again." << endl;
            cin >> input;
        }
    }
}

void comp_attacked(){
    // This function generates automatic response to【 Attack 】from the computer.
    int count_dodge = 0, temp = 0;
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 2){
            count_dodge += 1;
            temp = i;
        }
    }
    if (count_dodge > 0){
        cout << "Computer used card【 dodge 】." << endl;
        cout << endl;
        computer.card[temp] = -1;
        computer.cardnum -= 1;
    }
    else {
        cout << "Computer received 1 damage." << endl;
        cout << endl;
        computer.health -= 1;
    }
}
    
void comp_attacked_casper(){
    // This fucntion is used when the player has put on the weapon【 Casper 】and used【 Attack 】.
    int count_dodge = 0, temp = 0;
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 2){
            count_dodge += 1;
            temp = i;
        }
    }
    if (count_dodge > 0){
        cout << "Computer used card【 dodge 】." << endl;
        cout << endl;
        computer.card[temp] = -1;
        computer.cardnum -= 1;
    }
    else {
        cout << "Computer received 2 damage." << endl;
        cout << endl;
        computer.health -= 2;
    }
}

void attack(int input){
    // This is a general【 Attack 】card function to be activated when called.
    if (player.weapon == 11){
        comp_attacked_casper();
    }
    else{
        comp_attacked();
    }
}

void heal(int input){
    // Using the【 Heal 】card.
    if (input == 0){
        if (player.health < 5){
            cout << "Player used【 Heal 】." << endl;
            player.health += 1;
        }
    }
    else{
        if (computer.health < 5){
            cout << "Computer used【 Heal 】." << endl;
            computer.health += 1;
        }
    }
}


void truce(int input){
    // Using the【 Truce 】card.
    if (input == 0){
        cout << "Player used【 Truce 】." << endl;
        cout << endl;
    }
    else if (input == 1){
        cout << "Computer used【 Truce 】." << endl;
        cout << endl;
    }
    if (player.health < 5){
        player.health += 1;
    }
    if (computer.health < 5){
        computer.health += 1;
    }
}

void rifle(int input){
    // Put on the【 Rifle 】weapon.
    if (input == 0){
        cout << "Player used【 Rifle 】." << endl;
        cout << endl;
        player.weapon = 10;
    }
    else if (input == 1){
        cout << "Computer used【 Rifle 】." << endl;
        cout << endl;
        computer.weapon = 10;
    }
}

void demolish(int input){
    // Using the【 Demolish 】card.
    if (input == 1){
        if (computer.armor == 13 && player.weapon != 10){
            cout << "Computer has【 Shield 】, demoish is not effective." << endl;
            cout << endl;
        }
        else{
            for (int i = 0; i < 10; i++){
                if (computer.card[i] > 0){
                    computer.card[i] = -1;
                    computer.cardnum -= 1;
                    cout << "Player used【 Demolish 】." << endl;
                    cout << endl;
                    break;
                }
            }
        }
    }
    else{
        if (player.armor == 13 && computer.weapon != 10){
            cout << "Player has【 Shield 】, demoish is not effective." << endl;
            cout << endl;
        }
        else{
            for (int i = 0; i < 10; i++){
                if (player.card[i] > 0){
                    player.card[i] = -1;
                    player.cardnum -= 1;
                    cout << "Computer used【 Demolish 】." << endl;
                    cout << endl;
                    break;
                }
            }
        }
    }
}

void matrix(int input){
    // Put on the【 Matrix 】armor.
    if (input == 0){
        cout << "Player used【 Matrix 】." << endl;
        cout << endl;
        player.armor = 12;
    }
    else if (input == 1){
        cout << "Computer used【 Matrix 】." << endl;
        cout << endl;
        computer.armor = 12;
    }
}

void shield(int input){
    // Put on the【 Shield 】armor.
    if (input == 0){
        cout << "Player used【 Shield 】." << endl;
        cout << endl;
        player.armor = 13;
    }
    else if (input == 1){
        cout << "Computer used【 Shield 】." << endl;
        cout << endl;
        computer.armor = 13;
    }
}

void plunder(int input){
    // Using the【 Plunder 】card.
    if (computer.cardnum == 0 || player.cardnum ==0){
        cout << "No card available for plunder!" << endl;
        cout << endl;
    }
    else{
        int temp1 = 0, pos1 = 0;
        for (int i = 0; i < 10; i++){
            if (computer.card[i] > 0){
                temp1 = computer.card[i];
                pos1 = i;
                break;
            }
        }
        int temp2 = 0, pos2 = 0;
        for ( int i = 0; i < 10; i++){
            if (player.card[i] > 0){
                temp2 = player.card[i];
                pos2 = i;
                break;
            }
        }
    if (input == 1){
        cout << "Player used【 Plunder 】." << endl;
        cout << endl;
        for (int i = 0; i < 10; i++){
            if (player.card[i] > 0);
            else {
                player.card[i] = temp1;
                player.cardnum += 1;
                break;
            }
        }
        computer.card[pos1] = -1;
        computer.cardnum -= 1;
    }
        if (input == 0){
        cout << "Computer used【 Plunder 】." << endl;
        for (int i = 0; i < 10; i++){
            if (computer.card[i] > 0);
            else {
                computer.card[i] = temp2;
                computer.cardnum += 1;
                break;
            }
        }
        player.card[pos2] = -1;
        player.cardnum -= 1;
        }
    }
}

void invade(int input){
    // Using the【 Invade 】card.
    if (input == 1){
        if (computer.armor == 12 && player.weapon != 10){
            cout << "Computer has【 Matrix 】, this card is ineffective." << endl;
            cout << endl;
        }
        else {
            int count_attack = 0, temp = 0;
            for (int i = 0; i < 10; i++){
                if (computer.card[i] == 1){
                    count_attack += 1;
                    temp = i;
                }
            }
            cout << "Player used【 Invade 】." << endl;
            if (count_attack == 0){
                cout << "Computer received 1 damage." << endl;
                cout << endl;
                computer.health -= 1;
            }
            else if (count_attack > 0){
                cout << "Computer used【 Attack 】." << endl;
                cout << endl;
                computer.card[temp] = -1;
                computer.cardnum -= 1;
            }
        }
    }
}

void duel(int input){
    // Using the【 Duel 】card.
    if (input == 0){
        cout << "Player used【 Duel 】." << endl;
        cout << endl;
    }
    else if (input == 1){
        cout << "Computer used【 Duel 】." << endl;
        cout << endl;
    }
    int count_pa = 0, count_ca = 0;
    for (int i = 0; i < 10; i++){
        if (player.card[i] == 1){
            count_pa += 1;
            player.card[i] = -1;
        }
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 1){
            count_ca += 1;
            computer.card[i] = -1;
        }
    }
    if (count_pa > count_ca){
        cout << "Computer received 1 damage." << endl;
        cout << endl;
        computer.health -= 1;
    }
    else if (count_pa < count_ca){
        cout << "Player received 1 damage." << endl;
        cout << endl;
        player.health -= 1;
    }
    else if (count_pa == count_ca){
        cout << "Draw duel. No damage." << endl;
        cout << endl;
    }
}

void casper(int input){
    // Put on the【 Casper 】weapon.
    if (input == 0){
        cout << "Player used【 Casper 】." << endl;
        cout << endl;
        player.weapon = 11;
    }
    else if (input == 1){
        cout << "Computer used【 Casper 】." << endl;
        cout << endl;
        computer.weapon = 11;
    }
}

void rainfire(int input){
    // Using the【 Rainfire 】card.
    if (computer.armor == 12){
        cout << "Computer has【 Matrix 】, this card is ineffective." << endl;
        cout << endl;
    }
    else{
        if (input == 1){
            cout << "Player used【 Rainfire 】. Computer received 1 damage." << endl;
            cout << endl;
            computer.health -= 1;
        }
        else{
            cout << "Computer used【 Rainfire 】. Player received 1 damage." << endl;
            cout << endl;
            player.health -= 1;
        }
    }
}

void command(){
    // This function is used for referencing the ability of each card.
    cout << "【 Attack 】   :   In attempt to cost 1 damage" << endl;
    cout << "【 Dodge 】    :   In reponse to avoid 1 damage" << endl;
    cout << "【 Heal 】     :   Gain 1 health, maximum health is 5" << endl;
    cout << "【 Demolish 】 :   Destroy one of the opponent's cards" << endl;
    cout << "【 Plunder 】  :   Take one card from opponent's cards" << endl;
    cout << "【 Invade 】   :   The opponent must use【 Attack 】in response, otherwise cost 1 damage" << endl;
    cout << "【 Rainfire 】 :   Cost 1 unavoidable damage" << endl;
    cout << "【 Duel 】     :   The one who has fewer【 Attack 】loses and receives 1 damage" << endl;
    cout << "【 Truce 】    :   Everyone's health increases by 1" << endl;
    cout << "【 Rifle 】    :   Inacvtive opponent's armor" << endl;
    cout << "【 Casper 】   :   Use【 Attack 】costs 2 damage" << endl;
    cout << "【 Matrix 】   :   Immune to【 Invade 】and【 Rainfire 】" << endl;
    cout << "【 Shield 】   :   Immune to【 Demolish 】" << endl;
    cout << endl;
}

void usecard0(int input){
    // This function is used when player uses a card.
    if (input == 1){
        attack(1);
    }
    else if (input == 3){
        heal(0);
    }
    else if (input == 4){
        demolish(1);
    }
    else if (input == 5){
        plunder(1);
    }
    else if (input == 6){
        invade(1);
    }
    else if (input == 7){
        rainfire(1);
    }
    else if (input == 8){
        duel(0);
    }
    else if (input == 9){
        truce(0);
    }
    else if (input == 10){
        rifle(0);
    }
    else if (input == 11){
        casper(0);
    }
    else if (input == 12){
        matrix(0);
    }
    else if (input == 13){
        shield(0);
    }
    else if (input == 0){
        command();
    }
    for (int i = 0; i < 10; i++){
        if (player.card[i] == input){
            player.card[i] = -1; break;
        }
    }
    player.cardnum -= 1;
    Show();
}

void usecard1(int input){
    // This function is used whenever the computer uses a card.
    if (input == 1){
        comp_attack();
    }
    else if (input == 3){
        heal(1);
    }
    else if (input == 4){
        demolish(0);
    }
    else if (input == 5){
        plunder(0);
    }
    else if (input == 7){
        rainfire(0);
    }
    else if (input == 8){
        duel(1);
    }
    else if (input == 9){
        truce(1);
    }
    else if (input == 10){
        rifle(1);
    }
    else if (input == 11){
        casper(1);
    }
    else if (input == 12){
        matrix(1);
    }
    else if (input == 13){
        shield(1);
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == input){
            computer.card[i] = -1; break;
        }
    }
    computer.cardnum -= 1;
    Show();
}

void computer_round(){
    // This function is used for the computer to make rational deicisions accrodingly in each round.
    Show();
    int count_attack = 0, count_heal = 0, count_demolish = 0, count_plunder = 0, count_rainfire = 0;
    int count_truce = 0, count_rifle = 0, count_casper = 0, count_matrix = 0, count_shield = 0;
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 1){
            count_attack += 1;
        }
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 3){
            count_heal += 1;
        }
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 4){
            count_demolish += 1;
        }
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 5){
            count_plunder += 1;
        }
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 7){
            count_rainfire += 1;
        }
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 9){
            count_truce += 1;
        }
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 10){
            count_rifle += 1;
        }
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 11){
            count_casper += 1;
        }
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 12){
            count_matrix += 1;
        }
    }
    for (int i = 0; i < 10; i++){
        if (computer.card[i] == 13){
            count_shield += 1;
        }
    }
    if (count_rifle > 0 && count_casper == 0 && computer.weapon != 11){
        usecard1(10);
    }
    if (count_casper > 0 && count_rifle == 0){
        usecard1(11);
    }
    if (count_casper > 0 && count_rifle > 0){
        usecard1(11);
    }
    if (computer.weapon == 10 && count_casper > 0){
        usecard1(11);
    }
    if (count_matrix > 0 && count_shield == 0){
        usecard1(12);
    }
    if (count_shield > 0 && count_matrix == 0){
        usecard1(13);
    }
    if (count_matrix > 0 && count_shield > 0){
        usecard1(13);
    }
    while (computer.health < 5 && count_heal > 0){
        usecard1(3);
        count_heal -= 1;
    }
    while (computer.health < player.health && count_truce > 0){
        usecard1(9);
        count_truce -= 1;
    }
    while (count_plunder > 0 && player.armor != 13){
        usecard1(5);
        count_plunder -= 1;
    }
    while (count_demolish > 0 && player.armor != 13){
        usecard1(4);
        count_demolish -= 1;
    }
    while (count_rainfire > 0 && player.armor != 12){
        usecard1(7);
        count_rainfire -= 1;
    }
    while (count_attack > 0){
        usecard1(1);
        count_attack -= 1;
    }
    if (computer.cardnum > computer.health){
        cout << "Computer discarded some cards." << endl;
        cout << endl;
    }
    while (computer.cardnum > computer.health){
        for (int i = 0; i < 10; i++){
            if (computer.card[i] > 0 && computer.cardnum > computer.health){
                computer.card[i] = -1;
                computer.cardnum -= 1;
            }
        }
    }
}

int QUIT_GAME = 0;
// Global variable declared for use when quiting the game.

void player_round(){
    // This function is called every time when it is the player's turn.
    Show();
    cout << "It is now your turn. Please input card number, input 0 to view the card skills, input -1 to end your round, or input -2 to quit the game: ";
    int input;
    cin >> input;
    while (input != -1 && input != -2){
        usecard0(input);
        cin >> input;
    }
    int discard, temp = 0;
    if (player.cardnum > player.health){
        cout << "Please discard your cards. Maximum cards number allowed is: " << player.health << "." << endl;
    }
    while (player.cardnum > player.health){
        cin >> discard;
        for (int i = 0; i < 10; i++){
            if (player.card[i] == discard){
                temp = i;
            }
        }
        player.card[temp] = -1;
        player.cardnum -= 1;
    }
    Show();
    if (input == -1){
        cout << "It is now computer's turn." << endl;
        cout << endl;
    }
    else if (input == -2){
        QUIT_GAME = 1;
    }
}



int main() {
    // Main function for initialisation and start of the game.
    cout << "Load game or start a new game? Input 1 to load game, input 0 to start new game: ";
    int input;
    cin >> input;
    if (input == 1){// Loading data from existing archive.
        Condition *p_addr, *c_addr;
        p_addr = new Condition; 
        c_addr = new Condition;
        ifstream fin;
        fin.open("game_status.txt");
        if (fin.fail()){
            cout << "Error in lodaing data, please make sure that you have successfully saved game status last time when exiting again." << endl;
        }
        else{
            int ph, pa, pw, ch, ca, cw;
            int p[10], c[10];
            fin >> ph;
            fin >> pa;
            fin >> pw;
            for (int i = 0; i < 10; i++){
                fin >> p[i];
            }
            fin >> ch;
            fin >> ca;
            fin >> cw;
            for (int i = 0; i < 10; i++){
                fin >> c[i];
            }
            (*p_addr).health = ph;
            (*p_addr).armor = pa;
            (*p_addr).weapon = pw;
            player.health = (*p_addr).health;
            player.weapon = (*p_addr).weapon;
            player.armor = (*p_addr).armor;
            for (int i = 0; i < 10; i++){
                (*p_addr).card[i] = p[i];
                player.card[i] = (*p_addr).card[i];
            }
            (*c_addr).health = ch;
            (*c_addr).armor = ca;
            (*c_addr).weapon = cw;
            computer.health = (*c_addr).health;
            computer.weapon = (*c_addr).weapon;
            computer.armor = (*c_addr).armor;
            for (int i = 0; i < 10; i++){
                (*c_addr).card[i] = c[i];
                computer.card[i] = (*c_addr).card[i];
            }
            cout << player.health << endl;
            cout << player.armor << endl;
            cout << player.weapon << endl;
            for (int i = 0; i < 10; i++){
                cout << player.card[i] << endl;
            }
            cout << computer.health << endl;
            cout << computer.armor << endl;
            cout << computer.weapon << endl;
            for (int i = 0; i < 10; i++){
                cout << computer.card[i] << endl;
        }}
        fin.close();
        generate_computer_card();
        generate_computer_card();
        generate_computer_card();
        computer_round();
        }

    else if (input == 0){ // Starting a new game
        player.health = 5;
        computer.health = 5;
        int cardpile;
        cout << "Please choose a card pile for this game by inputing an integer from 0 to 5 inclusive: ";
        cin >> cardpile;
        ini_card(cardpile);
        for (int i = 0; i <= 3; i++){
            generate_player_card();
            generate_computer_card();
        }
    }
    while (player.health > 0 && computer.health > 0){
        generate_player_card();
        generate_player_card();
        generate_player_card();
        player_round();
        if (player.health > 0 && computer.health > 0 &&  QUIT_GAME != 1){
            generate_computer_card();
            generate_computer_card();
            generate_computer_card();
            computer_round();
        }
        else{
            QUIT_GAME = 0;
            break;
        }
    }
    if (player.health <= 0){
        cout << "Game over! Computer wins." << endl;
    }
    else if (computer.health <= 0){
        cout << "Congratulations! Player wins." << endl;
    }
    else {
        cout << "You quit the game." << endl;
        save_status(player.health, player.armor, player.weapon, player.card, computer.health, computer.armor, computer.weapon, computer.card);
    }
        
    return 0;
}
