#include "print.h"


void print::printer(const saveee& p) {
    const auto& da = p.getData(); 
    for (const auto& d : da) {
        cout << "ID: " << d.id
            << ", Name: " << d.name
            << ", Type: " << d.type
            << ", Hours: " << d.hour
            << ", Hour Rate: " << d.shour
            << ", Salary: " << d.bs << endl;
    }
}
