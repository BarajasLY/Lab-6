#include <iostream>
#include "RPG.h"

using namespace std;

void displayStats(RPG player1, RPG player2){

    cout << "Name: " << player2.getName() << ", Health: " << player2.getHealth() << endl;
    cout << "Name: " << player1.getName() << ", Health: " << player1.getHealth() << endl;
}

void displayEnd(RPG player1, RPG player2){

    if (player1.isAlive()){
        printf("Wiz had won\n");
    }
    else{
        printf("NPC had won\n");
    }
        
}

void gameLoop(RPG * player1, RPG * player2){

    while (player1->isAlive(), player2->isAlive()){
        cout << "Player 1 turn" << endl;
        displayStats((*player1), (*player2));
        (*player1).useSkill(player2);
        printf("-------------------\n");

    
        cout << "Player 2 turn" << endl;
        displayStats((*player1), (*player2));
        (*player2).useSkill(player1);
        printf("-------------------\n");

}
}


int main()
{
    RPG player1 = RPG("Wiz", 75, 50, 10, "mage");
    RPG player2 = RPG("NPC", 30, 10, 10, "warrior");

    gameLoop(&player1, &player2);
    displayEnd(player1, player2);
    return 0;
}

