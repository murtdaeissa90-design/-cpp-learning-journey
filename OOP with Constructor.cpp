#include<iostream>
#include <string>
using namespace std;

class car {
private :
    string brand;
    string model;
    int year;

    bool isExpired() {
        int current_year = 2026;
        return (current_year - year) > 15;
    }

public :
    // Constructor
    car(string brand, string model, int year) {
        setBrand(brand);
        setModel(model);
        setYear(year);
    }

    // Setters
    void setBrand(string b) { brand = b; }
    void setModel(string m) { model = m; }
    void setYear(int y)     { year = y; }

    // Getters
    string getBrand() { return brand; }
    string getModel() { return model; }
    int getYear() { return year; }

    void display () {
        cout << " brand:" << brand << endl;
        cout << "model: " << model << endl;
        cout << "year" << year << endl;
        cout << "Expired:" << (isExpired() ? "yes" : "no") << endl;
        cout << "..........." << endl;
    }
};

int main ()
{
    car car1("nissan", "man", 2008);
    car car2("sunny", "ali", 2005);
    car car3("man", "ali" , 2008);

    car1.display();
    car2.display();
    car3.display();
    return 0;
}