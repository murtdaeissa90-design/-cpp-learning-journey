#include <iostream>
#include <string>
using namespace std;

// المستوى الأول
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

// المستوى الثاني: يرث من Animal
class Mammal : public Animal {
public:
    Mammal(string animalColor, string animalType, int animalAge)
        : Animal(animalColor, animalType, animalAge) {}

    void printMammal() {
        printAnimal();
    }
};

// المستوى الثالث: يرث من Mammal (وبالتالي من Animal أيضاً)
class cat : public Mammal {
public:
    string breed;

public:
    cat(string animalColor, int animalAge, string catBreed)
        : Mammal(animalColor, "cat", animalAge) {
        breed = catBreed;
    }

    void meaw() {
        cout << "make sound:meaaaw meaaaw!" << endl;
    }
void grrrr() {
        cout << "make sound:grrrr" << endl;
        }
    void showInfo() {
        printMammal();
        cout << "Breed: " << breed << endl;
        meaw();
        grrrr();
        cout <<"............." << endl;
    }
};

int main() {
    cat cat1("Brown", 3, "Tigers");
    cat cat2("White", 2, "Tigers");

    cat1.showInfo();
    cat2.showInfo();

    return 0;
}