#include "Params.h"
#include "InstanceReader.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Params::Params(const InstanceReader& reader) {

    numVehicles = reader.getNumVehicles();
    numClients = reader.getNumCustomers();         
    numDepot = reader.getNumDepots();    
    
    for(int i = 0; i < numClients; i++){
        Client c;
        c.id = reader.getCustumer_id(i);
        c.coordX = reader.getCustumer_x(i);
        c.coordY = reader.getCustumer_y(i);
        c.demand = reader.getCustumer_demand(i);
        c.visited = false;
        this->clients.push_back(c);
    }

    for(int i = 0; i < numDepot; i++){
        Depot d;
        d.id = reader.getDepot_id(i);
        d.coordX = reader.getDepot_x(i);
        d.coordY = reader.getDepot_y(i);

        for(int j = 0; j < numVehicles; j++){
            Vehicle v;
            v.id = j;
            v.maxDistance = reader.getDepot_distance(i);
            v.maxCapacity = reader.getDepot_load(i);
            v.distance = 0;
            v.capacity = 0;
            d.vehicles.push_back(v);
        }
        this->depots.push_back(d);
    }
}

void Params::displaySummary() const{
    cout << "--- Instance Summary ---" << endl;
    cout << "Number of Vehicles: " << numVehicles << endl;
    cout << "Number of Clients:    " << numClients << endl;
    cout << "Number of Depots:   " << numDepot << endl;

    cout << "Clients:" << endl;
    cout << "ID\tX\tY\tDemand\tVisited" << endl;
    for (const auto& c : clients) {
        cout << c.id << "\t" 
             << c.coordX << "\t" 
             << c.coordY << "\t" 
             << c.demand << "\t" 
             << (c.visited ? "True" : "False") << endl;
    }

    cout << "\nDepots and Vehicles:" << endl;
    for (const auto& d : depots) {
        cout << "Depot ID: " << d.id << " | (x,y): (" << d.coordX << ", " << d.coordY << ")" << endl;
        cout << "  Vehicles per Depot:" << endl;
        cout << "  ID\tCap. Max\tDist. Max" << endl;
        
        for (const auto& v : d.vehicles) {
            cout << "  " << v.id << "\t" 
                 << v.maxCapacity << "\t\t" 
                 << v.maxDistance << endl;
        }
    }
}