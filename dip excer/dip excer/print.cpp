#include "print.h"
#include<vector>
#include <iostream>
void printee:: printe(const saveee& pr) {
    const auto& m = pr.getprint();
    for (auto&ma : m) {
        cout <<endl<< "type " << ma.type
            <<endl;
        cout << "mail " <<ma.mail<<endl;
        cout << "from " <<ma.frm;
    }
}
