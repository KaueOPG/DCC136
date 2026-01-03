#include <iostream>
#include "InstanceReader.h"
#include "Params.h"

using namespace std;

int main() {
    InstanceReader reader;

    if (reader.readFile("cordeau/p01.txt")) {
        Params params(reader);
        params.displaySummary();
        } else {
        cout << "Failed to open file." << endl;
    }
    return 0;
}