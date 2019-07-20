#include "Creature.h"

Creature::Creature(char symbol, int health, int attack, int gold, std::string name) :
                m_symbol{symbol}, m_health{health}, m_attack{attack}, m_gold{gold}, m_name{name} {
}

Creature::~Creature() {
}

const std::string& Creature::getName() const {
    return m_name;
}

char Creature::getSymbol() const {
    return m_symbol;
}

int Creature::getHealth() const {
    return m_health;
}

int Creature::getAttack() const {
    return m_attack;
}
int Creature::getGold() const {
    return m_gold;
}

void Creature::reduceHealth(int damage) {
    m_health -= damage;
}

void Creature::addGold(int gold) {
    m_gold += gold;
}

bool Creature::isDead() const {
    return m_health <= 0;
}