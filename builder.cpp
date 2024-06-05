

#include <iostream>
#include <map>
using namespace std;

class Car {
	int wheels;
	int seats;
	string color;
	string engine;
	bool gps;

	void info() {
		cout 
			<< "Wheels: " << wheels << endl 
			<< "Seats: " << seats << endl 
			<< "Color: " << color << endl 
			<< "Engine: " << engine << endl 
			<< "GPS: " << gps << endl;
	}
};

class CarBuilder {
private:
	Car* result;
public:
	CarBuilder() {}
	~CarBuilder() { delete result }
	CarBuilder& reset() { this->result = new Car(); return *this }
	CarBuilder& setWheels(int count) { this->result->wheels = count; return *this }
	CarBuilder& setSeets(int count) { this->result->seets = count; return *this }
	CarBuilder& setColor(int color) { this->result->color = color; return *this }
	CarBuilder& setEngine(int engine) { this->result->engine = engine; return *this }
	CarBuilder& setGPS(int gps) { this->result->gps = gps; return *this }
	Car* getResult() { return this->result }
};

class Director {
public:
	Car* createDefaultCar(CarBuilder* builder) {
		builder->reset();
		builder->setWheels(4);
		builder->setSeets(4);
		builder->setColor("white");
		builder->setEngine("common engine");
		builder->setGPS(true);
		builder->getResult();
	}
	Car* createMuscleCar(CarBuilder* builder) {
		builder->reset();
		builder->setWheels(4);
		builder->setSeets(4);
		builder->setColor("red");
		builder->setEngine("uncommon engine");
		builder->setGPS(false);
		builder->getResult();
	}
	Car* createSportCar(CarBuilder* builder) {
		builder->reset();
		builder->setWheels(4);
		builder->setSeets(2);
		builder->setColor("black");
		builder->setEngine("rare engine");
		builder->setGPS(true);
		builder->getResult();
	}
};


int main()
{

}

