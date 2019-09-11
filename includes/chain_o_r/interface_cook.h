#pragma once

#include "helpers/request.h"
#include "helpers/response.h"

class interface_cook {
	
protected:
    double        	  m_price;
    interface_cook    *m_next_cook;
	
public:
    interface_cook(double price);
    virtual ~interface_cook();
    void addCook(interface_cook *cook);
    virtual response solveRequest(const request &res);
	
};