#include <iostream>

using namespace std;

class Rabbit : public Herbivore {
public:
	Rabbit(string name, int health, double luck, bool isNew) : Herbivore(name, health, luck, isNew) {}
	virtual ~Rabbit() {}
};
