#include "Monster.h"
#include "RandomGenerator.h"
#include <iostream>

Monster::MonsterData Monster::s_monsterData[NUM_TYPE] {
    {"dragon", 'D', 20, 4, 100},
	{"orc", 'o', 4, 2, 25},
	{"slime", 's', 1, 1, 10}
};

Monster Monster::getRandomMonster() {
    return Monster(static_cast<Type>(getRandomNumber(0, NUM_TYPE - 1)));
}

Monster::Monster(Type type) : Creature(s_monsterData[type].symbol, 
                                        s_monsterData[type].health,
                                        s_monsterData[type].attack,
                                        s_monsterData[type].gold,
                                        s_monsterData[type].name) {
}

Monster::~Monster() {
}