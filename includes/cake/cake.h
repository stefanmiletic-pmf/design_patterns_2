#pragma once

#include <ostream>
#include <iomanip>
#include "cake/layer.h"
#include "cake/slice.h"

class cake {
	
public:
	
    layer    *m_crust, *m_fill, *m_w_c;
    double  m_total_eaten;
	int m_slice_count;
	
public:
    cake();
    virtual ~cake();
    virtual void setCrust(layer *kora);
    virtual void setFill(layer *fil);
    virtual void setWhippedCream(layer *slag);
    virtual slice getSlice(double);

    friend std::ostream& operator<<(std::ostream& out, cake &c) {
		
		out << "Cake info: \n";
		
		
        out << "[cake: " << std::setprecision(2) << std::fixed << (100.0 * (1-c.m_total_eaten)) << "% cake left";
        out << ",\n  crust: ";
        if (c.m_crust == NULL) out << "NaN";
        else out << *c.m_crust;
        out << ",\n  fill: ";
        if (c.m_fill == NULL) out << "NaN";
        else out << *c.m_fill;
        out << ",\n  whipped cream: ";
        if (c.m_w_c == NULL) out << "NaN";
        else out << *c.m_w_c;
        out << "]";
        return out;
    }
};