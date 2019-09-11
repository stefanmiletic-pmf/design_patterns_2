#pragma once

#include "adapter/sequence.h"

class nutrition_meter {
	
public:
    static double calc(sequence* seq) {
        double nutrition = 0.0;
        for (int i = 0; i < seq->length(); i++) {
            pair_vn element = seq->get(i);
            nutrition += element.m_nutrition * element.m_volume;
        }
        return nutrition;
    }
};