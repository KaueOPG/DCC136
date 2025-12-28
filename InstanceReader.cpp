#include "InstanceReader.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

InstanceReader::InstanceReader() : type(0), num_vehicles(0), num_customers(0), num_depots(0) {}

bool InstanceReader::readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    file >> type >> num_vehicles >> num_customers >> num_depots;

    struct DepotConstraint { int duration, load; };
    vector<DepotConstraint> constraints(num_depots);
    for (int i = 0; i < num_depots; ++i) {
        file >> constraints[i].duration >> constraints[i].load;
    }

    for (int i = 0; i < num_customers; ++i) {
        Customer c;
        file >> c.id >> c.x >> c.y >> c.service_duration >> c.demand 
             >> c.frequency >> c.num_combinations;
        
        for (int j = 0; j < c.num_combinations; ++j) {
            int combo;
            file >> combo;
            c.visit_combinations.push_back(combo);
        }
        customers.push_back(c);
    }

    for (int i = 0; i < num_depots; ++i) {
        Depott d;
        int dummy_duration, dummy_demand;
        file >> d.id >> d.x >> d.y >> dummy_duration >> dummy_demand;
        
        d.max_distance = constraints[i].duration;
        d.max_load = constraints[i].load;
        
        depots.push_back(d);

        string dummy;
        getline(file, dummy);
    }

    file.close();
    return true;
}

void InstanceReader::displaySummary() const {
    cout << "--- Instance Summary ---" << endl;
    cout << "Customers: " << num_customers << endl;
    cout << "Depots:    " << num_depots << endl;
    cout << "Vehicles per Depott: " << num_vehicles << endl;
    cout << "Depott Load Capacity: " << depots[0].max_load << endl;
    cout << "Depott Distance Capacity: " << depots[0].max_distance << endl;
}