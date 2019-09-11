#pragma once

#include "iterators/interface_cake_iterator.h"

class cake_delivery;

class cake_iterator: public interface_cake_iterator {
	
	
protected:
    cake_delivery* m_delivery;
    int         m_index;
	
public:
    cake_iterator(cake_delivery *client_delivery);
    virtual bool hasNext();
    virtual cake* next();
	
protected:
    int findNextCake(int begin);
	
};