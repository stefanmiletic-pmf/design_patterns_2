#pragma once

#include "adapter/cake_adapter.h"
#include "cake/cake.h"

cake_adapter::cake_adapter(cake *t): m_t(t) {}

pair_vn cake_adapter::get(int idx) {
	if (idx < 0 || idx >= 3) throw "Index out of bounderies";
	
	
	layer *l = NULL;
	switch (idx) {
		case 0: l = m_t->m_crust; break;
		case 1: l = m_t->m_fill; break;
		case 2: l = m_t->m_w_c; break;
	}
	
	
	if (l == NULL) 
		return pair_vn(0.0, 0.0);
	else
		return pair_vn(l->m_quantity, l->m_taste->nutrition());
	
}
int cake_adapter::length() {
	if (m_t->m_crust == NULL) return 0;
	if (m_t->m_fill == NULL) return 1;
	if (m_t->m_w_c == NULL) return 2;
	return 3;
}