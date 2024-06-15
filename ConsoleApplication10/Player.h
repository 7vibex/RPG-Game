#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

enum CharacterClass {
    WIZARD,
    WARRIOR,
    ROGUE
};

class Player {
public:
    std::string name;
    std::string introText;
    CharacterClass characterClass;
    std::vector<std::string> inventory;
    int health;
    int specialAttackUsed;

    Player(std::string playerName, std::string playerIntro, CharacterClass playerClass);
    void attack(int& enemyHealth);
    void specialAttack(int& enemyHealth);
};

#endif // PLAYER_H
