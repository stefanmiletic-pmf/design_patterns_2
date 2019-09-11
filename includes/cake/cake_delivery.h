#pragma once

#include <vector>
#include <stdlib.h>  

#include "cake/layer.h"
#include "cake/slice.h"
#include "cake/cake.h"

#include "chain_o_r/interface_cook.h"
#include "helpers/response.h"
#include "helpers/request.h"
#include "constants/REQUEST_TYPE.h"
#include "constants/TASTE_TYPE.h"


#include "iterators/interface_cake_iterator.h"

class cake_delivery {
    friend class cake_iterator;
    friend class cake_chocolate_iterator;
    friend class cake_strawberry_vanilla_iterator;
	
protected:
    std::vector<cake*>  m_cakes;

	
public:
    cake_delivery(int amount, double budget, interface_cook *cook_chain);
	
    virtual interface_cake_iterator* getIteratorChocolate();
    virtual interface_cake_iterator* getIterator();
    virtual interface_cake_iterator* getIteratorStrawberryAndVanilla();

    virtual ~cake_delivery();
	
	
    virtual void addCake(cake *client_cake);
	
	
protected:
    TASTE_TYPE getTaste();
};