#pragma once

#include "iterators/cake_strawberry_vanilla_iterator.h"


#include "cake/cake_delivery.h"
#include "cake/taste/strawberry.h"
#include "cake/taste/vanilla.h"


cake_strawberry_vanilla_iterator::cake_strawberry_vanilla_iterator(cake_delivery *client_delivery): m_delivery(client_delivery) {
	m_index = findNextCake(0);
}

bool cake_strawberry_vanilla_iterator::hasNext() {
	return (m_index < m_delivery->m_cakes.size());
}
 cake* cake_strawberry_vanilla_iterator::next() {
	if (!hasNext()) throw "No such element";
	cake *cake_found = m_delivery->m_cakes[m_index];
	m_index = findNextCake(m_index + 1);
	return cake_found;
}


bool cake_strawberry_vanilla_iterator::isVanilla(cake *client_cake) {
	if (client_cake->m_fill != NULL && client_cake->m_fill->m_taste != NULL && dynamic_cast<const vanilla*>(client_cake->m_fill->m_taste) != NULL) return true;
	if (client_cake->m_crust != NULL && client_cake->m_crust->m_taste != NULL && dynamic_cast<const vanilla*>(client_cake->m_crust->m_taste) != NULL) return true;
	if (client_cake->m_w_c != NULL && client_cake->m_w_c->m_taste != NULL && dynamic_cast<const vanilla*>(client_cake->m_w_c->m_taste) != NULL) return true;
	
	
	return false;
}

bool cake_strawberry_vanilla_iterator::isStrawberry(cake *client_cake) {
	if (client_cake->m_fill != NULL && client_cake->m_fill->m_taste != NULL && dynamic_cast<const strawberry*>(client_cake->m_fill->m_taste) != NULL) return true;
	if (client_cake->m_crust != NULL && client_cake->m_crust->m_taste != NULL && dynamic_cast<const strawberry*>(client_cake->m_crust->m_taste) != NULL) return true;
	if (client_cake->m_w_c != NULL && client_cake->m_w_c->m_taste != NULL && dynamic_cast<const strawberry*>(client_cake->m_w_c->m_taste) != NULL) return true;
	
	
	return false;
}



bool cake_strawberry_vanilla_iterator::isVanillaStrawberry(cake *client_cake) {
	return isVanilla(client_cake) && isStrawberry(client_cake);
}

int cake_strawberry_vanilla_iterator::findNextCake(int begin) {
	int i;
	for (i = begin; i < m_delivery->m_cakes.size(); i++) {
		if (isVanillaStrawberry(m_delivery->m_cakes[i])) {
			break;
		}
	}
	return i;
}

	
