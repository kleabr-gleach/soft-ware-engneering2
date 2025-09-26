#include<iostream>
#include<string>
using namespace std;
class isms {
public:
    virtual~isms() = default;
    virtual void sendsms(const string& number, const string& message) = 0;
};
class Balance {
private:
    int balance;
public:
    Balance(int b):balance(b){}
    bool hasbalance() const{ return balance > 0; }
    void usebalannce() { if (balance > 0)balance--; }
    int getbalance() const{ return balance; }

};
class valid {
public:
    bool isvalid(const string& number) {
        return number.size() >= 10;
    }
};
//real subj
class SMSService : public isms {
public:
    void sendsms(const string& number, const string& message) override {
        cout << " SMS sent to " << number << ": " << message << endl;
    }
};
//proxy
class proxy :public isms {
private:
    Balance balance;
    SMSService sm;
    valid vald;
    int limit;

public:
    proxy(int initblance,int initlimit) :balance(initblance),limit(initlimit){}
    void sendsms(const string& number, const string& message) override {
        if (limit <= 0) {
            cout << "your get limit";
            return;
        }
        if (!vald.isvalid(number)) {
            cout << "not valid";
            return;
        }
        if (!balance.hasbalance()) {
            cout << "not balance";
            return;
        }
        sm.sendsms(number, message);
        limit--;
        balance.usebalannce();
        cout << " Remaining balance: " << balance.getbalance() << endl;
        cout << "limit" << limit << endl;
    }
};
int main() {
    proxy proxyy(2,1);
    proxyy.sendsms("01225510421", "ko");
    proxyy.sendsms("01225510421", "k");
    return 0;
}
