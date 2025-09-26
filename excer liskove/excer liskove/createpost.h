#pragma once
#include"creatpost.h"
#include"post.h"
using namespace std;
class createpost:public creatpost
{
public:
    string createPost(const string& word)override;
};

