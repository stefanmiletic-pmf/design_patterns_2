#include "chain_o_r/fill_cook.h"


fill_cook::fill_cook(double price): interface_cook(price) {}

response fill_cook::solveRequest(const request &client_request) {
	
	
	if (client_request.m_req_type != FILL ||
			client_request.m_price < 0 ||
			client_request.m_price < this->m_price) {
				
		return interface_cook::solveRequest(client_request);
		
	}
	
	
	double quantity = 90 + (rand() * 0.05);
	const taste* client_taste = taste_factory::getFactory().getTaste(client_request.m_taste);
	
	return response(SOLVED, m_price, client_taste, quantity);
	
	
}

