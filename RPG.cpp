#include "RPG.h"
#include <iostream>
#include <string>

using namespace std;


RPG::RPG(string name, int health, int strength, int defense, string type)
{
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
}

void RPG::printAction(string skill, RPG opponent)
{
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}


void RPG::setSkills()
{
    if (type == "mage"){
        skills[0] = "fire";
        skills[1] = "thunder";

    } else if (type == "thief"){
        skills[0] = "pilfer";
        skills[1] = "jab";

    } else if (type == "archer"){
        skills[0] = "parry";
        skills[1] = "crossbow_attack";

    } else{
        skills[0] = "Slash";
        skills[1] = "Parry";
    }

    cout << "Skills set: " << skills[0] << ", " << skills[1] << endl;

}

string RPG::getType() const
{
    return type;
}

string RPG::getName() const
{
    return name;
}

int RPG::getHealth() const
{
    return health;
}
void RPG::updateHealth(int update_health)
{
    health = update_health;
}
bool RPG::isAlive() const
{
    return health > 0;
}

int RPG::getStrength() const
{
    return strength;
}

int RPG::getDefense() const
{
    return defense;
}

void RPG::attack(RPG* opponent)
{
    int opp_health = (*opponent).getHealth();
    int opp_def = (*opponent).getDefense();
    int new_health = opp_health - (strength - opp_def);
    (*opponent).updateHealth(new_health);
}

void RPG::useSkill(RPG* opponent)
{
    for(int i = 0;i < SKILL_SIZE;i++){
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    int chosen_skill_index;

    printf("Choose a skill to use: Enter 0 or 1: ");
    cin >> chosen_skill_index;
    
    string chosen_skill = skills[chosen_skill_index];

    printAction(chosen_skill, (*opponent));

    attack(opponent);
}



