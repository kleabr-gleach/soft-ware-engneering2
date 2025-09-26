#pragma once
#include "data.h"
#include <vector>
#include <string>
using namespace std;
class calcbs {
public:
    virtual int calcs(dataa& d) = 0;
    virtual ~calcbs() = default;
  
};
