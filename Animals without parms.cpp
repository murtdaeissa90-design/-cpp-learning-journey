#include <iostream>
#include <string>
using namespace std;

class animals {
public:
    string name;
    string type;
    int age;
    string color;

    // دالة بناء افتراضية
    animals() {
        name = "Unknown";
        type = "Unknown";
        age = 0;
        color = "Unknown";
        cout << "Constructor called" << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Age: " << age << endl;
        cout << "Color: " << color << endl;
        cout << "-------------------" << endl;
    }
};

int main() {
    animals a1;
    animals a2;

    // تعديل خصائص الكائن الأول
    a1.name = "Leo";
    a1.type = "Lion";
    a1.age = 5;
    a1.color = "Golden";

    // تعديل خصائص الكائن الثاني
    a2.name = "Bella";
    a2.type = "Cat";
    a2.age = 2;
    a2.color = "White";

    a1.display();
    a2.display();

    return 0;
}