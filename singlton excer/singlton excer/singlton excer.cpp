
#include <iostream>
#include<thread>
#include<mutex>
#define null NULL
using namespace std;
class counter {
    int count = 0;
    counter() {};
    counter(const counter&) = delete;
    counter& operator = (const counter&) = delete;
    static counter* inst;
    static mutex mut;

    void addone();
public:
    static counter* getinst(){
        if (inst == null) {
            lock_guard<mutex>lock(mut);
            if (inst == nullptr) {
                inst = new counter();
            }
}
    return inst;
    }
  
    void incrment(){ addone(); }
    void show() { cout << "Count: "<< count << endl; }
};
counter* counter::inst = nullptr;
mutex counter::mut;

void counter::addone() {
    count++;
}
int main()
{
    counter* c1 = counter::getinst();
    c1->incrment();
    c1->show();
    return 0;
}

