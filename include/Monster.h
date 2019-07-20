#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
#include <string>

class Monster : public Creature {
private:
    struct MonsterData {
        std::string name;
        char symbol;
        int health;
        int attack;
        int gold;
    };
    
public:
    enum Type {
        DRAGON, 
        ORC, 
        SLIME, 
        NUM_TYPE
    };

private:
    static MonsterData s_monsterData[NUM_TYPE];

public:
    Monster(Type type);
    ~Monster();
    
    static Monster getRandomMonster();
};

#endif