#pragma once

#include "iterators/interface_cake_iterator.h"
//#include "cake/cake_delivery.h"
//#include "cake/taste/chocolate.h"

class cake;
class cake_delivery;

class cake_chocolate_iterator : public interface_cake_iterator {
	
	
protected:
    cake_delivery* m_delivery;
    int         m_index;
	
public:
    cake_chocolate_iterator(cake_delivery* client_delivery);
    virtual bool hasNext();
    virtual cake* next();
protected:
    bool isChocolate(cake *client_cake);
    int findNextCake(int begin);
	
};
