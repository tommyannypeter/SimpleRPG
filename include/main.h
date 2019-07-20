#ifndef MAIN_H
#define MAIN_H

#include "Player.h"
#include "Monster.h"

void fightMonster(Player &player, Monster &monster);
void attackMonster(Player &player, Monster &monster);
void attackPlayer(Player &player, Monster &monster);

#endif