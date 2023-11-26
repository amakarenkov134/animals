#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <cstring>
#include <Windows.h>
#include "Interact.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	vector<Animal*> animals;
	animals.push_back(new Rabbit("Кролик 1", 5, 0.3, true));
	animals.push_back(new Rabbit("Кролик 2", 5, 0.4, true));
	animals.push_back(new Moose("Лось 1", 10, 0.5, true));
	animals.push_back(new Moose("Лось 2", 10, 0.6, true));
	animals.push_back(new Wolf("Волк 1", 7, 3, 3, true));
	animals.push_back(new Wolf("Волк 2", 7, 4, 3, true));
	animals.push_back(new Fox("Лиса 1", 6, 2, 2, true));
	animals.push_back(new Fox("Лиса 2", 6, 1, 1, true));
	int epochs = 5;
	for (int i = 0; i < epochs; i++) {
		cout << boolalpha << endl << "Эпоха №" << i + 1 << endl;
		for (int x = 0; x < animals.size(); x++) {
			animals[x]->setIsNew(true);
		}
		if (animals.size() == 1) {
			cout << "Осталось одно животное!\n";
			break;
		}
		for (int j = 0; j < animals.size(); j++) {
			int randIndex = rand() % animals.size();
			while (randIndex == j) {
				randIndex = rand() % animals.size();
			}
			animals[j]->show();
			animals[randIndex]->show();
			if (typeid(*animals[j]).name() == typeid(*animals[randIndex]).name()) {
				if (animals[j]->getIsNew() && animals[randIndex]->getIsNew()) {
					cout << "Новое животное!\n";
					if (typeid(*animals[j]).name() == string("class Moose")) {
						animals.push_back(new Moose("Новый Лось " + to_string(i + 1), 10, 0.6, true));
					}
					else if (typeid(*animals[j]).name() == string("class Rabbit")) {
						animals.push_back(new Rabbit("Новый Заяц " + to_string(i + 1), 5, 0.3, true));
					}
					else if (typeid(*animals[j]).name() == string("class Fox")) {
						animals.push_back(new Fox("Новая Лиса " + to_string(i + 1), 5, 2, 2, true));
					}
					else if (typeid(*animals[j]).name() == string("class Wolf")) {
						animals.push_back(new Wolf("Новый Волк " + to_string(i + 1), 7, 4, 3, true));
					}
					animals.back()->show();
					animals[j]->setIsNew(false);
					animals[randIndex]->setIsNew(false);
				}
			}
			else {
				animals[j]->Interact(*animals[randIndex]);
				if (animals[j]->getHealth() == 0) {
					swap(animals[j], animals[animals.size() - 1]);
					animals.pop_back();
					continue;
				}
				else if (animals[randIndex]->getHealth() == 0) {
					swap(animals[randIndex], animals[animals.size() - 1]);
					animals.pop_back();
					continue;
				}
			}
		}
	}
	for (int i = 0; i < animals.size(); i++) {
		delete animals[i];
	}
	return 0;
}
