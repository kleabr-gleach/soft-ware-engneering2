#pragma once
#include"post.h"
#include<vector>
class savee
{
private:
    vector<post> posts;
public:
    void saveee( post& p);
    const vector<post>& getPost()const { return posts; }
};

