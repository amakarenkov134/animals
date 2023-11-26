#include <string>

using namespace std;

class Animal {
protected:
	string name;
	int health;
	bool isNew;
public:
	Animal(string name, int health, bool isNew) : name(name), health(health), isNew(isNew) {}
	virtual ~Animal() {}
	virtual void Interact(Animal& other) = 0;
	string getName() { return name; }
	int getHealth() { return health; }
	void setHealth(int h) { health = h; }
	int getIsNew() { return isNew; }
	void setIsNew(int i) { isNew = i; }
	virtual void show() = 0;
};
