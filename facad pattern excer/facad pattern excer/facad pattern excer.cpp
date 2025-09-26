#include<iostream>
using namespace std;
class inv {
public:
    bool checkitem(const string& item) {
        cout << "your order is avaliable" << item << endl;
        return true;
    }
};
class pay {
public:
    bool checkmoney(double amount) {
        cout << "amount is :" << amount << "sucsses in pay order" << endl;
        return true;
    }
};
class tr {
public:
    void ship(const string& item) {
        cout << "the item is shipping succses" << item << endl;
    }
};
class pushares {
private:
    inv in;
    pay p;
    tr t;
public:
    void pusher(const string& item, double amount) {
        cout << "starting pucher" << item << endl;
        if (in.checkitem(item)) {
            if (p.checkmoney(amount)) {
                t.ship(item);
                cout << "Purchase completed successfully!" << endl;
            }
            else {
                cout << "pay is failed";
            }
        }
        else {
            cout << "out of stock";
        }
    }

};
int main() {
    pushares* p = new pushares;
    p->pusher("laptop", 1000);
    delete p;
    return 0;
}
