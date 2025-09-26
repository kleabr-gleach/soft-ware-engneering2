#pragma once
#include"mail.h"
#include<string>
using namespace std;
class fmail{
    public:
        virtual~fmail() = default;
        virtual string frommail(mail& fm) = 0;
};

