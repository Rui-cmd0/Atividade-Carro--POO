#include <iostream>
#include <sstream>  

using namespace std;

class Car {
public:
    int Pass; 
    int passMax = 2;
    int Gas; 
    int gasMax = 100;
    int Km; 
    
    string toString() {
        stringstream buffer;
        buffer << "pass: " << Pass << ", ";
        buffer << "gas: " << Gas << ", ";
        buffer << "km: " << Km << endl;
        return buffer.str();
    }
    
    void enter() {
        if (Pass < passMax)
            Pass++;
        else
            cout << "fail: limite de pessoas atingido" << endl;
    }
    
    void leave() {
        if (Pass > 0)
            Pass--;
        else
            cout << "fail: nao ha ninguem no carro" << endl;
    }
    
    void fuel(int gas) {
        Gas = gas;
        if (Gas > gasMax)
            Gas = gasMax;
    }
    
    void drive (int km) {
        if (Pass == 0) {
            cout << "fail: nao ha ninguem no carro" << endl;
            return;
        }
        if (Gas == 0) {
            cout << "fail: tanque vazio" << endl;
            return;
        }
        Gas = Gas - km;
        Km += km; 
        if (Gas < 0) {         
            Km += Gas;
            cout << "fail: tanque vazio apos andar " << Gas + km << " km" << endl;
            Gas = 0;
        }
    }

    Car(int gas, int pass, int km) {
        Gas = gas;
        Pass = pass;
        Km = km;
    }
};

int main(){
    Car car = Car(0, 0, 0);
    car.toString();

    while(true){
        string action;
        int amount;
        
        getline(cin, action);
        cout << "$" << action << endl;
        stringstream ss(action);
        ss >> action >> amount;
        
        if (action == "fuel")
            car.fuel(amount);
        if (action == "drive")
            car.drive(amount);
        if (action == "show")
            cout << car.toString();
        if (action == "enter")
            car.enter();
        if (action == "leave")
            car.leave();
        if (action == "end")
            return 0;
    }
}
