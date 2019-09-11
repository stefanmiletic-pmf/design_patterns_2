#pragma once

#include "iterators/cake_chocolate_iterator.h"
#include "cake/cake_delivery.h"
#include "cake/taste/chocolate.h"


cake_chocolate_iterator::cake_chocolate_iterator(cake_delivery *client_delivery): m_delivery(client_delivery) {
	m_index = findNextCake(0);
}

 bool cake_chocolate_iterator::hasNext() {
	return (m_index < m_delivery->m_cakes.size());
}
 cake* cake_chocolate_iterator::next() {
	if (!hasNext()) throw "No such element";
	cake *cake_found = m_delivery->m_cakes[m_index];
	m_index = findNextCake(m_index + 1);
	return cake_found;
}

bool cake_chocolate_iterator::isChocolate(cake *client_cake) {
	if (client_cake->m_fill != NULL && client_cake->m_fill->m_taste != NULL && dynamic_cast<const chocolate*>(client_cake->m_fill->m_taste) != NULL) return true;
	if (client_cake->m_crust != NULL && client_cake->m_crust->m_taste != NULL && dynamic_cast<const chocolate*>(client_cake->m_crust->m_taste) != NULL) return true;
	if (client_cake->m_w_c != NULL && client_cake->m_w_c->m_taste != NULL && dynamic_cast<const chocolate*>(client_cake->m_w_c->m_taste) != NULL) return true;
	
	return false;
}


int cake_chocolate_iterator::findNextCake(int begin) {
	int i;
	for (i = begin; i < m_delivery->m_cakes.size(); i++) {
		if (isChocolate(m_delivery->m_cakes[i])) {
			break;
		}
	}
	return i;
}

	
