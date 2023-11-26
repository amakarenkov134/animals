#include <string>

using namespace std;

class Herbivore : public Animal {
protected:
	double luck;
public:
	Herbivore(string name, int health, double luck, bool isNew) : Animal(name, health, isNew), luck(luck) {}
	virtual ~Herbivore() {}
	virtual void Interact(Animal& other);
	double getLuck() { return luck; }
	void show() override;
};

void Herbivore::show() {
	cout << endl << name << endl << "Здоровье: " << health << endl << "Удачливость: " << luck << endl << "Может разможаться: " << isNew << endl;
}
