#include "print.h"
#include <iostream>
void print::printer(const savee& p) {
    const auto& pos = p.getPost();
    for (auto& p : pos) {
        cout << "post" << p.posta;
    }
}   
