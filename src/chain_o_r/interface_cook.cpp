#pragma once

#include "chain_o_r/interface_cook.h"

interface_cook::interface_cook(double price): m_price(price), m_next_cook(NULL) {}

interface_cook::~interface_cook() {
	if (m_next_cook != NULL) delete m_next_cook;
}

void interface_cook::addCook(interface_cook *cook) {
	if (this->m_next_cook == NULL) {
		this->m_next_cook = cook;
	} else {
		this->m_next_cook->addCook(cook);
	}
}

response interface_cook::solveRequest(const request &res) {
	if (this->m_next_cook == NULL) {
		return response(NOT_SOLVED);
	} else {
		return this->m_next_cook->solveRequest(res);
	}
}