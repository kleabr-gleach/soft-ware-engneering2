#include<iostream>
#include<string>
#include<memory>
using namespace std;
class proto {
public:
    virtual~proto() = default;
    virtual unique_ptr<proto>clone() const  = 0;
    virtual void print()const = 0;
};
class name :public proto {
    string value;
public:
    name(const string& v): value(v){}
    unique_ptr<proto>clone()const  override {
        return make_unique<name>(*this);
    }
    void print() const override {
        cout << "name:" << value;
   }
};
class id :public proto {
    int  value;
public:
    id(int v):value(v){}
    unique_ptr<proto> clone()const override {
        return make_unique<id>(*this);
    }
    void print() const override {
        cout << "id" << value;
    }

};
class address :public proto {
private:
    string value;
public:
    address(const string&v) :value(v){}
    unique_ptr<proto>clone()const override{
        return make_unique<address>(*this);
    }
    void print()const override {
        cout << "address" << value;
    }
};
int main() {
    unique_ptr<proto>p1 = make_unique<name>("omar");
    unique_ptr<proto>p2 = make_unique<id>(1234);
    unique_ptr<proto>p3 = make_unique<address>("sidigaber");
    auto c1 = p1->clone();
    auto c2 = p2->clone();
    auto c3 = p3->clone();
    c1->print();
    c2->print();
    c3->print();
    return 0;
}
