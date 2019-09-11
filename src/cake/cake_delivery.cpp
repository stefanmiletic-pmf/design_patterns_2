#include <vector>
#include <stdlib.h> 

#include <iostream>
#include "cake/cake_delivery.h"

#include "iterators/cake_chocolate_iterator.h"
#include "iterators/cake_strawberry_vanilla_iterator.h"
#include "iterators/cake_iterator.h"

cake_delivery::cake_delivery(int amount, double budget, interface_cook *cook_chain) {
	amount++;
	while (amount > 1) {
		
		amount--;
		cake *client_cake = new cake();

		
		
		response response_crust = cook_chain->solveRequest(request(CRUST, (budget-=200), getTaste()));
		
		
		if (response_crust.m_req_response_type != SOLVED) {
			delete client_cake;
			break;
		}
		
		client_cake->setCrust(new layer(response_crust.m_taste, response_crust.m_quantity));




		response response_fill = cook_chain->solveRequest(request(FILL, (budget-=200), getTaste()));
		
		
		if (response_fill.m_req_response_type != SOLVED) {
			delete client_cake;
			break;
		}
		client_cake->setFill(new layer(response_fill.m_taste, response_fill.m_quantity));



		response response_w_c = cook_chain->solveRequest(request(WHIPPED_CREAM, (budget-=200), getTaste()));
		if (response_w_c.m_req_response_type != SOLVED) {
			delete client_cake;
			break;
		}
		
		client_cake->setWhippedCream(new layer(response_fill.m_taste, response_fill.m_quantity));
		
		
		
		m_cakes.push_back(client_cake);
	}
}


 interface_cake_iterator* cake_delivery::getIteratorChocolate() {
    return new cake_chocolate_iterator(this);
}
 interface_cake_iterator* cake_delivery::getIterator(){
    return new cake_iterator(this);
}
 interface_cake_iterator* cake_delivery::getIteratorStrawberryAndVanilla() {
    return new cake_strawberry_vanilla_iterator(this);
}


 cake_delivery::~cake_delivery() {
	for (std::vector<cake*>::iterator it = m_cakes.begin(); it != m_cakes.end(); ++it) {
		if (*it != NULL) delete *it;
	}
}


 void cake_delivery::addCake(cake *client_cake) {
	m_cakes.push_back(client_cake);
}


TASTE_TYPE cake_delivery::getTaste() {
	return TASTE_TYPE(rand() % 4);
}