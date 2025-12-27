#include <iostream>
#include "InstanceReader.h"

using namespace std;

int main() {
    cout<< "passou" << endl;
    InstanceReader reader;

    if (reader.readFile("cordeau/p01.txt")) {
        reader.displaySummary();

        // Example: Print coordinates of the first customer
        const auto& customers = reader.getCustomers();
        if (!customers.empty()) {
            cout << "Customer 1 is at (" << customers[0].x 
                      << ", " << customers[0].y << ")" << endl;
        }
    } else {
        cerr << "Failed to open file." << endl;
    }
        cout<< "passou" << endl;
    return 0;
}