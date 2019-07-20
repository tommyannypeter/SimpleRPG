#include "Player.h"
#include <iostream>

Player::Player(char symbol, int health, int attack, int gold) :
                Creature(symbol, health, attack, gold) {
    std::cout << "Enter your name: ";
    std::cin >> m_name;
    std::cout << "Welcome, " << m_name << ".\n";
}

Player::~Player() {
}

int Player::getLevel() const {
    return m_level;
}

void Player::levelUp() {
    ++m_level;
    ++m_attack;
    ++m_health;
}

bool Player::hasWon() const {
    return m_level >= 20;
}