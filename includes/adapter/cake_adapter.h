#pragma once

#include "helpers/pair_vn.h"
#include "adapter/sequence.h"
#include "cake/cake.h"

class cake;

class cake_adapter: public sequence  {

protected:
    cake* m_t;
	
	
public:
    cake_adapter(cake* t);
    virtual pair_vn get(int idx);
    virtual int length();
	
};