#include "intern.h"
int intern::calcs(dataa& d) {
    sum+=d.bs + (d.shour * d.hour) / 2;
    return d.bs+=sum;
}
