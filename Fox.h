#include <iostream>

using namespace std;

class Fox : public Carnivore {
public:
	Fox(string name, int health, int strength, int hungry, bool isNew) : Carnivore(name, health, strength, hungry, isNew) {}
	virtual ~Fox() {}
};
