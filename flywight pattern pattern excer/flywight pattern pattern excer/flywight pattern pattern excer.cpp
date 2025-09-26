#include<iostream>
#include<map>
#include<memory>
#include<string>
using namespace std;
class treetype {
private:
    string name;
    string colour;
public:
    treetype(const string&n,const string&c):name(n),colour(c){}
    void draw(int x, int y) {
        cout << "Drawing tree '" << name << "' with color "
            << colour << " at (" << x << ", " << y << ")\n";
    }
};
class treefac {
private:
    map< string, shared_ptr<treetype>>type;
public:
    shared_ptr<treetype>gettree(const string& name, const string& colour) {
        string key = name + "-" + colour;
        if (type.find(key) == type.end()) {
            cout << "creating new tree" << key << "\n";
            type[key] = make_shared<treetype>(name, colour);
        }
        return type[key];
    }
};
class tree {
private:
    int x;
    int y;
    shared_ptr<treetype>type;
public:
    tree(int x,int y,shared_ptr<treetype>type):x(x),y(y),type(type){}
    void draw() {
        type->draw(x,y);
    }
};
int main() {
    treefac t;
    auto tr = t.gettree("oak", "green");
    auto tre = t.gettree("aa", "aaaa");
    tree t1(10, 20, tr);
    tree t2(20, 30, tre);
    t1.draw();
    t2.draw();


    return 0;
}
