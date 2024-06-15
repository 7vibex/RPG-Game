#include "Player.h"



Player::Player(std::string playerName, std::string playerIntro, CharacterClass playerClass) {
    name = playerName;
    introText = playerIntro;
    characterClass = playerClass;
    health = 15; 
    specialAttackUsed = 0; // Niciun atac special folosit la început
}

void Player::attack(int& enemyHealth) {
    // Atac normal
    enemyHealth -= 2;
}

void Player::specialAttack(int& enemyHealth) {
    // Atac special
    if (specialAttackUsed == 0) {
        enemyHealth -= std::rand() % 3 + 3 ; // Atacul special face mai multe daune
        specialAttackUsed = 1; // Marc?m atacul special ca folosit
    }
}