#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Vehicle {
private:
    int vehicleId;
    string licensePlate;
    string vehicleType;
public:
    virtual ~Vehicle() = default;
    Vehicle(string vehicleType, string licensePlate, int vehicleId) : vehicleType(vehicleType), licensePlate(licensePlate), vehicleId(vehicleId){}
    int getVehicleId() { return vehicleId; }
    string getLicensePlate() { return licensePlate; }
    string getVehicleType() { return vehicleType; }
};

class LightVehicle : public Vehicle {};
class Truck : public Vehicle {};
class Motocycle : public Vehicle {};

class ParkingSpot {
private:
    int spotId;
    bool isOccupied;
    string spotType;
public:
    ParkingSpot(int spotId, string spotType) : spotId(spotId), spotType(spotType), isOccupied(false) {}
    void setIsOccupied (bool flag) { isOccupied = flag; }
    int getSpotId() { return spotId; }
    bool getIsOccupied() { return isOccupied; }
    string getSpotType() { return spotType; }
};

class ParkingTicket {
private:
    int ticketId;
    int Vehicle::vehicleId;
    int ParkingSpot::spotId;
    time_t entryTime;
    time_t exitTime;
    double duration = difftime(exitTime, entryTime);
public:
    ParkingTicket(int vehicleId, int spotId) {
        entryTime = time(nullptr);
        exitTime = time(nullptr);
    }
    time_t setEntryTime(time_t time) { return entryTime = time; }
    time_t setExitTime(time_t time) { return exitTime = time; }
    double getDurationTime() { return duration; }
};

class ParkingLot {
public:
    vector<ParkingSpot*> spots;
    vector<Vehicle*> vehicles;
    vector<ParkingTicket*> tickets;
    ParkingSpot* findFreePlace() {
        for (auto iterator : spots) {
            if (spots.empty()) return iterator;
        }
    }
    void addVehicle(Vehicle* vehicle) { 
        ParkingSpot* spot = findFreePlace();
        spot->setIsOccupied(true);
        vehicles.push_back(vehicle); 
        ParkingTicket ticket(vehicle->getVehicleId(), spot->getSpotId());
    }
    void deleteVehicle(Vehicle* vehicle) { 
        for (auto iterator : vehicles) if (iterator == vehicle) {
            delete vehicle;
            return;
        }
    }
};

int main()
{
    
}