#pragma once

#include <stdlib.h> 
#include <map>

#include "factories/abstract_taste_factory.h"

class taste;

class taste_factory : public abstract_taste_factory {
	
protected:
    std::map<TASTE_TYPE, const taste*>  m_taste;
	
public:

    static taste_factory& getFactory();
    const taste* getTaste(TASTE_TYPE type);
	
protected:
    taste_factory() {}
    taste_factory(const taste_factory&) {}
    taste_factory& operator=(taste_factory&) { return *this;}

};
