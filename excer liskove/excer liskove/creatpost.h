#pragma once
#include"post.h"

using namespace std;
class creatpost
{
public:
    virtual ~creatpost() = default;
    virtual string createPost(const string& word) = 0;
};

