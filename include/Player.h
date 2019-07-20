#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include <string>

class Player : public Creature {
private:
    int m_level{1};
public:
    Player(char symbol = '@', int health = 10, int attack = 1, int gold = 0);
    ~Player();

    int getLevel() const;

    void levelUp();
    bool hasWon() const;
};

#endif