#include <iostream>
#include <clocale>

using namespace std;

class IDrivable {
public:
    virtual ~IDrivable() = default;
    virtual void StartEngine() = 0;
    virtual void StopEngine() = 0;
    virtual void Drive() = 0;
};

class Car : public IDrivable {
public:
    void StartEngine() override {
        cout << "Двигун автомобіля запущено." << endl;
    }

    void StopEngine() override {
        cout << "Двигун автомобіля зупинено." << endl;
    }

    void Drive() override {
        cout << "Автомобіль їде по дорозі." << endl;
    }
};

class Motorcycle : public IDrivable {
public:
    void StartEngine() override {
        cout << "Двигун мотоцикла завевся з гучним ревом!" << endl;
    }

    void StopEngine() override {
        cout << "Двигун мотоцикла вимкнено." << endl;
    }

    void Drive() override {
        cout << "Мотоцикл швидко мчить по трасі." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Car myCar;
    Motorcycle myBike;

    IDrivable* vehicles[] = { &myCar, &myBike };

    for (int i = 0; i < 2; ++i) {
        vehicles[i]->StartEngine();
        vehicles[i]->Drive();
        vehicles[i]->StopEngine();
        cout << endl;
    }

    return 0;
}