#include "chain_o_r/whipped_cream_cook.h"


whipped_cream_cook::whipped_cream_cook(double price): interface_cook(price) {}

response whipped_cream_cook::solveRequest(const request &client_request) {
	
	
	if (client_request.m_req_type != WHIPPED_CREAM ||
			client_request.m_price < 0 ||
			client_request.m_price < this->m_price) {
				
		return interface_cook::solveRequest(client_request);
		
	}
	
	
	double quantity = 120 + (rand() * 0.03);
	const taste* client_taste = taste_factory::getFactory().getTaste(client_request.m_taste);
	
	return response(SOLVED, m_price, client_taste, quantity);
	
	
}


