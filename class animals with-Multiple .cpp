#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string color;
    string type;
    int age;

public:
    Animal(string animalColor, string animalType, int animalAge) {
        color = animalColor;
        type = animalType;
        age = animalAge;
    }

    void printAnimal() {
        cout << "Type: " << type << endl;
        cout << "Color: " << color << endl;
        cout << "Age: " << age << endl;
    }
};

class Habitat {
protected:
    string region;

public:
    Habitat(string animalRegion) {
        region = animalRegion;
    }

    void printHabitat() {
        cout << "Region: " << region << endl;
    }
};

// وراثة متعددة: من Animal و Habitat
class WildAnimal : public Animal, public Habitat {
public:
    WildAnimal(string animalColor, string animalType, int animalAge, string animalRegion)
        : Animal(animalColor, animalType, animalAge), Habitat(animalRegion) {}

    void showInfo() {
        printAnimal();
        printHabitat();
        cout << "---" << endl;
    }
};

int main() {
    WildAnimal animal1("Golden", "Lion", 5, "African Savanna");
    WildAnimal animal2("Gray", "Elephant", 12, "Central Africa");

    animal1.showInfo();
    animal2.showInfo();

    return 0;
}