#include <iostream>
using namespace std;

class Motor {
public:
    Motor() {
        // генерира исклучок со веројатност од 50%
        if (rand() % 2 == 0) {
            throw "Motorot ima problemi!";
        }
        cout << "Motorot e ok." << endl;
    }
};

class Avtomobil {
public:
    Avtomobil() {
        try {
            motor = new Motor();
        } catch (const char* msg) {
            cout << "Se sluci greska pri inicijalizacija na motor: " << msg << endl;
            throw; // повторно фрла исклучок, за да се фати во конструкторот на Garaza
        }
        cout << "Avtomobilot e inicijaliziran." << endl;
    }

    ~Avtomobil() {
        delete motor;
        cout << "Avtomobilot e isklucen." << endl;
    }

private:
    Motor* motor;
};

class Garaza {
public:
    Garaza() {
        try {
            avtomobil = new Avtomobil();
        } catch (...) {
            cout << "Se sluci greska pri inicijalizacija na avtomobilot." << endl;
            throw;
        }
        cout << "Garazata e otvorena." << endl;
    }

    ~Garaza() {
        delete avtomobil;
        cout << "Garazata e zatvorena." << endl;
    }

private:
    Avtomobil* avtomobil;
};

int main() {
    try {
        Garaza garaza;
    } catch (...) {
        cout << "Se sluci greska." << endl;
    }
    return 0;
}
