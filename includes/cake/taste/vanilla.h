#pragma once

#include <string>
#include "cake/taste/taste.h"

class vanilla: public taste {
    //friend class taste_factory;
	
	
public:
    virtual std::string name() const { return "Vanila"; }
    virtual double nutrition() const { return 0.3; }
public:
    vanilla() {}
	
};


