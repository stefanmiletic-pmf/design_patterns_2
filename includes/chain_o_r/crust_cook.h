#include "chain_o_r/interface_cook.h"
#include "factories/taste_factory.h"

class crust_cook: public interface_cook {
public:
    crust_cook(double price);
    virtual response solveRequest(const request &client_request);
	
};

