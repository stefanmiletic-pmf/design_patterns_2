#pragma once

#include "constants/REQUEST_RESPONSE.h"
#include "cake/taste/taste.h"



class response {
	
public:
    REQUEST_RESPONSE m_req_response_type;
    double     		 m_price;
    const taste* 	 m_taste;
    double     		 m_quantity;
	
public:
    response(REQUEST_RESPONSE req_response_type, double price = 0.0, const taste* t = NULL, double quantity = 0.0): m_req_response_type(req_response_type), m_price(price), m_taste(t), m_quantity(quantity) {}

};