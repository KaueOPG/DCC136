#ifndef PARAMS_H
#define PARAMS_H

#include <vector>

using namespace std;

struct Client
{
    int id;                 // ID
	double coordX;			// Coordinate X
	double coordY;			// Coordinate Y
	double demand;			// Demand
	bool visited;			// Visited
};

struct Depot
{
    int id;                 // Id
	double coordX;			// Coordinate X
	double coordY;			// Coordinate Y
    vector<Vehicle> vehicles; // Vector of Vehicles
};

struct Vehicle
{
    int id;                 // Id
	double maxDistance;	    // Maximum Distance per Vehicle
	double maxCapacity;		// Maximum Capacity  per Vehicle
    double distance;	    // Actual Distance
	double capacity;		// Actual Capacity
    vector<int> clientIds;  // Vector of Clients Visited
};

class Params 
{
    int numVehicles;        // Number of Vehicles per Depot
    int numClients;         // Number of Clients
    int numDepot;           // Number of Depots  
    vector<Client> clients; // Vector of Clients
    vector<Depot> depots;   // Vector of Depots
};
#endif