#include <iostream>
#include <string>

using namespace std;

class Bike {
protected:
    string* name;
    int* speeds;
    double* wheel;
    bool* brake;

public:
    Bike() {
        cout << "[Bike] конструктор без параметров" << endl;
        name = new string("NoName");
        speeds = new int(1);
        wheel = new double(26.0);
        brake = new bool(false);
    }

    Bike(string n, int s, double w, bool b) {
        cout << "[Bike] конструктор с параметрами" << endl;
        name = new string(n);
        speeds = new int(s);
        wheel = new double(w);
        brake = new bool(b);
    }

    ~Bike() {
        cout << "[Bike] деструктор" << endl;
        delete name;
        delete speeds;
        delete wheel;
        delete brake;
    }

    string getName() { return *name; }
    int getSpeeds() { return *speeds; }
    double getWheel() { return *wheel; }
    bool getBrake() { return *brake; }

    void ride() {
        cout << "Едем на " << *name << ", скоростей: " << *speeds << endl;
    }
};

class MountainBike : public Bike {
private:
    bool* suspension;

public:
    MountainBike() : Bike() {
        cout << "[MountainBike] конструктор" << endl;
        suspension = new bool(false);
    }

    MountainBike(string n, int s, double w, bool b, bool susp)
        : Bike(n, s, w, b) {
        cout << "[MountainBike] конструктор с параметрами" << endl;
        suspension = new bool(susp);
    }

    ~MountainBike() {
        cout << "[MountainBike] деструктор" << endl;
        delete suspension;
    }

    bool getSuspension() { return *suspension; }

    void ride() {
        cout << "Горный велосипед " << *name
             << ", амортизация: " << (*suspension ? "есть" : "нет") << endl;
    }
};

class CityBike : public Bike {
private:
    bool* basket;

public:
    CityBike() : Bike() {
        cout << "[CityBike] конструктор" << endl;
        basket = new bool(false);
    }

    CityBike(string n, int s, double w, bool b, bool bas)
        : Bike(n, s, w, b) {
        cout << "[CityBike] конструктор с параметрами" << endl;
        basket = new bool(bas);
    }

    ~CityBike() {
        cout << "[CityBike] деструктор" << endl;
        delete basket;
    }

    bool getBasket() { return *basket; }

    void ride() {
        cout << "Городской велосипед " << *name
             << ", корзина: " << (*basket ? "есть" : "нет") << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Обычный велосипед:" << endl;
    Bike* b = new Bike("Forward", 18, 27.5, false);
    b->ride();
    delete b;

    cout << endl;
    cout << "Горный велосипед:" << endl;
    MountainBike* m = new MountainBike("Trek", 21, 29.0, false, true);
    m->ride();
    delete m;

    cout << endl;
    cout << "Городской велосипед:" << endl;
    CityBike* c = new CityBike("Aist", 7, 28.0, false, true);
    c->ride();
    delete c;

    return 0;
}