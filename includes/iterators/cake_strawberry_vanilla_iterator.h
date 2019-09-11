#pragma once

#include "iterators/interface_cake_iterator.h"
//#include "cake/cake_delivery.h"

class cake;
class cake_delivery;

class cake_strawberry_vanilla_iterator : public interface_cake_iterator {
	
	
protected:
    cake_delivery* m_delivery;
    int         m_index;
	
public:
    cake_strawberry_vanilla_iterator(cake_delivery* client_delivery);

    virtual bool hasNext();
    virtual cake* next();
	
protected:

	bool isVanilla(cake* client_cake);
    bool isStrawberry(cake* client_cake);
    bool isVanillaStrawberry(cake* client_cake);
    int findNextCake(int begin);

	
};
