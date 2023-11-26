#include <iostream>

using namespace std;

class Moose : public Herbivore {
public:
	Moose(string name, int health, double luck, bool isNew) : Herbivore(name, health, luck, isNew) {}
	virtual ~Moose() {}
};
