#include "factories/taste_factory.h"

#include "constants/TASTE_TYPE.h"

//#include "cake/taste/taste.h"
#include "cake/taste/strawberry.h"
#include "cake/taste/chocolate.h"
#include "cake/taste/vanilla.h"

taste_factory& taste_factory::getFactory() {
	static taste_factory factory;
	return factory;
}


const taste* taste_factory::getTaste(TASTE_TYPE type) {
	if (type == NaN) {
		type = (TASTE_TYPE) (rand() % 3 + 1);
	}
	
	if (m_taste.find(type) == m_taste.end()) {
		
		switch (type) {
			case STRAWBERRY_TASTE: 
				m_taste[STRAWBERRY_TASTE] = new strawberry(); 
				break;
			case CHOCOLATE_TASTE:
				m_taste[CHOCOLATE_TASTE] = new chocolate();
				break;
			case VANILLA_TASTE: 
				m_taste[VANILLA_TASTE] = new vanilla(); break;
		default:
			throw "Taste undefined";
		}
		
		
	}
	return m_taste[type];
}
