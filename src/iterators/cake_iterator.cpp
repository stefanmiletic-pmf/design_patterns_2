#include "iterators/cake_iterator.h"


#include "cake/cake_delivery.h"

cake_iterator::cake_iterator(cake_delivery *client_delivery): m_delivery(client_delivery) {
	m_index = findNextCake(0);
}

 bool cake_iterator::hasNext() {
	return (m_index < m_delivery->m_cakes.size());
}
 cake* cake_iterator::next() {
	if (!hasNext()) throw "No such element";
	cake *cake_found = m_delivery->m_cakes[m_index];
	m_index = findNextCake(m_index + 1);
	return cake_found;
}


int cake_iterator::findNextCake(int begin) {
	return begin;
}

	