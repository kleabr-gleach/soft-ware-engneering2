#pragma once
#include"fmail.h"
using namespace std;
class femail:public fmail
{
public:
    string frommail( mail& fm)override;
};

