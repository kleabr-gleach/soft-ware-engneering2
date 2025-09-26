#include<iostream>
#include"createpost.h"
#include"hash.h"
#include"post.h"
#include"mention.h"
#include<string>
#include"savee.h"
#include"print.h"
using namespace std;
int main() {
    string word;
    cin>> word;
    creatpost* p = nullptr;
    if (!word.empty() && word[0] == '#') {
        p = new hashe();
    }
    else if(!word.empty() && word[0] == '@') {
        p=new mention;
    }
    else {
        p = new createpost;
    }
    post ps;
    ps.posta = p->createPost(word);
    savee s;
    s.saveee(ps);
    delete p;
    print printer;
    printer.printer(s);
    return 0;
}
