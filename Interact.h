#include <string>
#include <iostream>
#include "Animal.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Wolf.h"
#include "Fox.h"
#include "Moose.h"
#include "Rabbit.h"

using namespace std;

void Herbivore::Interact(Animal& other) {
	Herbivore* herb = dynamic_cast<Herbivore*>(&other);
	if (herb) {
		cout << endl << herb->name << " ���������� � " << name << " ������ �� ���������!\n";
	}
	Carnivore* carn = dynamic_cast<Carnivore*>(&other);
	if (carn) {
		double randNum = (double)rand() / RAND_MAX;

		if (randNum > luck) {
			health = 0;
			carn->increaseHungry();
			cout << endl << name << " ����� �� " << carn->getName() << endl;
		}
		else {
			carn->decreaseHungry();
			cout << endl << name << " ������ �� " << carn->getName() << endl;
			cout << "����� " << carn->getName() << " = " << carn->getHungry() << endl;
			if (carn->getHungry() == 0) {
				carn->setHealth(0);
				cout << carn->getName() << " ����� �� ������.\n";
			}
		}
	}
}

void Carnivore::Interact(Animal& other) {
	Herbivore* herb = dynamic_cast<Herbivore*>(&other);
	if (herb) {
		double randNum = (double)rand() / RAND_MAX;
		if (randNum > herb->getLuck()) {
			herb->setHealth(0);
			hungry++;
			cout << endl << herb->getName() << " ����� �� " << name << endl;
		}
		else {
			hungry--;
			cout << endl << herb->getName() << " ������ �� " << name << endl;
			cout << "����� " << name << " = " << hungry << endl;
			if (hungry == 0) {
				health = 0;
				cout << name << " ����� �� ������.\n";
			}
		}
	}
	Carnivore* carn = dynamic_cast<Carnivore*>(&other);
	if (carn) {
		double randNum = (double)rand() / RAND_MAX;
		if (strength == carn->getStrength()) {
			cout << endl << "���������� ���� � ��������" << endl;
		}
		else {
			if (randNum > 0.85) {
				if (strength > carn->getStrength()) {
					carn->setHealth(0);
					hungry++;
					cout << endl << name << " ������� " << carn->getName() << endl;
				}
				else {
					health = 0;
					carn->increaseHungry();
					cout << endl << carn->getName() << " ������� " << name << endl;
				}
			}
			else {
				if (strength < carn->getStrength()) {
					carn->setHealth(0);
					hungry++;
					cout << endl << name << " ������� " << carn->getName() << endl;
				}
				else {
					health = 0;
					carn->increaseHungry();
					cout << endl << carn->getName() << " ������� " << name << endl;
				}
			}
		}

	}
}
