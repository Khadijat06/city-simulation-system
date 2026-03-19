#include <iostream>
#include <fstream>
using namespace std;

class Region {
public:
    string name;
    int population;
    int resources;

    Region(string n, int p, int r) {
        name = n;
        population = p;
        resources = r;
    }

    void simulate() {
        population += 50;
        resources -= 30;
    }

    void display() {
        cout << name << " | Population: " << population 
             << " | Resources: " << resources << endl;
    }
};

int main() {
    ifstream file("config.txt");

    if (!file) {
        cout << "Error opening config file.\n";
        return 1;
    }

    int r_pop, r_res, c_pop, c_res, i_pop, i_res;

    file >> r_pop >> r_res;
    file >> c_pop >> c_res;
    file >> i_pop >> i_res;

    Region residential("Residential", r_pop, r_res);
    Region commercial("Commercial", c_pop, c_res);
    Region industrial("Industrial", i_pop, i_res);

    cout << "City Simulation Start\n\n";

    for (int day = 1; day <= 5; day++) {
        cout << "Day " << day << ":\n";

        residential.simulate();
        commercial.simulate();
        industrial.simulate();

        residential.display();
        commercial.display();
        industrial.display();

        cout << "----------------------\n";
    }

    return 0;
}