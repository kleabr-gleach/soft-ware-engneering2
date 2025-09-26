#pragma once
#include"creatpost.h"
using namespace std;
class mention:public creatpost
{
public:
    string createPost(const string& word)override;
};

