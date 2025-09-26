#pragma once
#include"fmail.h"
class fhotmail:public fmail
{
public:
    string frommail( mail& fm)override;
};

