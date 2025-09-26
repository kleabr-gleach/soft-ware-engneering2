#include<iostream>
#include<memory>
using namespace std;
class bankaccount {
private:
    string name;
    double balance;
public:
    bankaccount(const string&n,double b):name(n), balance(b) {}
    const string& getname() { return name; }
    double getbalance() { return balance; }
    void depos(double amount) { balance += amount; }
    bool withdraw(double amount) {
        if (balance < amount) {
            cout << name << "no more money";
            return false;
        }
        else {
            balance -= amount;
            return true;
        }
    }


};
class bank {
public:
    virtual~bank() = default;
    virtual void excer(bankaccount&acount, double amount) = 0;

};
class pay :public bank {
public:
    void excer(bankaccount&acount,double amount)override {
        acount.withdraw(amount);
        cout << acount.getname() << "paid" <<amount<<"balance now"<<acount.getbalance()<< endl;
    }   
};
class draw :public bank {
public:
    void excer(bankaccount&acount,double amount)override {
        if(acount.withdraw(amount)){
            cout << acount.getname() << "withdraw" << amount << "balance" << acount.getbalance() << endl;

        }
      
    }
};
enum class opreationtype{PAY,WITHDRAW};
class opfactory {
public:
    static unique_ptr<bank>caretop(opreationtype type) {
        switch (type) {
        case opreationtype::PAY:
            return make_unique<pay>();
        case opreationtype::WITHDRAW:
            return make_unique<draw>();
        default:
            return nullptr;
        }
        
    }


};
int main() {
    bankaccount user1("Alice", 500);
    bankaccount user2("Bob", 300);
    auto payop = opfactory::caretop(opreationtype::PAY);
    auto withop = opfactory::caretop(opreationtype::WITHDRAW);
    payop->excer(user1,175);
    withop->excer(user2,100);
    return 0;

}
