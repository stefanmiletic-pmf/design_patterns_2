#pragma once
#include "constants/TASTE_TYPE.h"


class taste;

class abstract_taste_factory {
	
public:
    virtual const taste* getTaste(TASTE_TYPE type) = 0;
	
};