#pragma once

#include "helpers/pair_vn.h"

class sequence {
public:
    virtual pair_vn get(int idx) = 0;
    virtual int length() = 0;
};
