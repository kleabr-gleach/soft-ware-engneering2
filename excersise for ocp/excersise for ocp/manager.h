#pragma once
#include "data.h"
#include "calcbs.h"

class manager : public calcbs {
private:
    int sum = 0;
public:
    int calcs(dataa& d) override;
};
