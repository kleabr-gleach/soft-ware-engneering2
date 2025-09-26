#include<iostream>
#include"mail.h"
#include"sendemail.h"
#include"sendhotmail.h"
#include"sendmail.h"
#include"shtype.h"
#include"stype.h"
#include"type.h"
#include "save.h"
#include "print.h"
#include"femail.h"
#include"fhotmail.h"
int main() {
    string tmail;
    cin >> tmail;
    string maile;
    string ffmail;
    mail m;
    m.type = tmail;
    type* t = nullptr;
    sendmail* s = nullptr;
    fmail* f = nullptr;
    if (tmail == "email") {
        t = new stype();
        s = new sendemail();
        f = new femail();
        cout << "from";
        cin >> ffmail;
        m.frm = ffmail;
        cout << "enter:" << t->typemail(m);
        cin >> maile;
        m.mail = maile;
    }
    else {
        t = new shtype();
        s = new hotmail();
        f = new fhotmail();
        cout << "from";
        cin >> ffmail;
        m.frm = ffmail;
        cout << "enter:" << t->typemail(m);
        cin >> maile;
        m.mail = maile;
    }
    saveee sav;
    mail me;
    me.type= t->typemail(m);
    me.mail = s->sendtmail(m);
    me.frm = f->frommail(m);
    sav.savee(me);

    cout << s->sendtmail(m);
    printee printer;
    printer.printe(sav);
    delete s;
    delete t;
    delete f;
    return 0;

}
