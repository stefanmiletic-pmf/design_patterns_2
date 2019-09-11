#pragma once

#include <ostream>
#include "cake/taste/taste.h"



class layer {
	
public:
    const taste  *m_taste;
    double      m_quantity;
	
public:
    layer(const taste* t, double quantity);
	void consume(double);

    friend std::ostream& operator<<(std::ostream& out, layer& l) {
        out << "[layer: " << l.m_taste->name() << "\n			nutrition: " << l.m_taste->nutrition() << ",\n			quantity: " << l.m_quantity << "]";
        return out;
    }
};