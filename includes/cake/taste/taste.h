#pragma once

#include <string>

class taste {
public:
    virtual std::string name() const = 0;
    virtual double nutrition() const = 0;
};
