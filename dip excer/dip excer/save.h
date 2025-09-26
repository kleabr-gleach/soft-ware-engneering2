#pragma once
#include<vector>
#include"type.h"
#include"mail.h"
#include"fmail.h"
class saveee
{
private:
    vector<mail>s;
public:
    void savee( mail& sa);
    const vector<mail>& getprint()const { return s; }
};

