#include <string>

using namespace std;

class Carnivore : public Animal {
protected:
	int strength;
	int hungry;
public:
	Carnivore(string name, int health, int strength, int hungry, bool isNew) : Animal(name, health, isNew), strength(strength), hungry(hungry) {}
	virtual ~Carnivore() {}
	void Interact(Animal& other);
	int getStrength() { return strength; }
	int getHungry() { return hungry; }
	void increaseHungry() { hungry++; }
	void decreaseHungry() { hungry--; }
	void show() override;
};

void Carnivore::show() {
	cout << endl << name << endl << "Здоровье: " << health << endl << "Сила: " << strength << endl << "Голод: " << hungry << endl << "Может разможаться: " << isNew << endl;
}
