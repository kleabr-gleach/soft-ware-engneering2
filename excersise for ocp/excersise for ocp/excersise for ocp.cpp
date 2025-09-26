#include<iostream>
#include"calcbs.h"
#include"saveee.h"
#include"data.h"
#include "manager.h"
#include "intern.h"
#include "print.h"
using namespace std;
int main() {
    manager it;
    intern it1;
    print prenter;
    saveee saver;
    dataa d{ "12345", 1900, 9, "omar", "manager" ,90};
    dataa d1{ "12345", 1900, 10, "omar", "inntern",90 };
    it1.calcs(d1);
    it.calcs(d);
    saver.savee(d1);
    saver.savee(d);
    prenter.printer(saver);


}
