#pragma once

#include "cake/layer.h"



layer::layer(const taste* t, double quantity): m_taste(t), m_quantity(quantity) {}
void layer::consume(double amount) {
	
	m_quantity -= m_quantity * amount;
	
}
