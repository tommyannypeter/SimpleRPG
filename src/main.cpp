#include <iostream>
#include <string>
#include "main.h"
#include "RandomGenerator.h"
#include <ctime> // for time()

int main() {
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // get rid of first result
 
	Player player;
	while (true) {
		Monster monster = Monster::getRandomMonster();
		std::cout << "\nYou have encountered a " << monster.getName() <<
					" (" << monster.getSymbol() << ").\n";
		fightMonster(player, monster);
		if (player.isDead()) {
			std::cout << "\nYou died at level " << player.getLevel() <<
						" and with " << player.getGold() << " gold.\n";
			std::cout << "Too bad you can't take it with you!\n";
			break;
		}
		else if (player.hasWon()) {
			std::cout << "\nYou won! Congratulations!\n";
			std::cout << "You reached level 20 and got " << player.getGold() << " gold!\n";
			std::cout << "Hope you have a nice time with this game! :)\n";
			break;
		}
	}
 
    system("pause");
	return 0;
}

void fightMonster(Player &player, Monster &monster) {
	char choice;
	while (!monster.isDead() && !player.isDead()) {
		do {
			std::cout << "You have " << player.getHealth() << " hp now.\n";
			std::cout << "(R)un or (F)ight: ";
			std::cin >> choice;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else std::cin.ignore(32767, '\n');
		} while (choice != 'r' && choice != 'R' && choice != 'f' && choice != 'F');
		if (choice == 'f' || choice == 'F') {
			attackMonster(player, monster);
			attackPlayer(player, monster);
		}
		else {
			if (getRandomNumber(0, 1)) {
				std::cout << "You successfully fled.\n";
				return;
			}
			else {
				std::cout << "You failed to flee.\n";
				attackPlayer(player, monster);
			}
		}
	}
}

void attackMonster(Player &player, Monster &monster) {
	if (player.isDead()) return;

	monster.reduceHealth(player.getAttack());
	std::cout << "You hit the " << monster.getName() << " for " << player.getAttack() << " damage.\n";
	if (monster.isDead()) {
		player.levelUp();
		player.addGold(monster.getGold());
		std::cout << "You killed the " << monster.getName() << ".\n";
		std::cout << "You are now level " << player.getLevel() << ".\n";
		std::cout << "You found " << monster.getGold() << " gold.\n";
	}
}

void attackPlayer(Player &player, Monster &monster) {
	if (monster.isDead()) return;

	player.reduceHealth(monster.getAttack());
	std::cout << "The " << monster.getName() << " hit you for " << monster.getAttack() << " damage.\n";
}