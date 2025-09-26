#include<iostream>
#include<string>
using namespace std;
class isms {
public:
    virtual~isms() = default;
    virtual void sendsms(const string& number, const string& message) = 0;

};
class serviecesms :public isms {
public:
    void sendsms(const string& number, const string& message)override {
        cout << "send message to:" << number << "the message is" << message;
    }
};
class dsms :public isms {
protected:
    isms*wr;
public:
    dsms(isms*m):wr(m){}
    virtual  void sendsms(const string& number, const string& message)override {
        wr->sendsms(number, message);
    }
};
class dvalid :public dsms {
public:
    dvalid(isms*m):dsms(m){}
    void sendsms(const string& number, const string& message)override {
        if (number.size() <= 10) {
            cout << "invalid number";
            return;
        }
        wr->sendsms(number, message);
    }
};
class dbalance :public dsms {
private:
    int balance;
public:
    dbalance(isms*m,int initbalance):dsms(m),balance(initbalance){}
    void sendsms(const string& number, const string& message)override {
        if (balance <= 0) { cout << "there is no balance" << endl;
        return;}
        balance--;
        wr->sendsms(number, message);
        cout << "your balance now is " << balance;
    }
   
 
};
int main() {
    serviecesms sms;
    dvalid v(&sms);
    dbalance b(&v, 10);
    b.sendsms("01225510421", "ktfomk");
    return 0;
}
