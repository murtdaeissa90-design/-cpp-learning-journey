#include <iostream>
#include <string>
using namespace std;

class animals {
public:
    string name;
    string type;
    int age;
    string color;

    // دالة بناء بها براميترز
    animals(string n, string t, int a, string c) {
        name = n;
        type = t;
        age = a;
        color = c;
        cout << "Constructor called for " << name << endl;
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
    animals a1("Leo", "Lion", 5, "Golden");
    animals a2("Bella", "Cat", 2, "White");

    a1.display();
    a2.display();

    return 0;
}