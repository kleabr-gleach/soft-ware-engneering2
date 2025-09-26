#include<iostream>
#include<string>
#include<memory>
using namespace std;
class proto {
public:
    virtual~proto() = default;
    virtual unique_ptr<proto>consat()const = 0;
    virtual void show()const = 0;
};
class name :public proto {
private:
    string value;
public:
    name(const string&v):value(v){}
    unique_ptr<proto>consat()const override {
        return  make_unique<name>(*this);
    }
    void show()const override {
        cout << "name" << value;
    }
};
class id :public proto {
private:
    int value;
public:
    id(int v) :value(v) {}
    unique_ptr<proto>consat()const override {
        return make_unique<id>(*this);
    }
    void show()const override {
        cout << "id" << value;
    }
};
int main() {
    unique_ptr<proto>p1= make_unique<name>("omar");
    auto c1 = p1->consat();
    c1->show();
    return 0;
}
