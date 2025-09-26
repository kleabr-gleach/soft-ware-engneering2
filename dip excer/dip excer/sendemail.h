#pragma once
#include"mail.h"
#include"sendmail.h"
#include"stype.h"
using namespace std;
class sendemail :public sendmail
{
public:
    string sendtmail(const mail& m)override;
};

