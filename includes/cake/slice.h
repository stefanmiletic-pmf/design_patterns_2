#pragma once

#include <ostream>
#include <iomanip>
class slice {

public:
    double      m_quantity;
    const taste  *m_taste_crust, *m_taste_fill, *m_taste_w_c;

public:
    slice(double quantity, const taste* taste_crust, const taste* taste_fill, const taste* taste_w_c):
        m_quantity(quantity), m_taste_crust(taste_crust), m_taste_fill(taste_fill), m_taste_w_c(taste_w_c) {}

    friend std::ostream& operator<<(std::ostream &out, slice &slice) {
		
		if ( slice.m_quantity > 0 ) {
		
			out << "[slice: " << std::fixed << std::setprecision(2) << slice.m_quantity;
			out << ", crust: ";
			if (slice.m_taste_crust == NULL) out << "NaN";
			else out << slice.m_taste_crust->name() << " (" << slice.m_taste_crust->nutrition() << ")";
			out << ", fill: ";
			if (slice.m_taste_fill == NULL) out << "NaN";
			else out << slice.m_taste_fill->name() << " (" << slice.m_taste_fill->nutrition() << ")";
			out << ", whipped cream: ";
			if (slice.m_taste_w_c == NULL) out << "NaN";
			else out << slice.m_taste_w_c->name() << " (" << slice.m_taste_w_c->nutrition() << ")";
			out << "]";
		} else {
			
			out << "[slice: not enough for slice to be taken] \n";
			
		}
        return out;
    }
};