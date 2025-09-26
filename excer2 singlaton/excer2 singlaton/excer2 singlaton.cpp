#include<iostream>
#include<mutex>
#define null NULL
using namespace std;
class counter {
private:
    int count = 0;
    counter() {};
    counter(const counter&) = delete;
    counter& operator=(const counter&) = delete;
    static mutex mti;
    static counter* co;
    void addone();
public:
    static counter* getco() {
        if (co == null) {
            lock_guard<mutex>lock(mti);
            if (co == nullptr) {
                co = new counter;
            }
        }
        return co;
    }
    void increament() { addone(); }
    void show();
};
counter* counter::co = nullptr;
mutex counter::mti;
void counter::addone() {
    count++;
}
void counter::show() {
    cout << count;
}
int main() {
    counter* co = counter::getco();
    co->increament();
    co->show();
    return 0;
}
