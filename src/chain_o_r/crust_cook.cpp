#include "chain_o_r/crust_cook.h"

crust_cook::crust_cook(double price): interface_cook(price) {}

response crust_cook::solveRequest(const request &client_request) {
	
	
	if (client_request.m_req_type != CRUST ||
			client_request.m_price < 0 ||
			client_request.m_price < this->m_price) {
				
		return interface_cook::solveRequest(client_request);
		
	}
	
	
	double quantity = 130 + (rand() * 0.05);
	const taste* client_taste = taste_factory::getFactory().getTaste(client_request.m_taste);
	
	return response(SOLVED, m_price, client_taste, quantity);
	
	
}

