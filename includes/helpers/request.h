#pragma once

#include "constants/REQUEST_TYPE.h"
#include "constants/TASTE_TYPE.h"

class request {
	
public:
    REQUEST_TYPE  m_req_type;
    TASTE_TYPE    m_taste;
    double     	  m_price;
	
public:
    request(REQUEST_TYPE req_type, double price, TASTE_TYPE t = NaN): m_req_type(req_type), m_price(price), m_taste(t) {}

};
