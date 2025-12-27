#ifndef INSTANCE_READER_H
#define INSTANCE_READER_H

#include <vector>
#include <string>

struct Customer {
    int id;
    int x, y;
    int service_duration;
    int demand;
    int frequency;
    int num_combinations;
    std::vector<int> visit_combinations;
};

struct Depot {
    int id;
    int x, y;
    int max_duration;
    int max_load;
};

class InstanceReader {
private:
    int type;
    int num_vehicles;
    int num_customers;
    int num_depots;

    std::vector<Customer> customers;
    std::vector<Depot> depots;

public:
    InstanceReader();
    bool readFile(const std::string& filename);
    void displaySummary() const;

    // Getters
    int getNumCustomers() const { return num_customers; }
    int getNumDepots() const { return num_depots; }
    const std::vector<Customer>& getCustomers() const { return customers; }
    const std::vector<Depot>& getDepots() const { return depots; }
};

#endif