#ifndef INSTANCE_READER_H
#define INSTANCE_READER_H

#include <vector>
#include <string>

using namespace std;

struct Customer {
    int id;
    int x, y;
    int service_duration;
    int demand;
    int frequency;
    int num_combinations;
    vector<int> visit_combinations;
};

struct Depott {
    int id;
    int x, y;
    int max_distance;
    int max_load;
};

class InstanceReader {
private:
    int type;
    int num_vehicles;
    int num_customers;
    int num_depots;

    vector<Customer> customers;
    vector<Depott> depots;

public:
    InstanceReader();
    bool readFile(const string& filename);
    void displaySummary() const;

    int getNumCustomers() const { return num_customers; }
    int getNumDepots() const { return num_depots; }
    int getNumVehicles() const { return num_vehicles; }

    int getCustumer_id(int i) const {return customers[i].id;}
    int getCustumer_x(int i) const {return customers[i].x;}
    int getCustumer_y(int i) const {return customers[i].y;}
    int getCustumer_demand(int i) const {return customers[i].demand;}

    int getDepot_id(int i) const {return depots[i].id;}
    int getDepot_x(int i) const {return depots[i].x;}
    int getDepot_y(int i) const {return depots[i].y;}
    int getDepot_distance(int i) const {return depots[i].max_distance;}
    int getDepot_load(int i) const {return depots[i].max_load;}
};

#endif