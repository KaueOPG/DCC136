#include "InstanceReader.h"
#include <fstream>
#include <iostream>
#include <sstream>

InstanceReader::InstanceReader() : type(0), num_vehicles(0), num_customers(0), num_depots(0) {}

bool InstanceReader::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    // 1. Read Metadata
    file >> type >> num_vehicles >> num_customers >> num_depots;

    // 2. Read Depot Constraints (Duration and Load)
    // These are temporarily stored to be merged with depot coordinates later
    struct DepotConstraint { int duration, load; };
    std::vector<DepotConstraint> constraints(num_depots);
    for (int i = 0; i < num_depots; ++i) {
        file >> constraints[i].duration >> constraints[i].load;
    }

    // 3. Read Customer Data
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

    // 4. Read Depot Locations and merge with constraints
    for (int i = 0; i < num_depots; ++i) {
        Depot d;
        int dummy_duration, dummy_demand;
        file >> d.id >> d.x >> d.y >> dummy_duration >> dummy_demand;
        
        // Assign constraints read from the top of the file
        d.max_duration = constraints[i].duration;
        d.max_load = constraints[i].load;
        
        depots.push_back(d);

        // Clear remaining zeros in the depot line if they exist
        std::string dummy;
        std::getline(file, dummy);
    }

    file.close();
    return true;
}

void InstanceReader::displaySummary() const {
    std::cout << "--- Instance Summary ---" << std::endl;
    std::cout << "Customers: " << num_customers << std::endl;
    std::cout << "Depots:    " << num_depots << std::endl;
    std::cout << "Vehicles per Depot: " << num_vehicles << std::endl;
    
    if (!depots.empty()) {
        std::cout << "First Depot Load Capacity: " << depots[0].max_load << std::endl;
    }
}