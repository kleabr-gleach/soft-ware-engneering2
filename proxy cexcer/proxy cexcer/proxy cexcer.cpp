#include<iostream>
#include<memory>
using namespace std;
//subjector abstract
class rest {
public:
    virtual~rest() = default;
    virtual void order(const string& dish) = 0;

};
//real subject
class chef:public rest{
public:
    void order(const string& dish)override {
        cout << "making dish" << dish << endl;
    }
};
//proxy
class water :public rest {
private:
   unique_ptr<chef>che;
public:
    void order(const string& dish)override {
        cout << "Waiter: Taking order for " << dish << ".\n";
        if (!che) {
            cout << "water calling the chef\n";
            che = make_unique<chef>();
        }
        che->order(dish);
        cout << "Waiter: Serving " << dish << " to the client.\n";
    }
  
};
int main() {
    water w;
    cout << "my order is pizza\n";
    w.order("pizza");
    cout << "my order is pasta\n";
    w.order("pasta");
    return 0;
}
