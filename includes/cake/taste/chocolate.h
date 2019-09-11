#pragma once


#include <string>
#include "cake/taste/taste.h"

class chocolate: public taste {
    //friend class taste_factory;
	
	
public:
    virtual std::string name() const { return "Chocolate"; }
    virtual double nutrition() const { return 0.5; }
public:
    chocolate() {}
	
};
