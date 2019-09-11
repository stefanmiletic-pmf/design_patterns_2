#pragma once

#include "cake/cake.h"
#include <algorithm>    // std::max

#include <iostream>

cake::cake(): m_crust(NULL), m_fill(NULL), m_w_c(NULL), m_total_eaten(0.0), m_slice_count(0) {}


cake::~cake() {
	if (m_crust != NULL) delete m_crust;
	if (m_fill != NULL) delete m_fill;
	if (m_w_c != NULL) delete m_w_c;
}


 void cake::setCrust(layer *crust) {
	m_crust = crust;
}
 void cake::setFill(layer *fill) {
	m_fill = fill;
}
 void cake::setWhippedCream(layer *whipped_cream) {
	m_w_c = whipped_cream;
}
 slice cake::getSlice(double slice_size) {
	 
	 if ( slice_size + m_total_eaten > 1 ) {
		 
		 if ( std::abs(slice_size + m_total_eaten - 1) > 0.001 ) {
			 
			std::cout << "Slice " << (m_slice_count+1) << ". cannot be taken\n";
			return slice(0, NULL, NULL, NULL);
			
		 }
		 
		 
	 }
	 
	 std::cout << "Taking " << ++m_slice_count << ". slice \n";
	 std::cout << "Slice size: " << int(slice_size*100) << "% of cake \n";
	 
	double crust_left = m_crust->m_quantity;
	double fill_left = m_fill->m_quantity;
	double w_c_left = m_w_c->m_quantity;
	
	
	double total_left = crust_left + fill_left + w_c_left;
	double quantity = total_left * slice_size;
	
	
	if ( quantity >= 0 ) {
		m_crust->consume(slice_size);
		m_fill->consume(slice_size);
		m_w_c->consume(slice_size);
		
		m_total_eaten += slice_size;
		
	} else 
		return slice(0, NULL, NULL, NULL);
	
	
	return slice(quantity, m_crust->m_taste, m_fill->m_taste, m_w_c->m_taste);
}


