#include<iostream>
#include <string>
#include <vector>
using namespace std;

// ---------- دوال التصحيح التلقائي للاسم ----------

// 1) تشيل الأرقام والرموز وتحذف المسافات الزايدة
string removeDigits(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isalpha(c)) {
            result += c;
        } else if (c == ' ' && result != "" && result[result.length() - 1] != ' ') {
            result += c;
        }
    }
    if (result != "" && result[result.length() - 1] == ' ')
        result.erase(result.length() - 1);
    return result;
}

// 2) تخلي أول حرف كبير والباقي صغير
string fixCase(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (i == 0 || s[i - 1] == ' ')
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    }
    return s;
}

// 3) تحسب كم حرف مختلف بين كلمتين (Levenshtein distance)
int wordDistance(string a, string b) {
    int n = a.length(), m = b.length();
    int d[30][30];
    for (int i = 0; i <= n; i++) d[i][0] = i;
    for (int j = 0; j <= m; j++) d[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (tolower(a[i - 1]) == tolower(b[j - 1])) ? 0 : 1;
            int best = d[i - 1][j] + 1;
            if (d[i][j - 1] + 1 < best) best = d[i][j - 1] + 1;
            if (d[i - 1][j - 1] + cost < best) best = d[i - 1][j - 1] + cost;
            d[i][j] = best;
        }
    }
    return d[n][m];
}

// 4) الدالة الرئيسية: تنظف الاسم وتقارنه بأسماء الشركات المعروفة
string autoCorrectName(string name) {
    string known[] = {"Toyota", "Nissan", "Hyundai", "Honda", "Kia", "Ford", "Mazda", "Suzuki"};
    int count = 8;

    string cleaned = fixCase(removeDigits(name));

    int bestIndex = -1;
    int bestDist = 100;
    for (int i = 0; i < count; i++) {
        int dist = wordDistance(cleaned, known[i]);
        if (dist < bestDist) {
            bestDist = dist;
            bestIndex = i;
        }
    }

    // لو الفرق حرفين أو أقل نعتبرها غلطة كتابة ونصححها
    if (bestDist <= 2) return known[bestIndex];
    return cleaned;   // اسم جديد غير معروف، نرجعه منظف فقط
}

// ---------- الكلاس ----------

class car {
public :
    string brand;
    string model;
    int year;
    int salesCount;
    bool discontinued;   // هل توقف إنتاج الموديل

    // Constructor
    car(string b, string m, int y, bool disc = false) {
        brand = autoCorrectName(b);   // تصحيح تلقائي للاسم
        model = fixCase(removeDigits(m));
        year = y;
        salesCount = 0;
        discontinued = disc;
    }

    bool isDiscontinued() {
        return discontinued;
    }

    // Behavior function - تحاكي عملية بيع سيارة
    void sellOne() {
        if (isDiscontinued()) {
            cout << brand << " " << model << " is discontinued, cannot sell!" << endl;
            return;
        }
        salesCount++;
        cout << brand << " " << model << " sold! Total sales:" << salesCount << endl;
    }

    void display () {
        cout << " brand:" << brand << endl;
        cout << "model: " << model << endl;
        cout << "year" << year << endl;
        cout << "sales:" << salesCount << endl;
        cout << "Discontinued:" << (isDiscontinued() ? "yes" : "no") << endl;
        cout << "..........." << endl;
    }
};

// دالة تحسب وترجع السيارة الأكثر مبيعًا
car findBestSeller(vector<car>& cars) {
    int bestIndex = 0;
    for (int i = 1; i < cars.size(); i++) {
        if (cars[i].salesCount > cars[bestIndex].salesCount) {
            bestIndex = i;
        }
    }
    return cars[bestIndex];
}

// ---------- القائمة ----------

void showMenu() {
    cout << "\n====== Car Company Menu ======" << endl;
    cout << "1. Add car" << endl;
    cout << "2. Sell car" << endl;
    cout << "3. Show all cars" << endl;
    cout << "4. Show best seller" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose: ";
}

// عرض أسماء السيارات مرقمة (تستخدم عند البيع)
void showCarList(vector<car>& cars) {
    for (int i = 0; i < cars.size(); i++) {
        cout << i + 1 << ". " << cars[i].brand << " " << cars[i].model << endl;
    }
}

int main ()
{
    vector<car> cars;
    int choice = 0;

    while (choice != 5) {
        showMenu();
        cin >> choice;

        // لو كتب المستخدم حرف بدل رقم
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a number from 1 to 5" << endl;
            choice = 0;
            continue;
        }
        cin.ignore(1000, '\n');   // نتخلص من Enter المتبقي قبل getline

        if (choice == 1) {
            string name, mdl, disc;
            int year;

            cout << "Enter brand: ";
            getline(cin, name);
            cout << "Enter model: ";
            getline(cin, mdl);
            cout << "Enter year: ";
            cin >> year;
            cin.ignore(1000, '\n');
            cout << "Is it discontinued? (y/n): ";
            getline(cin, disc);

            car newCar(name, mdl, year, (disc == "y" || disc == "Y"));
            cars.push_back(newCar);
            cout << "Car added as: " << newCar.brand << " " << newCar.model << endl;
        }
        else if (choice == 2) {
            if (cars.empty()) {
                cout << "No cars yet!" << endl;
            } else {
                showCarList(cars);
                cout << "Choose car number: ";
                int num;
                cin >> num;
                if (num >= 1 && num <= cars.size())
                    cars[num - 1].sellOne();
                else
                    cout << "Invalid number!" << endl;
            }
        }
        else if (choice == 3) {
            if (cars.empty()) {
                cout << "No cars yet!" << endl;
            } else {
                for (int i = 0; i < cars.size(); i++)
                    cars[i].display();
            }
        }
        else if (choice == 4) {
            if (cars.empty()) {
                cout << "No cars yet!" << endl;
            } else {
                car best = findBestSeller(cars);
                cout << "Best seller:" << best.brand << " " << best.model
                     << " with " << best.salesCount << " sales" << endl;
            }
        }
        else if (choice == 5) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice, try again" << endl;
        }
    }

    return 0;
}