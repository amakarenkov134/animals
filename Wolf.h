#include <iostream>

using namespace std;

class Wolf : public Carnivore {
public:
	Wolf(string name, int health, int strength, int hungry, bool isNew) : Carnivore(name, health, strength, hungry, isNew) {}
	virtual ~Wolf() {}
};
