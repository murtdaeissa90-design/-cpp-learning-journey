#include <iostream>
#include <string>
using namespace std;

class car {
private:
    string brand;
    string model;
    int year;

    bool isExpired() {
        int current_year = 2026;
        return (current_year - year) > 15;
    }

public:
    // Constructor
    car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    void display() {
        cout << "brand: " << brand << endl;
        cout << "model: " << model << endl;
        cout << "year: " << year << endl;
        cout << "Expired: " << (isExpired() ? "yes" : "no") << endl;
        cout << "..........." << endl;
    }
};

int main() {
    car car1("nissan", "man", 2008);
    car car2("sunny", "ali", 2005);
    car car3("man", "ali", 2008);

    car1.display();
    car2.display();
    car3.display();
    return 0;
}