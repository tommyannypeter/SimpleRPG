#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature {
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_attack;
    int m_gold;

public:
    Creature(char symbol, int health, int attack, int gold, std::string name = "");
    ~Creature();

    const std::string& getName() const;
    char getSymbol() const;
    int getHealth() const;
    int getAttack() const;
    int getGold() const;

    void reduceHealth(int damage);
    void addGold(int gold);
    bool isDead() const;
};

#endif