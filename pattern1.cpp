#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car {
public:
    string category;
    string color;
    int seats;
    int volume;
    Car(string category, string color, int seats, int volume) : 
        category(category), color(color), seats(seats), volume(volume) {};
};

class CarAdapter {
    Car* car;
public:
    CarAdapter(string dataCar){
        string tempstr;
        string str[4];
        for (int i = 0; i < dataCar.size(); i++) {
            while (dataCar[i] != ';') {
                tempstr += dataCar[i];
            }
            str[i] = tempstr;
        }
    }
    Car* getCar() { return car; }
};

class Parking {
public:
    vector<Car> cars;

    void addCar(Car car) {
        cars.push_back(car);
    }

    void show() {
        for (int i = 0; i < cars.size(); i++) cout << cars[i];
    }
};
int main()
{
    
}