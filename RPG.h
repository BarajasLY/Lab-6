#ifndef RPG_h
#define RPG_h

#include <iostream>
#include <string> 

using namespace std;

const int SKILL_SIZE = 2;

class RPG {
public:
    // Constructors
    RPG();
    RPG(string name, int health, int strength, int defense, string type);

    void setSkills();
    void printAction(string skill, RPG opponent);
    void updateHealth(int update_health);

    bool isAlive() const;
    string getType() const;
    string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;

    void attack(RPG*);
    void useSkill(RPG*);
    

private:
    string type;
    string skills[SKILL_SIZE];

    string name;
    int health;
    int strength;
    int defense;
};

#endif
